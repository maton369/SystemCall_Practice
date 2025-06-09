#include <sys/syscall.h>    # システムコール番号 (SYS_write など) を定義

.section .text             # プログラム本体（命令）を配置するセクション
.globl _start              # エントリポイント _start をグローバルシンボルに指定

_start:
    movl $12, %edx         # 第3引数: 書き込むバイト数（12バイト）
    movl $message, %ecx    # 第2引数: 出力文字列のアドレス
    movl $1, %ebx          # 第1引数: 出力先ファイル記述子（1 = 標準出力）
    movl $SYS_write, %eax  # システムコール番号: write（通常 4）
    int $0x80              # ソフトウェア割り込みでシステムコールを実行

    xorl %ebx, %ebx        # 第1引数: 終了コード 0 を設定（ebx を 0 にクリア）
    movl $SYS_exit, %eax   # システムコール番号: exit（通常 1）
    int $0x80              # システムコール呼び出し（プロセス終了）

    # _start からは return しない（exit でプロセスが終了するため）

.section .data             # データ（文字列など）を配置するセクション
message:
    .ascii "Hello World\n" # 出力するメッセージ（改行付き）
