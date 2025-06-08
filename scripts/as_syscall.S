#include <sys/syscall.h>        # 定数 SYS_write, SYS_exit を定義

.section .text                  # 実行コードセクションの開始
.globl _start                   # _start ラベルをエントリポイントとして宣言

_start:
    # write(1, message, 12)
    mov     $12, %rdx           # 第3引数: 出力するバイト数
    mov     $message, %rsi      # 第2引数: 出力する文字列のアドレス
    mov     $1, %rdi            # 第1引数: ファイル記述子 1 (標準出力)
    mov     $SYS_write, %rax    # write システムコール番号 (通常 1)
    syscall                     # カーネルにシステムコールを発行

    # exit(0)
    xor     %rdi, %rdi          # 第1引数: 終了ステータス 0
    mov     $SYS_exit, %rax     # exit システムコール番号 (通常 60)
    syscall                     # カーネルにシステムコールを発行

.section .data
message:
    .ascii "Hello World\n"      # 出力する文字列（改行込みで12バイト）
