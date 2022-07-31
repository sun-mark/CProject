//
// Created by Administrator on 2022/7/7 0007.
//
#include <stdio.h>


void move(int n, char from, char to) {
    printf("%c->%c\n", from, to);
}

void handeta(int i, char source, char target, char temporary) {
    if (i == 0) {
        return;
    } else if (i == 1) {
        move(i, source, target);
    } else {
        handeta(i - 1, source, temporary, target);
        handeta(1, source, target, temporary);
        handeta(i - 1, temporary, target, source);

    }
}

int main() {
    handeta(16, 'A', 'C', 'B');

    return 0;
}