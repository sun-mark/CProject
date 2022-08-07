//
// 判断字符串类型
//
#include "head/io_utils.h"
#include <ctype.h>

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
    PRINTLN_INT(isdigit('9'));
    return 0;
}
