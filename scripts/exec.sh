#!/bin/bash

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

gcc -o getpriority getpriority.c
echo "通常実行:"
./getpriority
echo "nice 経由実行:"
nice ./getpriority
echo "nice -19 指定実行:"
nice -n 19 ./getpriority
rm -f getpriority