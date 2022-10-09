/**
 * 加锁
 * Created by bo on 2022/10/3.
*/

#include "head/io_utils.h"
#include "head/tinycthread.h"

int count = 0;
mtx_t mtx;

void Counter() {
    PRINTLNF("counter[%#x]", thrd_current());
    mtx_lock(&mtx);
    for (int i = 0; i < 1000000; ++i) {
        count++;
    }
    mtx_unlock(&mtx);
}

int main() {
    //创建锁
    /* Mutex types mtx_plain mtx_timed mtx_recursive */
    mtx_init(&mtx, mtx_plain);
    thrd_t t1, t2;
    thrd_create(&t1, Counter, NULL);
    thrd_create(&t2, Counter, NULL);
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);
    PRINTLN_INT(count);
    //销毁锁
    mtx_destroy(&mtx);
    //尝试加锁
//    mtx_trylock(&mtx);
    //加锁 有一个等待的时间
//    mtx_timedlock(&mtx, &(struct timespec) {.tv_sec=0, .tv_nsec=100000000});
    return 0;
}