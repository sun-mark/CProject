/**
* Created by bo on 2022/9/12.
*/
#include <string.h>
#include "head/io_utils.h"

int main() {
    char *string = "hello world c";
    //从前面找
    char *result = strchr(string, 'l');
    //从后面找
    char *result_reverse = strrchr(string, 'l');
    puts(result);
    puts(result_reverse);
    char *string2 = "c,1972;c++,1983:java,1995;rust,2010;kotlin,2011";
    char *break_set = ",;";
    int count = 0;
    char *p = string2;
    do {
        p = strpbrk(p, break_set);
        if (p) {
            puts(p);
            p++;
            count++;
        }
    } while (p);
    //查找字符串
    char *str = strstr(string, "ello");
    puts(str);
    PRINTLN_INT(str - string);
    return 0;
}
