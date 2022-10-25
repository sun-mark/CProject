//
// Created by Administrator on 2022/10/25 0025.
//

#include "operation.h"
#include "console_ui.h"

double OperationApply(Operation *operation) {
    if (operation->operator) {
        return operation->operator(operation->left, operation->right);
    } else {
        return 0.0;
    }
}

double Plus(double left, double right) {
    return left + right;
}

double Minus(double left, double right) {
    return left - right;
}

double Multiply(double left, double right) {
    return left * right;

}

double Divide(double left, double right) {
    //都是用户输入的不用判断精度问题
    if (right == 0.0) {
        return 0.0;
    } else {
        return left / right;
    }
}

int main(int argc, char *argv[]) {
    RunConsoleUi(argc, argv);
    return 0;
}