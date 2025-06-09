#include <unistd.h>     // fchdir()
#include <sys/stat.h>   // open()
#include <fcntl.h>      // open()
#include <stdio.h>      // perror()
#include <stdlib.h>     // system()

int main() {
    int fd;  // ディレクトリのファイルディスクリプタ

    // /usr/bin を読み取り専用でオープン
    if ((fd = open("/usr/bin", O_RDONLY)) < 0) {
        perror("open");  // オープン失敗時にエラー出力
        return 1;        // 異常終了
    }

    // fchdir を使ってファイルディスクリプタでカレントディレクトリを変更
    if (fchdir(fd) < 0) {
        perror("fchdir");  // エラー時にメッセージ表示
        return 1;          // 異常終了
    }

    // 現在のディレクトリを表示
    system("pwd");

    return 0;  // 正常終了
}
