/**
 * 共享资源线程安全问题
 * 并发三大问题
 * 1 原子性
 * 2 可见性
 * 3 重排序
 * volatile 目的是禁止编译器优化读写操作 禁止重排序 不会保证访问的原子性
 * MSVC 有强制刷新缓存的语义 可以保证可见性
 * Created by bo on 2022/10/2.
*/

#include "head/tinycthread.h"
#include "head/io_utils.h"

int count = 0;

int Counter(void *arg) {
    PRINTLNF("Counter.");
    for (int i = 0; i < 100000000; ++i) {
        //非原子操作 count先做加法操作+1 在复制值给count
        count++;
    }
    return 0;
}

int main() {
    thrd_t t1;
    thrd_create(&t1, Counter, NULL);
    thrd_t t2;
    thrd_create(&t2, Counter, NULL);
    thrd_join(t1, NULL);
    thrd_join(t2, NULL);
//    thrd_detach(t1);
//    thrd_detach(t2);
    PRINTLN_INT(count);
    return 0;
}