#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int sig_count = 0;

void handler(int signal)
{
    if (sig_count == 0)
    {
        pid_t id_filho = fork();
        if (id_filho == 0)
        {
            char *args[] = {"-f", "/dev/null", NULL};
            execvp("/bin/ls", args);
        }
    }
    printf("I received signal %d Count: %d\n", signal, sig_count);
    sig_count++;
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