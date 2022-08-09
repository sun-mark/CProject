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
    //0表示不是数字 非0表示是数字
    PRINTLN_INT(isdigit('0'));
    PRINTLN_INT(isdigit(' '));
    PRINTLN_INT(isdigit('a'));
    PRINTLN_INT(isdigit('f'));
    PRINTLN_INT(isdigit('1'));
    PRINTLN_INT(isdigit(','));
    PRINTLN_CHART(tolower('A'));
    return 0;
}
