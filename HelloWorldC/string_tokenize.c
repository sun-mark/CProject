/**
 * 字符串拆分
* Created by bo on 2022/9/12.
*/
#include <string.h>
#include <stdlib.h>
#include "head/io_utils.h"

#pragma pack(4)
typedef struct {
    int year;
    char *name;
} Language;

int main() {
    char string[] = "c,1972;c++,1983;java,1995;rust,2010;kotlin,2011";
    const char *language_delimit = ";";
    const char *filed_delimit = ",";
    int init_size = 3;
    int current_capacity = 0;
    //分配内存
    Language *languages = malloc(sizeof(Language) * init_size);
    if (!languages) {
        //内存分配失败
        abort();
    }
    char *strtok_result = strtok(string, filed_delimit);
    while (strtok_result) {
        Language language;
        language.name = strtok_result;
        strtok_result = strtok(NULL, language_delimit);
        language.year = atoi(strtok_result);
        if (current_capacity + 1 >= init_size) {
            //重新分配内存
            init_size *= 2;
            languages = realloc(languages, sizeof(Language) * init_size);
            if (!languages) {
                //分配失败
                abort();
            }
        }
        languages[current_capacity++] = language;
        strtok_result = strtok(NULL, filed_delimit);
    }
    PRINTLNF("解析个数：%d", current_capacity);
    PRINTLNF("分配内存的大小：%d", init_size * sizeof(Language));
    PRINTLNF("Language大小：%d", sizeof(Language));
    for (int i = 0; i < current_capacity; ++i) {
        PRINTLNF("Language[name=%s, year=%d]", languages[i].name, languages[i].year);
    }

    return 0;
}
