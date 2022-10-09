/**
 * 原子类型
 * atomic 一般是通过cpu原子指令实现也有通过加锁实现
 * Created by bo on 2022/10/3.
*/
#include "head/io_utils.h"
#include "head/tinycthread.h"
#include <stdatomic.h>


atomic_int count = 0;

int Counter(void *arg) {
    PRINTLNF("Counter.");
    for (int i = 0; i < 100000; ++i) {
        count++;
    }
    return 0;
}

int main() {
    thrd_t t1, t2;
    thrd_create(&t1, Counter, NULL);
    thrd_create(&t2, Counter, NULL);
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);
    PRINTLN_INT(count);
    //非0表示true是不是加锁实现的
    PRINTLN_INT(atomic_is_lock_free(&count));

    return 0;
}