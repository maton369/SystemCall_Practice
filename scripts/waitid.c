#include <sys/wait.h>     // waitid(), siginfo_t など

#ifdef __FreeBSD__
# include <signal.h>      // FreeBSDでは signal.h が必要
#endif

#include <unistd.h>       // fork(), write(), _exit()
#include <stdio.h>        // perror(), printf()

int main() {
    pid_t pid;            // 子プロセスのプロセスID
    siginfo_t info;       // 子プロセスの終了情報を受け取る構造体

    // 子プロセスの作成
    if ((pid = fork()) < 0) {
        perror("fork");   // fork 失敗時のエラーメッセージ
        return 1;         // 異常終了
    } else if (pid == 0) {
        // 子プロセスの処理
        write(1, "child process\n", 14);  // メッセージ出力
        _exit(12);                       // 終了ステータス12で終了
    }

    // 親プロセスの処理
    write(1, "parent process\n", 15);    // メッセージ出力

    // 子プロセスの終了を waitid() で待機
    if (waitid(P_PID, (id_t)pid, &info, WEXITED) < 0) {
        perror("waitid");  // waitid 失敗時のエラーメッセージ
        return 1;
    }

    // 子プロセスが正常終了していれば情報を表示
    if (info.si_code == CLD_EXITED) {
        printf("pid = %d exited with status = %d\n",
               info.si_pid, info.si_status);
    }

    return 0;  // 正常終了
}
