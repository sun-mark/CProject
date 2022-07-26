//
// Created by Administrator on 2022/7/20 0020.
//
#include <stdio.h>
#include<stdarg.h>

#include "head/io_utils.h"

int main() {
    int array[10] = {[1]=11, [0]=12};
    for (int i = 2; i < 10; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        printf("%i\n", array[i]);
    }
    PRINTLNF("hello word %d", 1 + 2);
    PRINTLNF("hello word");
    return 0;
}