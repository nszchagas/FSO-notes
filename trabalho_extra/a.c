#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
// #include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void handler(char *file_name, char *params)
{
    struct timeval *start, *end;
    start = malloc(sizeof(struct timeval));
    end = malloc(sizeof(struct timeval));
    int return_value, status;
    printf("%s %s\n", file_name, params);

    gettimeofday(start, NULL);
    pid_t pid = fork();
    pid_t terminated;
    if (pid < 0)
    {
        printf("Erro ao iniciar thread\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        return_value = execlp(file_name, file_name, params, NULL);
        printf("%d\n", errno);
        if (errno = !0)
            printf("Erro: %s\n", strerror(errno));
        gettimeofday(end, NULL);
        float elapsed = (float)(end->tv_sec - start->tv_sec);
        printf("> Demorou %0.10f segundos, retornou %d\n", elapsed, errno); //@TODO: arrumar a precisão pra 1 casa decimal
        exit(0);
    }
    else
    {
        terminated = wait(&status);
        gettimeofday(end, NULL);
        float elapsed = (float)(end->tv_usec - start->tv_usec) / 1000000;
        printf("> Demorou %0.10f segundos, retornou %d\n", elapsed, errno); //@TODO: arrumar a precisão pra 1 casa decimal
    }
}

int main()
{
    struct timeval *start, *end;
    start = malloc(sizeof(struct timeval));
    gettimeofday(start, NULL);
    int MAX_SIZE = 255;
    char *file_name = malloc(MAX_SIZE * sizeof(char));
    char *params = malloc(MAX_SIZE * sizeof(char));

    while (scanf("%s %s", file_name, params) != -1)
    {
        handler(file_name, params);
    }
    end = malloc(sizeof(struct timeval));
    gettimeofday(end, NULL);
    float elapsed = (float)(end->tv_usec - start->tv_usec) / 1000000;
    printf(">> O tempo total foi de: %0.5f segundos\n", elapsed); //@TODO: arrumar a precisão pra 1 casa decimal
    return 0;
}
