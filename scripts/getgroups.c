#include <unistd.h>     // getgroups()
#include <limits.h>     // NGROUPS_MAX
#include <stdio.h>      // perror(), printf(), putchar()
#include <sys/types.h>  // gid_t

int main()
{
    int i;
    int groups;
    gid_t list[NGROUPS_MAX];  // 補助グループIDの格納用配列

    // 補助グループIDの取得
    if ((groups = getgroups(NGROUPS_MAX, list)) < 0) {
        perror("getgroups");
        return 1;
    }

    // 各補助グループIDの表示
    for (i = 0; i < groups; i++) {
        printf("%u ", list[i]);
    }

    putchar('\n');  // 最後に改行を出力
    return 0;
}
