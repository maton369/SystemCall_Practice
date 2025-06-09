#include <sys/time.h>        // setpriority のため
#include <sys/resource.h>    // setpriority のため
#include <unistd.h>          // execl
#include <stdio.h>           // perror

int main() {
    // 自分の nice 値を 19 に下げる
    if (setpriority(PRIO_PROCESS, 0, 19) < 0) {
        perror("setpriority");
        return 1;
    }

    // 優先度を確認するプログラムに置き換える
    execl("./getpriority", "./getpriority", NULL);

    // execl に失敗した場合
    perror("execl");
    return 1;
}
