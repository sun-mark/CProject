#include <stdio.h>

int main() {
    int i;
    int sum = 1;
    for (i = 0; i < 10; ++i) {
        printf("Hello, World!\n");
        sum = sum + i;
    }
    return sum;
}
