#include <unistd.h>   // getpid(), getppid() に必要なヘッダ
#include <stdio.h>    // printf() に必要なヘッダ

int main() {
    pid_t pid, ppid;  // 自分と親のプロセスIDを格納する変数

    pid = getpid();   // 自分のプロセスIDを取得
    ppid = getppid(); // 親プロセスのプロセスIDを取得

    // 自分と親のPIDを表示
    printf("pid = %d, ppid = %d\n", pid, ppid);

    return 0;         // 正常終了
}
