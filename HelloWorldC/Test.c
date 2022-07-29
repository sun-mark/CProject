#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/**
 * 猜数字游戏
 * @return
 */
int main() {

    //随机数
    srand(time(NULL));
    int ranndom = rand();
    puts("猜个数");
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
    printf("%s\n", "输入任意字符退出");
    scanf("%s");
    exit(0);//等待终端输入任意字符
    return 0;
}
