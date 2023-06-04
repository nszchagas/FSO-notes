#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <wait.h>
#include <string.h>

double get_time_diff(struct timeval start, struct timeval end)
{
    return end.tv_sec - start.tv_sec + (double)(end.tv_usec - start.tv_usec) / 1000000;
}

int error = 0;
struct timeval g_start, g_end, p_start, p_end;
pid_t pid_child;
int main()
{
    char path[255], args[255];
    gettimeofday(&g_start, NULL);

    while (scanf("%s %s", path, args) != EOF)
    {
        gettimeofday(&p_start, NULL);

        fflush(stdout);
        pid_child = fork();

        if (pid_child == 0) // Runs child
        {
            execl(path, path, args, NULL);
            if (errno != 0)
            {
                printf("> Erro: %s\n", strerror(errno));
                fflush(stdout);
                fclose(stdin);
                exit(errno);
            }
        }
        if (waitpid(pid_child, &error, WUNTRACED))
        {
            error = WEXITSTATUS(error);
            gettimeofday(&p_end, NULL);
            double tempo = get_time_diff(p_start, p_end);
            printf("> Demorou %0.1lf segundos, retornou %d\n", tempo, error);
            fflush(stdout);
        }
    }

    gettimeofday(&g_end, NULL);
    double total_time = get_time_diff(g_start, g_end);
    printf(">> O tempo total foi de %0.1lf segundos\n", total_time);
    fflush(stdout);
    exit(0);
}