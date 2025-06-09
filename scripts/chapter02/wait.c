#include <sys/wait.h>   // wait() に必要
#include <unistd.h>     // fork(), write(), _exit() に必要
#include <stdio.h>      // perror(), printf() に必要

int main() {
    int status;         // 子プロセスの終了ステータスなどを受け取る変数
    pid_t pid;          // forkで生成されたプロセスIDを格納する変数

    // 子プロセスの作成
    if ((pid = fork()) < 0) {
        perror("fork");     // fork 失敗時のエラーメッセージ
        return 1;           // 異常終了
    } else if (pid == 0) {
        // 子プロセス側の処理
        write(1, "child process\n", 14);  // メッセージを標準出力
        _exit(12);                        // 終了ステータス12で終了
    }

    // 親プロセス側の処理
    write(1, "parent process\n", 15);    // 親のメッセージを標準出力

    // 子プロセスの終了を待つ
    if ((pid = wait(&status)) < 0) {
        perror("wait");     // wait失敗時のエラーメッセージ
        return 1;           // 異常終了
    }

    // 子プロセスが正常終了したかどうかを判定
    if (WIFEXITED(status)) {
        printf("pid = %d exited with status = %d\n", pid, WEXITSTATUS(status));
    }

    return 0;  // 正常終了
}
