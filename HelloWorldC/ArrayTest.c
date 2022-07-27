//
// Created by Administrator on 2022/7/20 0020.
//
#include <stdio.h>
#include<stdarg.h>

#include "head/io_utils.h"

int twodArray() {
    int array[5][2] = {
            {0, 9},
            [1]= {1, 8},
            {2, 7},
            [3]= {[0]= 3, 6},
            {4, 5},
    };
    return 0;
}

//vla C99;gcc ok,msvc error
int sumIntArrays(int rows, int columns, const int arrays[][columns]) {

}

int sumIntArray(const int array[], int length) {
    if (length <= 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
//    可以设置数组类型的内容
//    array[length - 1] = 213213;
    return sum;
}

int main() {
    int array[10] = {[1]=11, [0]=12};
    for (int i = 2; i < 10; ++i) {
        array[i] = i;
    }
    int sum = sumIntArray(array, 15);
    PRINTLN_INT(sum);
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        printf("%i\n", array[i]);
    }
//    PRINTLNF("hello word %d", 1 + 2);
//    PRINTLNF("hello word");
//    PRINTLN_INT(1 + 232);
//    PRINTLNF("%d", 1 + 232);
//    char a = 'd';
//    PRINTL_CHART(a);

    return 0;
}