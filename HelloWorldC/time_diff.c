/**
 * 计算时间差
* Created by bo on 2022/9/14.
*/

#include "head/io_utils.h"
#include "head/time_utils.h"

#define PI 3.1415926

void DoHardWork() {
    double sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i * i / PI;
    }
    PRINTLN_DOUBLE(sum);
}

int main() {

    time_t start_time = time(NULL);
    DoHardWork();
    time_t end_time = time(NULL);
    PRINTLN_INT(end_time - start_time);
    
    return 0;
}
