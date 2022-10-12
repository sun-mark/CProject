//
//conan 测试
// Created by Administrator on 2022/10/12 0012.
//

#include <curl/curl.h>
#include "head/io_utils.h"

int main() {
    FILE *file = feof(stdout);
    CURL *curl = curl_easy_init();
    struct curl_slist *headers = CURL_FORMADD_NULL;
    headers = curl_slist_append(headers,
                                "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, "www.baidu.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    CURLcode response = curl_easy_perform(curl);
    PRINTLN_INT(response);
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    fflush(file);
    fclose(file);
    return 0;
}