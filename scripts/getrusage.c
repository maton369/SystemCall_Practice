#include <sys/time.h>       // getrusage() に必要
#include <sys/resource.h>   // getrusage() に必要
#include <unistd.h>         // chdir()
#include <stdio.h>          // perror(), printf()

int main()
{
    struct rusage usage;  // プロセスのリソース使用情報を受け取る構造体
    int i;
    long long j = 1;      // 掛け算のオーバーフロー回避用に long long を使用

    // 無意味な処理でリソースを使用させる
    for (i = 1; i <= 1000000; i++) {
        chdir(".");       // カレントディレクトリへの chdir 呼び出し
        j *= i;           // ダミーの掛け算
        if (j > 1000000000) j = 1;  // オーバーフロー対策
    }

    // プロセス自身のリソース使用状況を取得
    if (getrusage(RUSAGE_SELF, &usage) < 0) {
        perror("getrusage");
        return 1;
    }

    // 使用時間（ユーザー・システム）を表示
    printf("user time   = %ld.%06ld seconds\n", 
        usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("system time = %ld.%06ld seconds\n", 
        usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);

    return 0;
}
