#include <unistd.h>  // fork(), execve(), _exit()
#include <stdio.h>   // perror()

int main() {
    pid_t pid;                   // プロセスID格納用変数
    char *argv[3];               // プログラムの引数配列
    extern char **environ;      // 環境変数への外部参照

    // forkで子プロセス作成
    if ((pid = fork()) < 0) {
        perror("fork");         // エラー時はメッセージ出力
        return 1;               // 異常終了
    } else if (pid == 0) {
        // 子プロセス側
        argv[0] = "echo";               // 第0引数：コマンド名
        argv[1] = "Hello, from child";  // 第1引数：表示するメッセージ
        argv[2] = NULL;                 // 引数リストの終端
        execve("/bin/echo", argv, environ);  // echoコマンドを実行

        // execveが失敗した場合だけここに来る
        perror("execve");
        _exit(1);
    }

    // 親プロセス側
    write(1, "Hello, from parent\n", 19);  // 親からのメッセージ
    return 0;                               // 正常終了
}
