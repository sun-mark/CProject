//
//其他常见文件操作
// Created by Administrator on 2022/9/28 0028.
//

#include <stdio.h>
#include "head/io_utils.h"
#include <corecrt_wstdio.h>
#include <sys/stat.h>

//看文件
long GetFileSize(char const *filename) {

}


int main() {
//    int result_1 = remove("E:\\CProject\\HelloWorldC\\copy-test\\dest\\file_test.txt");
//    PRINTLN_INT(result_1);
//    //不存在的就给一个-1
//    int result_2 = remove("E:\\CProject\\HelloWorldC\\copy-test\\dest\\file_t1est.txt");
//    PRINTLN_INT(result_2);
    //不存在给一个-1
//    PRINTLN_INT(rename("E:\\CProject\\HelloWorldC\\copy-test\\dest\\file_test.txt",
//                       "E:\\CProject\\HelloWorldC\\copy-test\\dest\\file_t1est.txt"));
    FILE *tmp_file = tmpfile();
    puts(tmpnam(tmp_file));
    fclose(tmp_file);
}