#include <unistd.h>   // setreuid, getuid, geteuid
#include <stdio.h>    // printf, perror

// 実ユーザーIDと実効ユーザーIDを表示する関数
static void printuid() {
    printf("uid = %u, euid = %u\n", getuid(), geteuid());
}

int main() {
    uid_t uid, euid;

    uid = getuid();       // 実ユーザーIDの取得
    euid = geteuid();     // 実効ユーザーIDの取得

    printuid();           // 初期状態のUIDを表示

    // UIDとEUIDを交換
    if (setreuid(euid, uid) < 0) {
        perror("setreuid (swap)");
        return 1;
    }

    printuid();           // 交換後のUIDを表示

    // 本来のUID/EUIDに戻す
    if (setreuid(uid, euid) < 0) {
        perror("setreuid (restore)");
        return 1;
    }

    printuid();           // 戻した後のUIDを表示

    return 0;
}
