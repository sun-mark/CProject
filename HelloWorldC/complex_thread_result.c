/**
 * 线程复杂返回结果的处理
 * 方法一：通过参数来解决
 * 方法二：通过回调来解决
 * Created by bo on 2022/10/4.
*/

#include "head/io_utils.h"
#include "head/tinycthread.h"

typedef struct {
    int a;
    char *b;
} ComplexResult;
typedef struct {
    int arg;
    ComplexResult result;
} ComplexArg;

int ComplexReturnValue(ComplexArg *arg) {
    PRINTLN_INT(arg->arg);
    arg->result.a = 3;
    arg->result.b = "hello";
    return 1;
}

int main() {
    ComplexArg complexArg = {.arg=35};
    thrd_t thrd;
    thrd_create(&thrd, ComplexReturnValue, &complexArg);
    int result;
    thrd_join(thrd, &result);
    PRINTLN_INT(complexArg.result.a);
    PRINTLN_INT(result);
    puts(complexArg.result.b);
    return 0;
}