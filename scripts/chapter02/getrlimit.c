#include <sys/time.h>         // getrlimit に必要
#include <sys/resource.h>     // getrlimit に必要
#include <stdio.h>            // perror(), printf()
#include <stdint.h>           // uintmax_t のために必要

int main()
{
    struct rlimit rlim;  // リミット値格納用構造体

    // RLIMIT_CPU（プロセスの最大CPU時間制限）の取得
    if (getrlimit(RLIMIT_CPU, &rlim) < 0) {
        perror("getrlimit");
        return 1;
    }

    // ソフトリミットの表示
    if (rlim.rlim_cur == RLIM_INFINITY) {
        printf("rlim_cur = unlimited\n");
    } else {
        printf("rlim_cur = %ju\n", (uintmax_t)rlim.rlim_cur);
    }

    // ハードリミットの表示
    if (rlim.rlim_max == RLIM_INFINITY) {
        printf("rlim_max = unlimited\n");
    } else {
        printf("rlim_max = %ju\n", (uintmax_t)rlim.rlim_max);
    }

    return 0;
}
