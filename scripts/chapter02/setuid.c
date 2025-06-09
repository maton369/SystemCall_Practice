#include <unistd.h>   // setuid, getuid, geteuid のために必要
#include <stdio.h>    // perror, printf のために必要

// 実ユーザーIDと実効ユーザーIDを表示する関数
static void printuid() {
    printf("uid = %u, euid = %u\n", getuid(), geteuid());
}

int main() {
    uid_t uid, euid;

    // 初期状態の UID/EUID を保存
    uid = getuid();
    euid = geteuid();

    printuid();  // 現在の UID/EUID を表示

    // 実効ユーザーIDを、実ユーザーIDと同じ値にする（権限を落とす）
    if (setuid(uid) < 0) {
        perror("setuid (to real UID)");
        return 1;
    }
    printuid();  // 権限を落とした状態を確認

    // 本来の実ユーザーIDでの処理をここに記述

    // 実効ユーザーIDを元に戻す（特権権限を再取得）
    if (setuid(euid) < 0) {
        perror("setuid (restore EUID)");
        return 1;
    }
    printuid();  // 再び特権に戻った状態を表示

    // 特権に戻った状態での処理をここに記述

    return 0;
}
