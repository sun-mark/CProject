/**
 * 复制文件
 * Created by bo on 2022/9/24.
*/

#include "head/io_utils.h"
#include <stdio.h>
#include <locale.h>
#include "head/time_utils.h"

#define COPY_SUCCESS 0;
#define COPY_ILLEGAL_ARGUMEUTS -1;
#define COPY_SRC_OPEN_ERROR -2;
#define COPY_SRC_READ_ERROR -3;
#define COPY_DEST_OPEN_ERROR -4;
#define COPY_DEST_WRITE_ERROR -5;
#define COPY_UNKNOW_ERROR -100;

/**
 * 单字符读写
 * @param src
 * @param dest
 * @return
 */
int CopyFile(char const *src, char const *dest) {
    if (!src || !dest) {
        return COPY_ILLEGAL_ARGUMEUTS;
    }
    FILE *src_file = fopen(src, "rb");
    if (!src_file) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result = COPY_UNKNOW_ERROR;
    while (1) {
        int src_char = fgetc(src_file);
        if (src_char == EOF) {
            if (ferror(src_file)) {
                result = COPY_SRC_READ_ERROR;
            } else if (feof(src_file)) {
                result = COPY_SUCCESS;
            } else {
                result COPY_UNKNOW_ERROR;
            }
            break;
        }
        if (fputc(src_char, dest_file) == EOF) {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }

    fclose(src_file);
    fclose(dest_file);

    return result;
}

/**
 * 加入缓存buffer 读写io效率更高
 * 只对文本文件有效
 * @param src
 * @param dest
 * @return
 */
int CopyFile2(char const *src, char const *dest) {
    if (!src || !dest) {
        return COPY_ILLEGAL_ARGUMEUTS;
    }
    FILE *src_file = fopen(src, "r");
    if (!src_file) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dest_file = fopen(dest, "w");
    if (!dest_file) {
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result;
    char buffer[BUFSIZ];
    while (1) {
        char *string = fgets(buffer, 1024, src_file);
        if (!string) {
            if (ferror(src_file)) {
                result = COPY_SRC_READ_ERROR;
            } else if (feof(src_file)) {
                result = COPY_SUCCESS;
            } else {
                result COPY_UNKNOW_ERROR;
            }
            break;
        }
        if (fputs(buffer, dest_file) == EOF) {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
    }
    fclose(src_file);
    fclose(dest_file);
    return result;
}

/**
 * 二进制读写
 * 加入缓存buffer 读写io效率更高
 * @param src
 * @param dest
 * @return
 */
int CopyFile3(char const *src, char const *dest) {
    if (!src || !dest) {
        return COPY_ILLEGAL_ARGUMEUTS;
    }
    FILE *src_file = fopen(src, "rb");
    if (!src_file) {
        return COPY_SRC_OPEN_ERROR;
    }
    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        fclose(src_file);
        return COPY_DEST_OPEN_ERROR;
    }
    int result;
    char buffer[BUFSIZ];
    while (1) {
        size_t fread_size = fread(buffer, sizeof(buffer[0]), BUFSIZ, src_file);
        if (fwrite(buffer, sizeof(buffer[0]), fread_size, dest_file) < fread_size) {
            result = COPY_DEST_WRITE_ERROR;
            break;
        }
        if (fread_size < BUFSIZ) {
            if (ferror(src_file)) {
                result = COPY_SRC_READ_ERROR;
            } else if (feof(src_file)) {
                result = COPY_SUCCESS;
            } else {
                result COPY_UNKNOW_ERROR;
            }
            break;
        }
    }
    fclose(src_file);
    fclose(dest_file);
    return result;
}

int main() {
    setlocale(LC_ALL, "zh_CN.utf-8");
    //复制文件
//    PRINTLN_INT(CopyFile("../copy-test/source/file_test.txt", "../copy-test/dest/file_test.txt"));
    long_time_t start_time = getMillisecond();
    for (int i = 0; i < 20; ++i) {
//        PRINTLN_INT(CopyFile("../copy-test/source/file_test.txt", "../copy-test/dest/file_test.txt"));
//        PRINTLN_INT(CopyFile2("../copy-test/source/file_test.txt", "../copy-test/dest/file_test.txt"));
        PRINTLN_INT(CopyFile3("../copy-test/source/file_test.txt", "../copy-test/dest/file_test.txt"));
    }
//    PRINTLN_INT(CopyFile("../copy-test/source/1663991686366.png", "../copy-test/dest/1663991686366.png"));
    long_time_t end_time = getMillisecond();
    PRINTLN_LONG_LONG(end_time - start_time);
    return 0;
}
