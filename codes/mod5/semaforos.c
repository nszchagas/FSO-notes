//--8<-- [start:solucao]

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define N 5

#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N

#define THINKING 0
#define HUNGRY 1
#define EATING 2

// Semáforo binário para proteger as funções de pegar e guardar os garfos.
sem_t mutex;

// Estados dos filósofos, entre {HUNGRY, EATING, THINKING}.
int state[N];

// Array de semáforos para os N filósofos.
sem_t s[N];

// Número dos filósofos definido globalmente para ser
// acessado pelos processos filhos.
int phil[N] = {0, 1, 2, 3, 4};

// Testa se os garfos estão livres para o filósofo i,
// o que ocorre se os seus vizinhos não estiverem comendo.
void test(int i)
{
    if (
        state[i] == HUNGRY 
        && state[LEFT] != EATING 
        && state[RIGHT] != EATING)
    {
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d. \n", 
        i, LEFT, RIGHT);
        printf("Philosopher %d is EATING.\n", i);
        
        sem_post(&s[i]);
    }
}

// Função "atômica" para pegar ambos garfos, protegida pelo mutex.
void take_forks(int i)
{
    sem_wait(&mutex);
    state[i] = HUNGRY;

    printf("Philosopher %d is HUNGRY.\n", i);

    test(i);
    sem_post(&mutex);

    sem_wait(&s[i]);
    sleep(1);
}

// Função "atômica" para devolver os garfos e 
// sinalizar os vizinhos.
void put_forks(int i)
{
    sem_wait(&mutex);
    state[i] = THINKING;

    printf("Philosopher %d is putting down forks %d and %d.\n", 
                i, LEFT, RIGHT);
    printf("Philosopher %d is THINKING.\n", i);
    test(LEFT);
    test(RIGHT);

    sem_post(&mutex);
}

void think(int i)
{
    printf("Philosopher %d is THINKING...\n", i);
    sleep(1);
}

void *philosopher_semaphores(void *num)
{
    while (1)
    {
        int *i = num;
        think(*i);

        take_forks(*i);
        sleep(1);
        put_forks(*i);
    }
}



// Aplicação utilizando pthreads.
void main()
{
    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < N; i++)
        sem_init(&s[i], 0, 0);

    for (i = 0; i < N; i++)
        pthread_create(&thread_id[i], 
          NULL, philosopher_semaphores, &phil[i]);

    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}
//--8<-- [end:solucao]