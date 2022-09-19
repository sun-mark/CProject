#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/**
 * 猜数字游戏
 * @return
 */

int main() {
    srand(time(NULL));
    int ranndom = rand();
    puts("输入数字");
    while (true) {
        int user_input;
        scanf("%d", &user_input);
        if (user_input == ranndom) {
            puts("猜对了");
            break;
        } else if (user_input > ranndom) {
            puts("大了");
        } else {
            puts("小了");
        }
    }
    printf("%s\n", "恭喜");
    scanf("%s");
    exit(0);//退出
    return 0;
}
