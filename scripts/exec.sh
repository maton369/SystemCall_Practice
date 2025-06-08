#!/bin/bash
set -e  # エラー時に即終了

echo "[*] Building as_int80 (32-bit)..."
gcc -m32 -o as_int80 as_int80.S -nostdlib

echo "[*] Running as_int80..."
./as_int80 | tee output.log

echo "[*] Done. Output saved to output.log"
