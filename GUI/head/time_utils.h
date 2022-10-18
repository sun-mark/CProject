/**
 * UTC世界调和时间
 * GMT格林威治时间
 * Epoch 新纪元
* Created by bo on 2022/9/14.
*/
#define _XOPEN_SOURCE

#ifndef HELLOWORLDC_TIME_UTILS_H
#define HELLOWORLDC_TIME_UTILS_H

#include <time.h>

#if defined(_WIN32)

#include <sys/timeb.h>

#elif  defined(__unix__)

#include <sys/time.h>

#endif

//描述毫秒
typedef long long long_time_t;

const int TIME_INT_1000 = 1000;
const int TIME_INT_60 = 60;

long_time_t getMillisecond(void) {
#if defined(_WIN32)
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * TIME_INT_1000 + time_buffer.millitm;
    //MAC OS也有这个timeval
#elif defined(__unix__) || defined(__APPLE__)
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    return time_value.tv_sec * TIME_INT_1000 + time_value.tv_usec / TIME_INT_1000;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L
    struct timespec timespec_value;
    //WIN32没有这个函数
    timespec_get(&timespec_value, TIME_UTC);
    return timespec_value.tv_sec * TIME_INT_1000 + timespec_value.tv_nsec / TIME_INT_1000 / TIME_INT_1000;
#else
    //仅仅为了程序执行结果并不精准
    time_t current_time=time(NULL);
    return current_time * 1000LL;

#endif

}

#endif //HELLOWORLDC_TIME_UTILS_H
