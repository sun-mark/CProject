/**
 * 重定向输入输出流
 * Created by bo on 2022/9/25.
*/

#include <stdio.h>

#if defined(__APPLE__) || defined(__liunx__)
#   include <unistd.h>
#elif defined(_WIN32)

#   include <io.h>

#endif

void RedirectStdout(char const *file_name) {
    static int save_stdout_no = -1;
    if (file_name) {
        if (save_stdout_no == -1) {
            save_stdout_no = dup(fileno(stdout));
        }
        fflush(stdout);
        freopen(file_name, "a", stdout);
    } else {
        if (save_stdout_no != -1) {
            fflush(stdout);
            dup2(save_stdout_no, fileno(stdout));
            close(save_stdout_no);
            save_stdout_no = -1;
        }
    }
}

int main() {

//    freopen("output.log", "a", stdout);
//    puts("text text text");
//    fclose(stdout);

    puts("1");
    RedirectStdout("output.log");
    puts("2");
    puts("3");
    RedirectStdout(NULL);
    puts("4");
    puts("5");
    RedirectStdout("output.log");
    puts("end");
    //python x.py -> output.log 2>&1
    return 0;
}
