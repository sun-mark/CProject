/**
 * 获取系统时间
* Created by bo on 2022/9/14.
*/
#include "head/time_utils.h"
#include "head/io_utils.h"

int main() {
    time_t current_time;
    time(&current_time);
    PRINTLN_LONG(current_time);
    return 0;
}
