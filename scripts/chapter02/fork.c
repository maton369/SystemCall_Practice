#include <unistd.h>  // fork(), write(), _exit() に必要
#include <stdio.h>   // perror() に必要

int main() {
    pid_t pid;  // プロセスID格納用の変数

    // fork() で新しいプロセスを作成
    if ((pid = fork()) < 0) {
        perror("fork");      // fork 失敗時にエラーメッセージを表示
        return 1;            // 異常終了
    } else if (pid == 0) {
        // 子プロセス側の処理
        write(1, "child process\n", 14);  // 標準出力にメッセージを出力
        _exit(0);                        // 子プロセス正常終了（exit より安全）
    }

    // 親プロセス側の処理
    write(1, "parent process\n", 15);    // 標準出力にメッセージを出力
    return 0;                            // 親プロセス正常終了
}
