//
//errorno 错误码表示
// Created by Administrator on 2022/9/19 0019.
//

#include "head/io_utils.h"
#include <errno.h>
#include <string.h>

int main() {
    for (int i = 0; i < 100; ++i) {
        PRINTLN_INT(i);
        puts(strerror(i));

    }
    return 0;
}