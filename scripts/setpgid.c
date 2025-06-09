#include <unistd.h>   // setpgid(), sleep()
#include <stdio.h>    // perror()

int main()
{
    // プロセスグループIDを自身のPIDと同じに設定（通常これはデフォルト）
    if (setpgid(0, 0) < 0) {
        perror("setpgid");
        return 1;
    }

    // PGID変更後の処理（例：確認用にスリープ）
    sleep(60);

    return 0;
}
