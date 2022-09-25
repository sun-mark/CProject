/**
 * Created by bo on 2022/9/24.
*/
#include "head/io_utils.h"
#include <string.h>

char buf[BUFSIZ];

void ReadFile() {
    FILE *file = fopen("../CMakeLists.txt", "r");
    if (file) {
        puts("open file success");
        setvbuf(file, buf, _IOLBF, 1024);
        int next_char = getc(file);
        while (next_char != EOF) {
            putchar(next_char);
            next_char = getc(file);
        }
        fclose(file);
    } else {
        puts("open file fail");
        perror("error:");
    }
}

void Echo() {
    char buffer[2];
    while (1) {
//        if (!gets_s(buffer, 2)) {
//            break;
//        }
        if (!fgets(buffer, 2, stdin)) {
            break;
        }
//        puts(buffer);
        printf("%s", buffer);

    }
}

int main() {
//    ReadFile();
    Echo();
//    stdio 读取字符
//    getchar()
//     指定的流中读取一个字符
//    getc() fgetc()
    // EOF 表示文件结束


    return 0;
}