//
// Created by 蛟龙002 on 2022/8/4.
//

/**
 * 联合体公用一块内存
 * @return
 */
int main() {
    typedef union B {
        int i;
    } B;
    typedef struct A {
        char c;
        short s;
        int i;
        double d;
        B b;
    } A;
    A a = {
            .c='b',
            .b={.i=2}
    };
}