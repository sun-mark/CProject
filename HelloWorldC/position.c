/**
 * 文件操作方式
 * Created by bo on 2022/9/26.
*/

#include <stdio.h>
#include "head/io_utils.h"

int main() {
    FILE *file_open = fopen("../CMakeLists.txt", "rb");
    long file_tell = ftell(file_open);
    PRINTLN_LONG(file_tell);
    char buffer[128];
    fread(buffer, 1, 128, file_open);
    PRINTLN_LONG(ftell(file_open));
    fseek(file_open, 10, SEEK_CUR);
    PRINTLN_LONG(ftell(file_open));
    fseek(file_open, -10, SEEK_END);
    PRINTLN_LONG(ftell(file_open));
    fseek(file_open, 10, SEEK_SET);
    PRINTLN_LONG(ftell(file_open));
    fclose(file_open);
    return 0;
}