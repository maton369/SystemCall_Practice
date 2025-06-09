#include <sys/time.h>        // setrlimit のために必要なヘッダファイル
#include <sys/resource.h>    // setrlimit のために必要なヘッダファイル
#include <unistd.h>          // chdir のために必要なヘッダファイル
#include <stdio.h>           // perror() のために必要なヘッダファイル

int main()
{
    struct rlimit rlim; // リミット値を指定するための rlimit 構造体

    rlim.rlim_cur = 1;  // ソフトリミット：1 秒
    rlim.rlim_max = 2;  // ハードリミット：2 秒

    // CPU 時間のリミットを設定
    if (setrlimit(RLIMIT_CPU, &rlim) < 0) {
        perror("setrlimit");
        return 1;
    }

    // CPU時間を消費させるために無限ループ（chdir を繰り返す）
    for (;;) {
        chdir(".");
    }

    return 0; // 到達しない（1〜2秒で SIGXCPU により強制終了）
}
