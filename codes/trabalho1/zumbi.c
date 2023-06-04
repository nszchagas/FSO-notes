#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

int sig_count = 0;

void handler(int signal)
{
    pid_t id_filho;
    sig_count++;
    if (sig_count == 1)
    {
        id_filho = fork();
        if (id_filho == 0)
        {
            char *args[] = {"-f", "/dev/null", NULL};
            execvp("/bin/tail", args);
        }
    }
    else if (sig_count == 2)
        wait(NULL);
    else
        exit(0);
}

int main()
{
    struct sigaction sa = {};
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (getchar() != 'X')
        ;
    return 0;
}