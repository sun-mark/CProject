//
// Created by Administrator on 2022/10/25 0025.
//

#include "calculator.h"
#include "operation.h"
#include "console_ui.h"
#include <stdlib.h>
#include <string.h>

int HandleInput(CalcContext *context, char input_value) {
    if (context->display_text) {
        char c[2] = {[0]=input_value};
        context->display_text(c);
    }

    return 1;
}

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

