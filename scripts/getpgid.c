#include <unistd.h>   // getpgid
#include <stdio.h>    // perror, printf

int main()
{
    pid_t pgid;  // プロセスグループID受け取り用変数

    // getpgid(0): 自プロセスのプロセスグループIDを取得
    if ((pgid = getpgid(0)) < 0) {
        perror("getpgid");  // 取得失敗時にエラーメッセージ表示
        return 1;           // 異常終了
    }

    // 成功時：プロセスグループIDを表示
    printf("pgid = %d\n", pgid);
    return 0;  // 正常終了
}
