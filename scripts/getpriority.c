#include <sys/time.h>          // struct timeval（未使用だが getpriority で推奨される）
#include <sys/resource.h>      // getpriority(), PRIO_PROCESS などの定義
#include <errno.h>             // errno グローバル変数
#include <stdio.h>             // perror(), printf()

int main() {
    int pri;

    errno = 0;                         // errno を明示的に 0 に初期化
    pri = getpriority(PRIO_PROCESS, 0);  // カレントプロセス (pid 0) の優先度を取得

    if (errno != 0) {                  // errno が非 0 の場合はエラー発生
        perror("getpriority");        // エラー内容を出力
        return 1;                     // 異常終了
    }

    printf("%d\n", pri);              // 優先度（nice 値）を出力
    return 0;                         // 正常終了
}
