/**
 * UTC世界调和时间
 * GMT格林威治时间
 * Epoch 新纪元
* Created by bo on 2022/9/14.
*/

#ifndef HELLOWORLDC_TIME_UTILS_H
#define HELLOWORLDC_TIME_UTILS_H

#include <time.h>

#if defined(_WIN32)

#include <sys/timeb.h>

#elif  defined(__unix__)

#include <sys/time.h>

#endif

typedef long long long_time_t;

long_time_t getMillisecond(void) {
#if defined(_WIN32)
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * 1000LL + time_buffer.millitm;
#elif defined(__unix__)
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    return 1;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L
    struct timespec timespec_value;
    timespec_get(&timespec_value, TIME_UTC);
    return
#else
time_t current_time=time(NULL);
return current_time * 1000LL;

#endif

}

#endif //HELLOWORLDC_TIME_UTILS_H
