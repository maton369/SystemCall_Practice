#include <unistd.h>   // setsid(), fork(), sleep()
#include <stdio.h>    // perror(), printf()
#include <stdlib.h>   // exit()

int main()
{
    pid_t pid;

    // 子プロセスの作成
    if ((pid = fork()) < 0) {
        perror("fork");  // フォーク失敗
        return 1;
    } else if (pid > 0) {
        // 親プロセスは終了
        _exit(0);
    }

    // setsidにより新しいセッションの作成
    if (setsid() < 0) {
        perror("setsid");
        return 1;
    }

    // 現在のPID, セッションID, プロセスグループIDを表示
    printf("PID  = %d\n", getpid());
    printf("SID  = %d\n", getsid(0));   // セッションID
    printf("PGID = %d\n", getpgid(0));  // プロセスグループID
    fflush(stdout);

    // 新しいセッション内での処理（デバッグ用にスリープ）
    sleep(1);

    return 0;
}
