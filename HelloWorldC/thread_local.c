/**
 * thread local
 * 类似于线程副本只在此线程内操作 最后的结果可以通过join返回 or callback返回
 * Created by bo on 2022/10/3.
*/
#include "head/io_utils.h"
#include "head/tinycthread.h"

_Thread_local int count = 0;

int Counter() {
    PRINTLNF("counter[%#x]", thrd_current());
    for (int i = 0; i < 10000000; ++i) {
        count++;
    }
    return count;
}

int main() {
    thrd_t t1, t2;
    int i1, i2;
    thrd_create(&t1, Counter, NULL);
    thrd_create(&t2, Counter, NULL);
    thrd_join(t1, &i1);
    thrd_join(t2, &i2);
    PRINTLN_INT(i1 + i2);
    return 0;
}