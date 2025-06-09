#include <unistd.h>   // setgroups(), execl()
#include <grp.h>      // gid_t
#include <stdio.h>    // perror(), printf()
#include <stdlib.h>   // exit()

int main()
{
    gid_t list[3];  // 補助グループID設定用配列

    // 補助グループIDを設定
    list[0] = 3000;
    list[1] = 3001;
    list[2] = 3002;

    // 補助グループを設定
    if (setgroups(3, list) < 0) {
        perror("setgroups");
        return 1;
    }

    // getgroups を起動して確認
    if (execl("./getgroups", "./getgroups", NULL) < 0) {
        perror("execl");
        return 1;
    }

    return 0; // 到達しないはず
}
