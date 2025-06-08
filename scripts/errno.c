#include <string.h>   // strerror() を使用するために必要
#include <stdio.h>    // printf() を使用するために必要
#include <locale.h>   // setlocale() を使用するために必要

int main() {
    int i;  // ループカウンタ

    setlocale(LC_ALL, "");  // 現在のロケール（言語環境）を有効にする

    for (i = 0; i <= 255; i++) {  // errno の範囲 0〜255 をループ
        printf("%d %s\n", i, strerror(i));  // 各エラー番号に対応するメッセージを表示
    }

    return 0;  // 正常終了
}
