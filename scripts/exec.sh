#!/bin/bash
set -e  # エラー時に即終了

# echo "[*] Building as_int80 (32-bit)..."
# gcc -m32 -o as_int80 as_int80.S -nostdlib
# echo "[*] Running as_int80..."
# ./as_int80 | tee output.log
# echo "[*] Done. Output saved to output.log"

echo "[*] as_sysenter をビルドしています（32ビット）..."
gcc -m32 -no-pie -o as_sysenter as_sysenter.S -nostdlib

echo "[*] as_sysenter を実行しています..."
./as_sysenter | tee output.log

echo "[*] 実行完了。出力は output.log に保存されました。"