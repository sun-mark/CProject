/**
 * 格式化时间
 * Created by bo on 2022/9/22.
*/

#include "head/time_utils.h"
#include "head/io_utils.h"

int main() {
    time_t current_time = time(&current_time);
    struct tm *calendar_time = localtime(&current_time);
    char *string = asctime(calendar_time);
    //共享内存 可能有并发问题
    puts(string);
    puts(ctime(&current_time));
    char current_time_s[20];
    size_t size = strftime(current_time_s, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
    puts(current_time_s);
    PRINTLN_LONG(size);
    return 0;
}