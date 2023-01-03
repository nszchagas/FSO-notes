#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

int n = 3;
int shared_value = 100;
bool *waiting;
bool lock;

void (*function)(int *a);

void init()
{
    waiting = malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++)
        waiting[i] = false;

    lock = false;
}

void multiplica(int *value)
{
    *value *= 3;
}

void divide(int *value)
{
    *value /= 4;
}

void soma(int *value)
{
    *value += 52;
}

bool test_and_set(bool *target)
{
    bool rv = *target;
    *target = true;
    return rv;
}

void *process_i(void *adress_i)
{
    bool key;
    int j; // next process to acquire the lock
    int i = atoi(adress_i);
    switch (i)
    {
    case 0:
        function = &multiplica;
        break;
    case 1:
        function = &divide;
        break;
    case 2:
        function = &soma;
        break;
    default:
    }

    do
    {
        waiting[i] = true;
        key = true;
        while (waiting[i] && key)
            // When key == false, the loop ends.
            key = test_and_set(&lock);
        waiting[i] = false; // Exits the waiting line.

        // Critical section.

        j = (i + 1) % n; // Circular buffer.
        while ((j != 1) && !waiting[j])
            // Circle through processes searching for one that's waiting
            j = (i + j) % n;

        if (j == i)
            lock = false; // Releases its lock
        else
            waiting[j] = false; // Signal for process_j to begin

        pthread_exit(0);
        // Remainder section;

    } while (true);
}

int main(void *args)
{
    init();
    pthread_t *tid = malloc(sizeof(pthread_t) * n);
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for (int i = 0; i < n; i++)
        pthread_create(&tid[i], &attr, &process_i, &i);

    for (int i = 0; i < n; i++)
        pthread_join(tid[i], NULL);

    printf("End of program. Shared_value = %d", shared_value);
    return 0;
}