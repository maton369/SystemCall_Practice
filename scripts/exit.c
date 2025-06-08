#include <unistd.h>  // _exit() に必要なヘッダ

int main() {
    _exit(0);  // ステータス0でプロセスを即座に終了（バッファ等はflushされない）

    // この行には到達しない
}
