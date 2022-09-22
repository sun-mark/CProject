/**
* 时间获取
* Created by bo on 2022/9/14.
*/
#include "head/io_utils.h"
#include "head/time_utils.h"
#include <time.h>
#include <sys/timeb.h>

#ifdef __unix__

#include <sys/time.h>

#endif

int main() {
    //epoch时间
    time_t;
    //进程消耗处理器的时间 更多的是描述程序运行的时间
    clock_t;
    //获取日期
    struct tm;
    //获取纳秒 C11 MSVC
    struct timespec;
    //获取毫秒
    struct timeb;

#ifdef __unit__
    //获取微妙
    struct timeval;
#endif
    return 0;
}