#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid = getpid();
    pid_t pgid = getpgid(0);

    printf("Before setpgid: PID = %d, PGID = %d\n", pid, pgid);
    fflush(stdout);  // バッファを強制フラッシュ

    if (setpgid(0, 0) < 0) {
        perror("setpgid");
        return 1;
    }

    pgid = getpgid(0);
    printf("After setpgid: PID = %d, PGID = %d\n", pid, pgid);
    fflush(stdout);

    sleep(1);

    return 0;
}
