//
// Created by Administrator on 2022/10/25 0025.
//

#include "calculator.h"
#include "operation.h"
#include "console_ui.h"
#include <stdlib.h>
#include <string.h>

static void ClearBuffer(CalcContext *context) {
    context->input_buffer[0] = 0;
    context->input_buffer_position = 0;
}

static void ClearAll(CalcContext *context) {
    ClearBuffer(context);
    context->result = 0;
    memset(&context->previous_operation, 0, sizeof(Operation));
    memset(&context->current_operation, 0, sizeof(Operation));
}


static void FormatInput(CalcContext *context) {
    if (context->input_buffer_position == 0) {
        context->input_buffer[0] = '0';
        context->input_buffer[1] = 0;
        context->input_buffer_position = 1;
    } else if (context->input_buffer_position == 1) {
        if (context->input_buffer[0] == '.') {
            context->input_buffer[0] = '0';
            context->input_buffer[1] = '.';
            context->input_buffer[2] = 0;
            context->input_buffer_position = 2;
        }
    } else if (context->input_buffer_position > 1) {
        char *p = context->input_buffer;
        if (p[0] == '0' && p[1] != ',') {
            p[0] = p[1];
            p[1] = 0;
            context->input_buffer_position = 1;
        } else if (p[context->input_buffer_position - 1] == '.') {
            for (int i = 0; i < context->input_buffer_position - 1; ++i) {
                if (p[i] == '.') {
                    context->input_buffer_position--;
                    p[context->input_buffer_position] = 0;
                    break;
                }
            }
        }
    }
}

static void DisplayInput(CalcContext *context) {
    FormatInput(context);
    context->display_text(context->input_buffer);
}

static void ApplyInput(CalcContext *context, double *operand) {
    if (context->input_buffer_position > 0) {
        *operand = atof(context->input_buffer);
        ClearBuffer(context);
    } else {
        *operand = context->result;
    }
}

static void ApplyInputToleft(CalcContext *context) {
    ApplyInput(context, &context->current_operation.left);
}

static void ApplyInputToRight(CalcContext *context) {
    ApplyInput(context, &context->current_operation.right);
}

int HandleInput(CalcContext *context, char input_value) {
    switch (input_value) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            if (context->input_buffer_position < MAX_CHAR) {
                context->input_buffer[context->input_buffer_position++] = input_value;
                context->input_buffer[context->input_buffer_position] = '\0';

            }
            DisplayInput(context);
            break;
        case '+':
            context->current_operation.operator = Plus;
            ApplyInputToleft(context);
            break;
        case '-':
            context->current_operation.operator = Minus;
            ApplyInputToleft(context);
            break;
        case '*':
            context->current_operation.operator = Multiply;
            ApplyInputToleft(context);
            break;
        case '/':
            context->current_operation.operator = Divide;
            ApplyInputToleft(context);
            break;
        case '=':
            break;
        case '%':
            break;
        case 'S':
            break;
        case 'c':
            ClearAll(context);
            DisplayInput(context);
            break;
    }
    if (context->display_text) {
        char c[2] = {[0]=input_value};
        context->display_text(c);
    }

    return 1;
}


CalcContext *CreateCalcContext() {
    CalcContext *calc_context = malloc(sizeof(CalcContext));
    ClearAll(calc_context);
    calc_context->display_text = NULL;
    return calc_context;
}

void DestroyCalcContext(CalcContext **p_context) {
    free(*p_context);
    *p_context = NULL;
}

