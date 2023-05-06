#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

int error = 0, count = 0;
struct timeval start, end, start_c;
int main()
{

    int MAX_SIZE = 256 * sizeof(char);
    char *path, *args;
    int pid_child;

    path = malloc(MAX_SIZE);
    args = malloc(MAX_SIZE);

    while (scanf("%s %s", path, args) != EOF)
    {
        if (count == 0)
        {
            gettimeofday(&start, NULL);
            count++;
        }
        gettimeofday(&start_c, NULL);

        fflush(stdout);
        pid_child = fork();

        if (pid_child == 0) // Executing child.
        {
            execl(path, path, args, NULL);
            if (strcmp(strerror(errno), "Success") != 0)
            {
                printf("> Erro: %s\n", strerror(errno));
                fflush(stdout);
                error = errno;
                fclose(stdin);
                exit(errno);
            }
        }
        if (waitpid(pid_child, &error, WUNTRACED))
        {
            error = WEXITSTATUS(error);
            struct timeval end_c;
            gettimeofday(&end_c, NULL);
            double elapsed_time = end_c.tv_sec - start_c.tv_sec + (double)(end_c.tv_usec - start_c.tv_usec) / 1000000;
            printf("> Demorou %.1lf segundos, retornou %d\n", elapsed_time, error);
            fflush(stdout);
        }
    }

    gettimeofday(&end, NULL);
    double elapsed_time = end.tv_sec - start.tv_sec + (double)(end.tv_usec - start.tv_usec) / 1000000;
    printf(">> O tempo total foi de: %.1lf segundos\n", elapsed_time);
    fflush(stdout);
    exit(0);
}