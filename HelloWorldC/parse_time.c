/**
 * 解析时间
 * Created by bo on 2022/9/22.
*/

#include "head/time_utils.h"
#include "head/io_utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    clock_t startClock = clock();
    time_t current_time = time(NULL);
    struct tm *calendar_time = localtime(&current_time);
    PRINTLN_INT(calendar_time->tm_sec);
    PRINTLN_INT(calendar_time->tm_min);
    PRINTLN_INT(calendar_time->tm_hour);
    PRINTLN_INT(calendar_time->tm_mday);
    PRINTLN_INT(calendar_time->tm_mon);
    PRINTLN_INT(calendar_time->tm_year);
    char time_format[20];
    strftime(time_format, 20, "%Y-%m-%d %H:%M:%S", calendar_time);
    puts(time_format);
    char *string = strptime(time_format, "%Y-%m-%d %H:%M:%s", calendar_time);
    puts(time_format);
    puts(string);
    //windows parse time
    char time_format_source[25];
    strcpy(time_format_source, time_format);
    strcat(time_format_source, ".");
    char millisecond[3];
    sprintf(millisecond, "%lld", getMillisecond() / 10000000000);
    strcat(time_format_source, millisecond);
    puts(time_format_source);
    int millisecond_int;
    struct tm parsed_time;
    int sscanf1 = sscanf(time_format_source, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
                         &parsed_time.tm_year,
                         &parsed_time.tm_mon,
                         &parsed_time.tm_mday,
                         &parsed_time.tm_hour,
                         &parsed_time.tm_min,
                         &parsed_time.tm_sec,
                         &millisecond_int
    );
    parsed_time.tm_year -= 1900;
    parsed_time.tm_mon -= 1;
    PRINTLN_INT(sscanf1);
    //尽量使时间符合规范
    mktime(calendar_time);
    PRINTLNF(".............");
    PRINTLN_INT(parsed_time.tm_sec);
    PRINTLN_INT(parsed_time.tm_min);
    PRINTLN_INT(parsed_time.tm_hour);
    PRINTLN_INT(parsed_time.tm_mday);
    PRINTLN_INT(parsed_time.tm_mon);
    PRINTLN_INT(parsed_time.tm_year);
    PRINTLN_DOUBLE(((double) (clock() - startClock)) / CLOCKS_PER_SEC);
    return 0;
}