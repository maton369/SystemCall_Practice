#include <unistd.h>  // write に必要
#include <stdio.h>   // perror に必要

int main()
{
    ssize_t n;  // 書き込んだバイト数を受け取る変数

    // 標準出力にメッセージを書き出す
    if ((n = write(1, "Hello\n", 6)) < 0) {
        perror("write");  // エラーが発生した場合
        return 1;         // 異常終了
    }

    return 0;  // 正常終了
}
