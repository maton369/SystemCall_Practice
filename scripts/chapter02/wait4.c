#include <sys/wait.h>      // wait4()
#include <sys/time.h>      // struct timeval
#include <sys/resource.h>  // struct rusage

#include <unistd.h>        // fork(), write(), _exit()
#include <stdio.h>         // perror(), printf()

int main() {
    int status;                 // 子プロセスの終了ステータス
    pid_t pid;                  // 子プロセスID
    struct rusage usage;        // 子プロセスのリソース使用状況

    // 子プロセスを作成
    if ((pid = fork()) < 0) {
        perror("fork");         // fork 失敗時のエラー出力
        return 1;               // 異常終了
    } else if (pid == 0) {
        // 子プロセス側
        write(1, "child process\n", 14);  // メッセージ出力
        _exit(12);                        // 終了コード12で終了
    }

    // 親プロセス側
    write(1, "parent process\n", 15);    // メッセージ出力

    // 子プロセスの終了を待ち、リソース使用情報を取得
    if ((pid = wait4(pid, &status, 0, &usage)) < 0) {
        perror("wait4");        // wait4 失敗時のエラー出力
        return 1;               // 異常終了
    }

    // 終了ステータスの確認と出力
    if (WIFEXITED(status)) {
        printf("pid = %d exited with status = %d\n",
               pid, WEXITSTATUS(status));
    }

    // 子プロセスが消費したユーザー時間とシステム時間を表示
    printf("user time   = %ld.%06ld sec\n",
           usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("system time = %ld.%06ld sec\n",
           usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);

    return 0;  // 正常終了
}
