/**
*内存操作
* Created by bo on 2022/9/13.
*/
#include "head/io_utils.h"
#include <stdlib.h>
#include <string.h>

int main() {
    //memchr()
    //strchr()

    //memcmp()
    //strcmp()
    char *mem = malloc(10);
//    printf_s("分配内存前:\n");
//    PRINTLN_ARRAY(mem, 10);
    memset(mem, 0, 10);
//    printf_s("分配内存后:\n");
//    PRINTLN_ARRAY(mem, 10);
    memcpy(mem, "abc", 2);
    puts(mem);
    PRINTLN_ARRAY(mem, 10);
    return 0;
}
