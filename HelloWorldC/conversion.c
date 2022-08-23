//
//字符类型的转换
//strtol功能多atoi简单MinGW不支持atof 的进制
//
#include "head/io_utils.h"
#include <stdlib.h>

int main() {
//    PRINTLN_INT(atoi("21321"));
//    PRINTLN_INT(atoi("-123213"));
//    PRINTLN_INT(atoi(" 2312dsfds"));
//    PRINTLN_INT(atoi("0x10"));
//
//    PRINTLN_DOUBLE(atof("12.34"));
//    PRINTLN_DOUBLE(atof("-12e34"));
//    PRINTLN_DOUBLE(atof("     1.23fdsf"));
//    PRINTLN_DOUBLE(atof("0x10"));//MinGW 不支持
//    PRINTLN_DOUBLE(atof("0x10p3.9"));//MinGW 不支持

    char const *const kInput = "1 20000000000000000000000000000000000 3 -4 5adf bye 1232 23213";
    char const *start = kInput;
    char *end;
    PRINTLNF("%s", kInput);
    while (1) {
        //把0存进去表示没有错误 先清空下错误
        errno = 0;
        const long i = strtol(start, &end, 10);
        if (start == end) {
            break;
        }
        PRINTLN_LONG(i);
        if (errno == ERANGE) {
            //20000000000000000000000000000000000 range 溢出
            perror("error");
        }
        start = end;
    }
    PRINTLNF("left: %s", end);
    return 0;
}