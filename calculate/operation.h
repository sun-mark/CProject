//
// Created by Administrator on 2022/10/25 0025.
//

#ifndef CALCULATE_OPERATION_H
#define CALCULATE_OPERATION_H

typedef struct {
    double left;
    double right;

    double (*operator)(double, double)
} Operation;

double OperationApply(Operation *operation);

double Plus(double left, double right);

double Minus(double left, double right);

double Multiply(double left, double right);

double Divide(double left, double right);

#endif //CALCULATE_OPERATION_H
