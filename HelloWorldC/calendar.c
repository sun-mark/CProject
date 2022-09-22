/**
 * 获取日历
* Created by bo on 2022/9/14.
*/
#include "head/time_utils.h"
#include "head/io_utils.h"

int main() {

    time_t local_time = time(NULL);
    PRINTLN_LONG(local_time);
    struct tm *calendar_time = localtime(&local_time);
    PRINTLN_INT(calendar_time->tm_year);
    PRINTLN_INT(calendar_time->tm_sec);
    PRINTLN_INT(calendar_time->tm_min);
    PRINTLN_INT(calendar_time->tm_hour);
    PRINTLN_INT(calendar_time->tm_mday);
    PRINTLN_INT(calendar_time->tm_mon);
    PRINTLN_INT(calendar_time->tm_year);
    PRINTLN_INT(calendar_time->tm_wday);
    PRINTLN_INT(calendar_time->tm_yday);
    PRINTLN_INT(calendar_time->tm_isdst);
    //mktime 会调整尽量返回的time_t符合规则
    time_t mktime1 = mktime(calendar_time);
    PRINTLN_LONG(mktime1);
    //GMT 0时区时间
    struct tm *pTm = gmtime((const time_t *) &local_time);
    PRINTLN_INT(pTm->tm_year);
    PRINTLN_INT(pTm->tm_sec);
    PRINTLN_INT(pTm->tm_min);
    PRINTLN_INT(pTm->tm_hour);
    PRINTLN_INT(pTm->tm_mday);
    PRINTLN_INT(pTm->tm_mon);
    PRINTLN_INT(pTm->tm_year);
    PRINTLN_INT(pTm->tm_wday);
    PRINTLN_INT(pTm->tm_yday);
    PRINTLN_INT(pTm->tm_isdst);
    return 0;
}