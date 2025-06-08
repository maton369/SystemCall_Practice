#include <unistd.h>  // chroot(), chdir(), sleep()
#include <stdio.h>   // perror()

int main()
{
    // ① /mnt を新しいルートディレクトリに設定
    if (chroot("/mnt") < 0) {
        perror("chroot");  // エラーがあれば表示
        return 1;
    }

    // ② chroot 後の "/" に移動（これは /mnt に相当）
    if (chdir("/") < 0) {
        perror("chdir");  // エラーがあれば表示
        return 1;
    }

    // ③ 60秒間スリープ（chroot 環境内での動作確認用）
    sleep(60);

    // ④ 正常終了
    return 0;
}
