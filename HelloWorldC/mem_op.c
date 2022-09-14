/**
*内存操作
* Created by bo on 2022/9/13.
*/
#include "head/io_utils.h"
#include <stdlib.h>
#include <string.h>


void *my_memcpy(void *restrict dest, const void *restrict src, size_t size) {
    if (!dest || !src) {
        return NULL;
    }
    char *char_dest = (char *) dest;
    const char *char_src = (char *) src;
    while (size--) {
        *char_dest++ = *char_src++;
    }
    return dest;
}

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
    //copy
    memcpy(mem, "a", 2);
    puts(mem);
    PRINTLN_ARRAY(mem, 10);
    free(mem);
    char src[] = "HelloWorld";
    char *dest = malloc(11);
    memcpy(dest, src, 11);
    puts(dest);
    //内存重叠保证安全
    memmove(dest + 3, dest + 1, 4);
    puts(dest);
    free(dest);
    void *hello = malloc(10);
    const void *test = "abcd";
    my_memcpy(hello, test, 10);
    puts(hello);
    return 0;
}

