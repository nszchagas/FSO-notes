#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    pid_t pid, pid_terminated;
    int status;

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("\nExecuting child!\n\n");
        execlp("/bin/ps", "-l", NULL);
    }
    else
    {
        pid_terminated = wait(&status);
        printf("\nChild PID was: %d and its now terminated with status: %d.\n\n", pid_terminated, status);
        execlp("/bin/ps", "-l", NULL);
        printf("\n");
    }

    return 0;
}