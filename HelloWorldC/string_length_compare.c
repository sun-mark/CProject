/**
* Created by $bo on 2022/8/23.
*/
#include "head/io_utils.h"
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>

int main() {
    char *string = "hello world c";
    PRINTLN_CHART(*string);
    PRINTLN_HEX(&string);
    PRINTLN_HEX(&*string);
    PRINTLNF("%s", string);
    PRINTLN_INT(strlen(string));
    PRINTLN_INT(strnlen_s(string, 100));//c11 msvc
    PRINTLN_INT(strnlen(string, 100));//gcc
    return 0;

}