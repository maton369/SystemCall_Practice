#!/bin/bash
set -e  # エラー時に即終了

# echo "[*] Building as_int80 (32-bit)..."
# gcc -m32 -o as_int80 as_int80.S -nostdlib
# echo "[*] Running as_int80..."
# ./as_int80 | tee output.log
# echo "[*] Done. Output saved to output.log"

# echo "[*] as_sysenter をビルドしています（32ビット）..."
# gcc -m32 -no-pie -o as_sysenter as_sysenter.S -nostdlib
# echo "[*] as_sysenter を実行しています..."
# ./as_sysenter | tee output.log
# echo "[*] 実行完了。出力は output.log に保存されました。"

# echo "[*] as_syscall をビルドしています（64ビット）..."
# gcc -nostdlib -static -o as_syscall as_syscall.S
# echo "[*] as_syscall を実行しています..."
# ./as_syscall | tee output.log
# echo "[*] 実行完了。出力は output.log に保存されました。"

# errno.c をコンパイル
gcc -o errno errno.c
# ロケール関連の環境変数を明示的に解除（LANG の効果を優先させるため）
unset LC_ALL LC_MESSAGES LC_CTYPE
# 日本語ロケールで実行し、出力を output.log に保存
LANG=ja_JP.UTF-8 ./errno | tee output.log
