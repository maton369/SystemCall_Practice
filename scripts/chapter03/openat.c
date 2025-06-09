#include <sys/stat.h>   // openat 用のパーミッション定義
#include <fcntl.h>      // openat, O_CREAT などの定義
#include <unistd.h>     // write, close に必要
#include <stdio.h>      // perror

int main()
{
    int dirfd; // 相対パスの起点ディレクトリのファイルディスクリプタ
    int fd;    // 書き込み用ファイルのファイルディスクリプタ
    const char *msg = "This file was created using openat().\n";

    // /var/tmp を読み取り専用で開く
    if ((dirfd = open("/var/tmp", O_RDONLY)) < 0) {
        perror("/var/tmp");
        return 1;
    }

    // /var/tmp を起点に file.txt を作成・オープン（書き込み用、なければ作成、既存なら truncate）
    if ((fd = openat(dirfd, "file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0) {
        perror("file.txt");
        close(dirfd);
        return 1;
    }

    // データを書き込み
    if (write(fd, msg, sizeof("This file was created using openat().\n") - 1) < 0) {
        perror("write");
        close(fd);
        close(dirfd);
        return 1;
    }

    // クリーンアップ
    close(fd);
    close(dirfd);

    return 0;
}
