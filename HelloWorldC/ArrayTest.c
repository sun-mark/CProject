//
// Created by Administrator on 2022/7/20 0020.
//
#include <stdio.h>
#include<stdarg.h>

#include "head/io_utils.h"


int twodArray() {
    //
    int array[5][2] = {
            {0, 9},
            [1]= {1, 8},
            {2, 7},
            [3]= {[0]= 3, 6},
            {4, 5},
    };
    return 0;
}

void swpa(int array[], int first, int second) {
    array[first] = array[first] ^ array[second];
    array[second] = array[first] ^ array[second];
    array[first] = array[first]  ^ array[second];
}

void shuffle(const int array[], int length, int shuffle[]) {

}

//vla C99;gcc ok,msvc error
int sumIntArrays(int rows, int columns, const int arrays[][columns]) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum += arrays[i][j];
        }
    }
    return sum;
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
    int array[] = {132, 221};
    swpa(array, 0, 1);
    PRINTLN_INT(array[0]);
    PRINTLN_INT(array[1]);
//    int array[5][2] = {
//            {0, 9},
//            [1]= {1, 8},
//            {2, 7},
//            [3]= {[0]= 3, 6},
//            {4, 5},
//    };
//    PRINTLN_INT(sumIntArrays(5, 2, array));
//    int array[10] = {[1]=11, [0]=12};
//    for (int i = 2; i < 10; ++i) {
//        array[i] = i;
//    }
//    int sum = sumIntArray(array, 15);
//    PRINTLN_INT(sum);
//    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
//        printf("%i\n", array[i]);
//    }
//    PRINTLNF("hello word %d", 1 + 2);
//    PRINTLNF("hello word");
//    PRINTLN_INT(1 + 232);
//    PRINTLNF("%d", 1 + 232);
//    char a = 'd';
//    PRINTL_CHART(a);

    return 0;
}