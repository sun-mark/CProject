//
// Created by 蛟龙002 on 2022/7/31.
//
#include "head/io_utils.h"

typedef struct Person2 {
    char name;
    int age;

} person2;
struct Person1 {
    char name;
    int age;
    char id;
    struct Person2 *person2;
//    struct {
//        int age1;
//    } extra;
} person1;

int main() {
    person2 person3 = {'b', 23};
    PRINTLN_INT(person3.age);
    struct Person1 person2 = {.name='a', .age= 18, .id='1', .person2= &person3};
//    PRINTLN_INT(person1.extra.age1);
    PRINTLN_INT(person2.person2->age);
    PRINTLN_INT(person2.person2->name);
    PRINTLN_INT(person1.age);
    person1.age = 1;
    PRINTLN_INT(person1.age);
    PRINTLN_INT(person2.age);
    return 0;
}