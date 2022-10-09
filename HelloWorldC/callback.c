/**
 * 回调
 * Created by bo on 2022/10/4.
*/
#include "head/io_utils.h"
#include "head/tinycthread.h"
#include <stdlib.h>

#define DOWNLOAD_TASKS 5
typedef struct Context {
    mtx_t mutex;
    int download_left;
} Context;
typedef struct DownloadRequest {
    Context *context;
    char const *url;
    char const *filename;
    int progress;
    int interval;

    void (*callback)(struct DownloadRequest *);
} DownloadRequest;

int DownloadFile(DownloadRequest *request) {
    PRINTLNF("\rDownloading file from: %s into %s ...", request->url, request->filename);
    for (int i = 0; i <= 100; ++i) {
        request->progress = i;
        thrd_sleep(&(struct timespec) {.tv_sec=0, .tv_nsec=request->interval * 1000000}, NULL);
    }
    request->callback(request);
    return 0;
}

void DownloadCallback(DownloadRequest *downloadRequest) {
    mtx_lock(&downloadRequest->context->mutex);
    downloadRequest->context->download_left--;
    PRINTLNF("\rDownload file from:%s into %s successfully,left:%d",
             downloadRequest->url,
             downloadRequest->filename,
             downloadRequest->context->download_left);
    mtx_unlock(&downloadRequest->context->mutex);
}


int main() {
    char *urls[] = {
            "https://www.baidu.com/download/file1",
            "https://www.baidu.com/download/file2",
            "https://www.baidu.com/download/file3",
            "https://www.baidu.com/download/file4",
            "https://www.baidu.com/download/file5",
            "https://www.baidu.com/download/file6",
            "https://www.baidu.com/download/file7",
            "https://www.baidu.com/download/file8",
            "https://www.baidu.com/download/file9",
            "https://www.baidu.com/download/file10",
    };
    char *filenames[] = {
            "D:/download1",
            "D:/download2",
            "D:/download3",
            "D:/download4",
            "D:/download5",
            "D:/download6",
            "D:/download7",
            "D:/download8",
            "D:/download9",
            "D:/download10",
    };

    DownloadRequest requests[DOWNLOAD_TASKS];
    Context context = {.download_left=DOWNLOAD_TASKS};
    mtx_init(&context.mutex, mtx_plain);
    for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
        requests[i] = (DownloadRequest) {
                .context=&context,
                .url=urls[i],
                .filename=filenames[i],
                .progress=0,
                .interval=(i + 1) * 10,
                .callback=DownloadCallback
        };
        thrd_t t;
        thrd_create(&t, DownloadFile, &requests[i]);
        thrd_detach(t);
    }
    while (1) {
        mtx_lock(&context.mutex);
        int download_left = context.download_left;
        mtx_unlock(&context.mutex);
        if (download_left == 0) {
            break;
        }

        printf("\r");
        for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
            printf("%s -- %3d%% ", requests[i].filename, requests[i].progress);
        }
//        printf("\r");
        fflush(stdout);
        thrd_sleep(&(struct timespec) {.tv_sec=0, .tv_nsec= 10000000}, NULL);
    }
    mtx_destroy(&context.mutex);
    return 0;
}