/**
 * 线程的基本用法
 * Created by bo on 2022/10/1.
*/
#include "head/io_utils.h"
#include "head/tinycthread.h"
//#include <unistd.h>

int SayHello(char *name) {
    PRINTLNF("Run in new thread[%#x]:Hello,%s", thrd_current(), name);
    return 10;
}

int main() {
    thrd_t new_thread;
    int result = thrd_create(&new_thread, SayHello, "c lang");
    if (result == thrd_success) {
        PRINTLNF("Run in main thread[%#x],creat new_thread[%#x]", thrd_current(), new_thread);
    } else {
        PRINTLNF("Run in main thread[%#x],failed to creat new_thread", thrd_current());
    }
//    sleep(3);
//    thrd_sleep(&(struct timespec) {.tv_sec=0, .tv_nsec=100000000}, NULL);
//  让出cpu资源重新所有线程一起抢占
//    thrd_yield();
//    thrd_join(new_thread, &result);
//    PRINTLNF("Run in main Thread[%#x] ,result from thread[%#x]:%d", thrd_current(), new_thread, result);
    thrd_detach(new_thread);
}