/**
*字符串 以null结尾
* Created by $bo on 2022/8/23.
*/
#include "head/io_utils.h"
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

int main() {
    char *string = "hello world c";
//    char *string2 = string + "dffd";
    char *string2 = "hello world b";
    PRINTLN_CHART(*string);
    PRINTLN_HEX(&string);
    PRINTLN_HEX(&*string);
    PRINTLNF("%s", string);
    PRINTLNF("%s", string2);
    PRINTLN_INT(strlen(string));
    PRINTLN_INT(strlen(string2));
    PRINTLN_INT(strlen(string));
    //安全版本不会无线数长度
    PRINTLN_INT(strnlen_s(string, 9));//c11 msvc
    PRINTLN_INT(strnlen(string, 100));//gcc
    //字符串比较 -1表示param1不同的字符在前 1反之 0表示相同
    PRINTLN_INT(strcmp(string, string2));
    PRINTLN_INT(strcmp(string2, string));
    PRINTLN_INT(strncmp(string, string2, 12));
    //字符串查询

    return 0;

}