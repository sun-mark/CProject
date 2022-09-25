/**
 * 序列化 反序列化
 * Created by bo on 2022/9/24.
*/
#include <stdio.h>
#include "head/io_utils.h"

typedef struct SerilalizationTest {
    int a;
    char b;
    long c;

} serilalizationTest;

#define OK 1;
#define FAIL 2;

int SaveSetting(serilalizationTest *ser, char *setting_file) {
    FILE *save_file = fopen(setting_file, "wb");
    if (save_file) {
        fwrite(ser, sizeof(serilalizationTest), 1, save_file);
        fclose(save_file);
        return OK;
    } else {
        perror("Failed to save settings.");
        return FAIL;
    }
}

int LoadSetting(serilalizationTest *ser, char *setting_file) {
    FILE *load_file = fopen(setting_file, "rb");
    if (load_file) {
        fread(ser, sizeof(serilalizationTest), 1, load_file);
        fclose(load_file);
        return OK;
    } else {
        perror("failed open file");
        return FAIL;
    }
}

int main() {
    serilalizationTest serilalization_test = {2, 'd', 300000000L};
    PRINTLN_INT(SaveSetting(&serilalization_test, "save_file.bin"));
    serilalizationTest serilalization_test2 = {.a=2};
    PRINTLN_INT(LoadSetting(&serilalization_test2, "save_file.bin"));
    PRINTLN_INT(serilalization_test2.a);
    PRINTLN_CHART(serilalization_test2.b);
    PRINTLN_INT(serilalization_test2.c);
    return 0;
}