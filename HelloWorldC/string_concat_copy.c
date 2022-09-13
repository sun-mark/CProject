/**
* 字符串的连接和复制
* Created by bo on 2022/9/13.
*/

#include <string.h>
#include "head/io_utils.h"

int main() {
    char src[] = "hell word c";
    char dest[20] = "C said:";
    //直接连接到后面
    strcat(dest, src);
    //字符copy到固定的地址
    strcpy(dest + strlen(dest), src);
    puts(dest);
    return 0;
}
