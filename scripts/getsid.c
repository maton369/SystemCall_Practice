#include <unistd.h>   // getsid()
#include <stdio.h>    // perror(), printf()

int main()
{
    pid_t sid;

    // 自プロセスのセッションIDを取得
    if ((sid = getsid(0)) < 0) {
        perror("getsid");  // エラーが発生した場合はエラーメッセージを表示
        return 1;
    }

    // セッションIDを出力
    printf("sid = %d\n", sid);

    return 0;  // 正常終了
}
