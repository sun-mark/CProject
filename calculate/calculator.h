//
// Created by Administrator on 2022/10/25 0025.
//

#ifndef CALCULATE_CALCULATOR_H
#define CALCULATE_CALCULATOR_H

#define MAX_CHAR 13

#include "operation.h"

typedef struct {
    char input_buffer[MAX_CHAR + 1];
    int input_buffer_position;
    double result;
    Operation previous_operation;
    Operation current_operation;

    void (*display_text)(char *);
} CalcContext;

int HandleInput(CalcContext *context, char input_value);

CalcContext *CreateCalcContext();

void DestroyCalcContext(CalcContext **p_context);

#endif //CALCULATE_CALCULATOR_H
