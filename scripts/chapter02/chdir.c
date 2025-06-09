#include <unistd.h>   // chdir() に必要なヘッダファイル
#include <stdio.h>    // perror() に必要なヘッダファイル
#include <stdlib.h>   // system() に必要なヘッダファイル

int main() {
    // カレントディレクトリを /tmp に変更
    if (chdir("/tmp") < 0) {
        perror("chdir");     // 失敗時のエラー表示
        return 1;            // 異常終了
    }

    // 現在のディレクトリを表示（確認用）
    system("pwd");

    return 0;  // 正常終了
}
