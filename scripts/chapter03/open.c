#include <sys/stat.h>   // open 用のパーミッション指定などに必要
#include <fcntl.h>      // open 用の定数（O_RDONLYなど）
#include <unistd.h>     // read(), write(), close() に必要
#include <stdio.h>      // perror()

int main()
{
    int fd_r, fd_w;  // ファイルディスクリプタ用変数
    char buf[1024];  // 読み取り・書き込みバッファ
    ssize_t bytes;

    // /etc/hosts を読み込み専用でオープン
    if ((fd_r = open("/etc/hosts", O_RDONLY)) < 0) {
        perror("/etc/hosts");
        return 1;
    }

    // file.txt を書き込み専用で O_CREAT（なければ作成）と O_TRUNC（既存なら truncate）付きでオープン
    if ((fd_w = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0) {
        perror("file.txt");
        close(fd_r);
        return 1;
    }

    // 読み取りと書き込みのループ
    while ((bytes = read(fd_r, buf, sizeof(buf))) > 0) {
        if (write(fd_w, buf, bytes) != bytes) {
            perror("write");
            close(fd_r);
            close(fd_w);
            return 1;
        }
    }

    if (bytes < 0) {
        perror("read");
    }

    // ファイルディスクリプタをクローズ
    close(fd_r);
    close(fd_w);

    return 0;
}
