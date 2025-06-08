#include <unistd.h>   // seteuid, getuid, geteuid
#include <stdio.h>    // perror, printf

// 実ユーザーIDと実効ユーザーIDを表示する関数
static void printuid()
{
    printf("uid = %u euid = %u\n", getuid(), geteuid());
}

int main()
{
    uid_t uid, euid;

    // 実/実効ユーザーIDを保存
    uid = getuid();
    euid = geteuid();

    printuid();  // 初期状態を表示

    // 実効ユーザーIDを実ユーザーIDに一時的に変更（特権を放棄）
    if (seteuid(uid) < 0) {
        perror("seteuid");
        return 1;
    }

    printuid();  // 特権を放棄した状態を表示

    // ＜ここで本来のユーザー権限で処理を行う＞

    // 実効ユーザーIDを元の特権ユーザーIDに戻す
    if (seteuid(euid) < 0) {
        perror("seteuid");
        return 1;
    }

    printuid();  // 特権を戻した状態を表示

    // ＜再び特権ユーザーの権限で処理を行う＞

    return 0;
}
