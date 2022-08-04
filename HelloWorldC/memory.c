//
// Created by Administrator on 2022/8/4 0004.
//
/**
 * 内存分析
 * @return
 */
#include "head/io_utils.h"

//#pragma pack(2)
struct Person {
//    short a;
    char a;
    char b;
//    int age;
    __attribute((aligned (2))) int age;
    double e;
    short s;
//    char *name;
//    short c;
};
typedef struct Person Person;

int main() {
    char c = 'c';
    Person person = {};
    PRINTLN_LONG_LONG(sizeof(person));

}
