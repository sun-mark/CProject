/**
 * Created by bo on 2022/9/24.
*/
#include "head/io_utils.h"

int main() {
    FILE *file = fopen("../CMakeLists.txt", "r");
    if (file) {
        puts("open file successfully");
        //buf 存活时间应该更久 1设置全局变量 2malloc开辟内存 可以在关闭内存前在设置一块内存给缓冲流
        char buf[BUFSIZ];
        //没办法设置缓冲区大小
        setbuf(file, buf);
        //设置更加灵活
        setvbuf(file, buf, _IOLBF, 1024);
        int ferror_code = ferror(file);
        PRINTLN_INT(ferror_code);
        fflush(stdout);
        int feof_code = feof(file);
        PRINTLN_INT(feof_code);
        fclose(file);
    } else {
        puts("open file fail ");
        perror("fopen");
    }
    return 0;
}