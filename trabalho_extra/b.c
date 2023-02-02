#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void *handler(void *args);

int main()
{
    struct timeval start, end, dt;
    gettimeofday(&start, NULL);

    int MAX_SIZE = 255;

    char *params = malloc(2 * MAX_SIZE * sizeof(char));

    pthread_attr_t attrs;
    pthread_t child;

    pthread_attr_init(&attrs);

    while (scanf("%s %s", &params[0], &params[1]) != -1)
    {
        pthread_create(&child, &attrs, handler, params);
        pthread_join(child, NULL);
    }

    gettimeofday(&end, NULL);
    timersub(&end, &start, &dt);
    printf(">> O tempo total foi de: %ld.%06ld segundos\n", dt.tv_sec, dt.tv_usec); //@TODO: arrumar a precisão pra 1 casa decimal
    return 0;
}

void *handler(void *args)
{
    struct timeval start, end, dt;

    gettimeofday(&start, NULL);
    printf("start: %ld.%06ld\n", start.tv_sec, start.tv_usec);
    char *params;
    params = args;
    printf("%s %s \n", params[0], params[1]);
    int return_value = execlp(&params[0], &params[0], &params[1], NULL);
    printf("%d\n", errno);
    if (errno = !0)
        printf("Erro: %s\n", strerror(errno));
    gettimeofday(&end, NULL);
    timersub(&end, &start, &dt);
    printf("end: %ld.%06ld\n", end.tv_sec, end.tv_usec);
    printf("> Demorou %ld.%06ld segundos, retornou %d\n", dt.tv_sec, dt.tv_usec, errno); //@TODO: arrumar a precisão pra 1 casa decimal
}
