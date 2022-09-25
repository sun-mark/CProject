/**
 * 统计字符数
 * Created by bo on 2022/9/25.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "head/io_utils.h"
#include <wchar.h>

#define ERROR_ILLEGAL_FILENAME -1
#define ERROR_CANNOT_OPEN_FILE -2
#define ERROR_READ_FILE 3
#define ERROR_UNSUPPORTED_CHARSET -99

#define CHARSET_UTF8  0
#define CHARSET_GBK 1

int CountCharactersInFile(char const *file_name, int charset) {
    if (!file_name) {
        return ERROR_ILLEGAL_FILENAME;
    }
    FILE *file;
    switch (charset) {
        case CHARSET_GBK:
#ifdef _WIN32
            setlocale(LC_ALL, "chs");
#else
            setlocale(LC_ALL, "zh_CN.gbk");
#endif
            file = fopen(file_name, "r");
            break;
        case CHARSET_UTF8:
            setlocale(LC_ALL, "zh_CN.utf-8");
#ifdef _WIN32
            file = fopen(file_name, "r,ccs=utf-8");
#else
            file = fopen(file_name, "r");
#endif
            break;
        default:
            return ERROR_UNSUPPORTED_CHARSET;
    }
    if (!file) {
        return ERROR_CANNOT_OPEN_FILE;
    }
    wchar_t buffer[BUFSIZ];
    int count = 0;
    while (fgetws(buffer, BUFSIZ, file)) {
        count += wcslen(buffer);
    }
    if (ferror(file)) {
        fclose(file);
        perror("error");
        return ERROR_READ_FILE;
    }
    fclose(file);
    return count;
}

int main() {
    PRINTLN_INT(CountCharactersInFile("../CMakeLists.txt", 0));
    return 0;
}