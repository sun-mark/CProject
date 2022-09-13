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
    free(mem);
    PRINTLN_ARRAY(mem, 10);
    char src[] = "HelloWorld";
    char *dest = malloc(11);
    memcpy(dest, src, 11);
    puts(dest);
    //内存重叠保证安全
    memmove(dest + 3, dest + 1, 4);
    puts(dest);
    free(dest);
    return 0;
}
