//
// Created by Administrator on 2022/7/29 0029.
//
#include "head/io_utils.h"
#include <stdlib.h>

/**
 * 指针
 * @return
 */

void add(int *a, int b) {
    *a = *a + b;

}

void add2(int a, double b) {
    a = a + b;

}

int (*f6)(int, double);

int (*f5)[](int, double);

int main() {
    f5[1] = &add2;
    PRINTLN_INT(f5[1](1, 4.9));

    //函数指针
    int a = 1;
    int c = 2132;
    PRINTLN_HEX(&main);
    PRINTLN_HEX(&add);
    int (*func)(int *a, int b) =&add;
    int (*func2)(int a, int b) =&add2;
//    PRINTLN_HEX(*func);
    PRINTLN_INT(func2(a, c));
    PRINTLN_INT(func(&a, c));
    PRINTLN_INT(func(&a, c));
    PRINTLN_INT(a);
    //动态分配内粗
//    int *i = malloc(0);
//    free(i);
//    calloc(10, sizeof(int));
//    realloc(i, 2 * 10);
//    int a = 1;
//    int b = 3;
//    add(&a, b);
//    add2(a, b);
//    PRINTLN_INT(a);
//    int array[6] = {1};
//    int *pa = array;
//    *pa++ = 10;
//    *++pa = 11;
//    int array[] = {111, 222, 333, 444, 555};
//    int *p = array;
//    PRINTLN_INT(array[2]);
//    PRINTLN_INT(*(array + 2));
//    PRINTLN_INT(p[2]);
//    PRINTLN_HEX(p);
//    PRINTLN_HEX(array);
//    PRINTLN_HEX(&array);
//    int *p = NULL;
//    *p = 3; //error
//    p = (int *) 0X3000;
//    PRINTLN_HEX(p);
//    int *a = 100;//compile warning
//    int *a = (int *) 100;//hard code
//    PRINTLN_INT(a);
//    PRINTLN_INT(*a);
//    int a = 1;
//    int b = 2;
//    PRINTLN_INT(a);
//    PRINTLN_HEX(&a);
//    PRINTLN_HEX(sizeof (&a));
//    PRINTLN_HEX(sizeof (a));
//    int *const p = &a;
//    p = &b;//error
//    *p = 2;
//    PRINTLN_INT(a);
//    int const *pp = &a;
//    pp = &b;
//    *pp = b //error
    //    int **pp = &p;
//    PRINTLN_INT(**pp);//1
//    PRINTLN_HEX(*pp);//&p=&a
//    PRINTLN_HEX(p);//&p=&a
//    PRINTLN_HEX(&a);//&p=&a
//    PRINTLN_HEX(&p);//&p=&a
//    PRINTLN_HEX(pp);//1
//    **pp = 2;
//    PRINTLN_INT(**pp);
//    PRINTLN_INT(*p);
//    PRINTLN_INT(a);
//   PRINTLN_INT(*p);
//    PRINTLN_HEX(p);
//    PRINTLN_HEX(&p);

}
