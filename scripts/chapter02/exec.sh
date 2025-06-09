#!/bin/bash

set -e

# ps aux | tee output.log

# gcc -o fork fork.c
# ./fork | tee output.log

# gcc -o execve execve.c
# ./execve | tee output.log

# gcc -o exit exit.c
# ./exit | tee output.log
# echo $? |tee -a output.log

# gcc -o wait wait.c
# ./wait | tee output.log

# gcc -o waitpid waitpid.c
# ./waitpid | tee output.log

# gcc -o wait4 wait4.c
# ./wait4 | tee output.log

# gcc -o waitid waitid.c
# ./waitid | tee output.log

# gcc -o getpid getpid.c
# echo $$ | tee output.log
# ./getpid | tee -a output.log
# rm -f getpid

# gcc -o chdir chdir.c
# ./chdir | tee output.log
# rm -f chdir

# gcc -o fchdir fchdir.c
# ./fchdir | tee output.log
# rm -f fchdir

# gcc -o chroot chroot.c
# ./chroot > output.log 2>&1 &
# PID=$!
# sleep 1
# echo ">>> プロセス $PID のルート確認:"
# if readlink "/proc/$PID/root" 2>/dev/null; then
#     echo ">>> chroot 確認成功"
# else
#     echo ">>> chroot 確認失敗（プロセスが終了した可能性あり）"
# fi
# echo ">>> 出力内容:"
# cat output.log
# rm -f chroot

# gcc -o getpriority getpriority.c
# echo "通常実行:"
# ./getpriority
# echo "nice 経由実行:"
# nice ./getpriority
# echo "nice -19 指定実行:"
# nice -n 19 ./getpriority
# rm -f getpriority

# gcc -o getpriority getpriority.c
# gcc -o setpriority setpriority.c
# ./setpriority | tee output.log
# rm -f setpriority
# rm -f getpriority

# getent group mail >/dev/null || groupadd mail
# id apache >/dev/null 2>&1 || useradd -g mail apache
# gcc -o getuid getuid.c
# chown apache:mail getuid
# chmod ug+s getuid
# echo ">>> getuid 実行ファイルの属性:"
# ls -l getuid
# ls -n getuid
# echo ">>> id コマンドによる現在のユーザー情報:"
# id
# echo ">>> getuid 実行:"
# ./getuid | tee output.log
# rm -f getuid

# echo "[*] setuid.c をビルド中..."
# gcc -o setuid setuid.c
# echo "[*] root 所有の setuid 実行ファイルを作成..."
# chown root setuid
# chmod u+s setuid
# ls -l setuid
# ls -n setuid
# echo "[*] 現在のユーザー情報:"
# id
# echo "[*] ./setuid を一般ユーザーで実行:"
# ./setuid || true  # 特権昇格に失敗してもスクリプトを止めない
# echo
# echo "[*] 一般ユーザーで再実行できるように apache 所有に変更..."
# chown apache setuid
# chmod u+s setuid
# ls -l setuid
# ls -n setuid
# echo "[*] ./setuid を再実行:"
# ./setuid || true
# echo
# echo "[*] root 所有に戻して再実行（戻れないパターンを確認）..."
# chown root setuid
# chmod u+s setuid
# ls -l setuid
# ./setuid || true | tee output.log
# echo
# echo "[*] クリーンアップ..."
# rm -f setuid

# echo "[*] seteuid.c をビルド中..."
# gcc -o seteuid seteuid.c
# if ! id apache >/dev/null 2>&1; then
#   echo "[*] 一時ユーザー 'apache' を作成中..."
#   useradd -M -s /sbin/nologin apache
# fi
# echo "[*] apache 所有の seteuid 実行ファイルを作成..."
# chown apache seteuid
# chmod u+s seteuid
# echo "[*] seteuid 実行ファイルの属性:"
# ls -l seteuid
# ls -n seteuid
# echo "[*] 現在のユーザー情報:"
# id
# echo "[*] ./seteuid を一般ユーザーで実行:"
# ./seteuid || true
# echo
# echo "[*] root 所有に戻して再実行（rootの動作確認）..."
# chown root seteuid
# chmod u+s seteuid
# ls -l seteuid
# ./seteuid || true | tee output.log
# echo
# echo "[*] クリーンアップ..."
# rm -f seteuid

# echo "[*] setreuid.c をビルド中..."
# gcc -o setreuid setreuid.c
# id apache &>/dev/null || useradd -r apache
# echo "[*] setuid テスト: apache 所有 + SUID で実行"
# chown apache setreuid
# chmod u+s setreuid
# echo "[*] 実行ファイルの属性:"
# ls -l setreuid
# ls -n setreuid
# echo "[*] 現在のユーザー:"
# id
# echo "[*] 実行:"
# ./setreuid || true
# echo
# echo "[*] root 所有に切り替え（root特権再昇格テスト）..."
# chown root setreuid
# chmod u+s setreuid
# echo "[*] 実行ファイルの属性:"
# ls -l setreuid
# echo "[*] 再実行:"
# ./setreuid || true
# echo
# echo "[*] クリーンアップ..."
# rm -f setreuid

# gcc -o getpgid getpgid.c
# ./getpgid | tee output.log
# rm -f getpgid

# gcc -o setpgid setpgid.c
# (./setpgid &) | tee output.log
# rm -f setpgid

# gcc -o setsid setsid.c
# ./setsid | tee output.log
# rm -f setsid

# gcc -o getsid getsid.c
# ./getsid | tee output.log
# rm -f getsid

# gcc -o getgroups getgroups.c
# ./getgroups | tee output.log
# rm -f getgroups

# gcc -o getgroups getgroups.c
# gcc -o setgroups setgroups.c
# ./setgroups | tee output.log
# rm -f setgroups
# rm -f getgroups

# gcc -o getrusage getrusage.c
# ./getrusage | tee output.log
# rm -f getrusage

gcc -o getrlimit getrlimit.c
./getrlimit | tee output.log
rm -f getrlimit