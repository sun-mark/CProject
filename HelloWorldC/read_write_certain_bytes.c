/**
 * 读写指定字节
 * Created by bo on 2022/9/25.
*/
#include <stdio.h>
#include "head/io_utils.h"

void Echo() {
#define BUFFER_SIZE 4
    int buffer[BUFFER_SIZE];
    while (1) {
        size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdin);
//        PRINTLN_ARRAY(buffer, BUFFER_SIZE);
        if (bytes_read < BUFFER_SIZE) {
            if (feof(stdin)) {
                puts("EOF");
                fwrite(buffer, sizeof(buffer[0]), bytes_read, stdout);
            } else if (ferror(stdin)) {
                perror("Error read from stdin");
            }
            break;
        }
        fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdout);
    }
}

int main() {
    Echo();
    return 0;
}

