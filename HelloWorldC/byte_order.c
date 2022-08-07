//
//端序判断
// Created by 蛟龙002 on 2022/8/7.
//
#include "head/io_utils.h"

int IsBigEndian() {
    union {

        char c[2];
        short s;
    } value = {.s = 0x100};
    return value.c[0] == 1;
}

int main() {
    PRINTLN_INT(IsBigEndian());
}
