//
//conan 测试
// Created by Administrator on 2022/10/12 0012.
//

#include <curl/curl.h>
#include "head/io_utils.h"

int main() {
    CURL *curl = curl_easy_init();
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers,
                                "User-Agent:Awesome-Octocat-App");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
    CURLcode response = curl_easy_perform(curl);
    PRINTLN_INT(response);
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    fflush(stdout);
    fclose(stdout);
    return 0;
}