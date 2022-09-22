/**
 * 获取系统时间
* Created by bo on 2022/9/14.
*/
#include "head/time_utils.h"
#include "head/io_utils.h"

int main() {
    time_t current_time;
    //传地址免去了复制的问题 能增加一点效率
    time(&current_time);
    PRINTLNF("现在的时间戳:%ld", current_time);
    time_t time1 = time(NULL);
    PRINTLNF("现在的时间戳:%ld", time1);
    return 0;
}
