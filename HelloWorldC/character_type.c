//
// 判断字符串类型
//
#include "head/io_utils.h"
#include <ctype.h>
#include <time.h>

/**
 * 判断是否未数字
 * 但是每次要判断
 * <ctype.h>提供的有API 利用查表法快速判断
 * @param c
 * @return
 */
int IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    time_t t1 = time(NULL);
    int num = 0;
    for (int i = 0; i < 1000000000; ++i) {
//        PRINTLN_INT(isdigit('9'));
        num = isdigit('9');
    }
    time_t t2 = time(NULL);
    PRINTLN_INT(t2 - t1);
//    PRINTLN_INT(IsDigit('9'));
    return 0;
}
