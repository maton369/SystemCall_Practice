#include <sys/wait.h>   // waitpid() に必要なヘッダファイル
#include <unistd.h>     // fork(), write(), _exit() に必要なヘッダファイル
#include <stdio.h>      // perror(), printf() に必要なヘッダファイル

int main() {
    int status;         // 終了ステータス等を受け取る変数
    pid_t pid;          // fork() により作成されたプロセスID

    // 子プロセスを作成
    if ((pid = fork()) < 0) {
        perror("fork");     // fork に失敗した場合
        return 1;           // 異常終了
    } else if (pid == 0) {
        // 子プロセスの処理
        write(1, "child process\n", 14);  // メッセージ出力（標準出力）
        _exit(12);                        // 終了コード12で即終了
    }

    // 親プロセスの処理
    write(1, "parent process\n", 15);    // メッセージ出力

    // 子プロセスの終了を待機
    if ((pid = waitpid(pid, &status, 0)) < 0) {
        perror("waitpid");   // waitpid に失敗した場合
        return 1;
    }

    // 子プロセスが正常に終了していた場合
    if (WIFEXITED(status)) {
        printf("pid = %d exited with status = %d\n", pid, WEXITSTATUS(status));
    }

    return 0;  // 正常終了
}
