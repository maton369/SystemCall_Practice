#include <unistd.h>  // getuid(), geteuid(), getgid(), getegid()
#include <stdio.h>   // printf()

int main() {
    uid_t uid, euid;   // 実ユーザーIDと実効ユーザーID
    gid_t gid, egid;   // 実グループIDと実効グループID

    uid = getuid();      // 実ユーザーIDを取得
    euid = geteuid();    // 実効ユーザーIDを取得
    gid = getgid();      // 実グループIDを取得
    egid = getegid();    // 実効グループIDを取得

    // 取得した各IDを表示
    printf("uid = %u, euid = %u, gid = %u, egid = %u\n", uid, euid, gid, egid);

    return 0;  // 正常終了
}
