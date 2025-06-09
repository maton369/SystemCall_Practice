#include <unistd.h>   // read, write に必要
#include <stdio.h>    // perror に必要

int main()
{
    ssize_t n;            // 読み込んだバイト数
    char buf[4096];       // 読み込み用バッファ

    // 標準入力から読み込む
    if ((n = read(0, buf, sizeof(buf))) < 0) {
        perror("read");   // 読み込みエラー表示
        return 1;         // 異常終了
    }

    // 読み込んだ内容を標準出力に書き出す
    if (write(1, buf, n) < 0) {
        perror("write");  // 書き込みエラー表示
        return 1;
    }

    return 0;             // 正常終了
}
