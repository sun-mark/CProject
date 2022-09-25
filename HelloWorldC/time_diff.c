/**
 * 计算时间差
* Created by bo on 2022/9/14.
*/

#include "head/io_utils.h"
#include "head/time_utils.h"
#include<unistd.h>

#define PI 3.1415926

void DoHardWork() {
    double sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i * i / PI;
    }
    PRINTLN_DOUBLE(sum);
}

int main() {
    clock_t start_time, end_time;
    start_time = clock();
//    clock_t start_time = clock();
//    long_time_t start_time = getMillisecond();
    sleep(3);
    end_time = clock();
//    time_t start_time = time(NULL);
//    DoHardWork();
//    time_t end_time = time(NULL);
//    long_time_t end_time = getMillisecond();
//    clock_t end_time = clock();
//    double diff = difftime(start_time, end_time);
//    PRINTLN_LONG(diff);
//    PRINTLN_DOUBLE((double) (end_time - start_time) * 1.0 / CLOCKS_PER_SEC);
//    PRINTLN_LONG_LONG(end_time - start_time);
    printf("%f\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}
