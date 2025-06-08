#include <unistd.h>   // chroot(), chdir(), sleep(), getpid()
#include <stdio.h>    // perror(), printf()

int main()
{
    // ① /mnt を新しいルートディレクトリに設定
    if (chroot("/mnt") < 0) {
        perror("chroot");
        return 1;
    }

    // ② chroot 後の "/" に移動
    if (chdir("/") < 0) {
        perror("chdir");
        return 1;
    }

    // ③ 現在のプロセスIDを表示
    printf("chroot 成功 (PID: %d)。10秒間スリープ中...\n", getpid());
    fflush(stdout);

    // ④ 60秒スリープ
    sleep(10);

    // ⑤ 終了
    return 0;
}
