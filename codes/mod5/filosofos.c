//--8<-- [start:solucao1]
#include <stdio.h>
#include <unistd.h>

int qtPhilosophers = 5; // Number of philosophers.

void think(int i)
{
    printf("Philosopher %d is THINKING...\n\n", i);
    sleep(1);
}

void take_fork(int i)
{
    printf("Attempting to get fork at position %d.\n\n", i);
}

void eat()
{
    printf("Eating...\n\n");
    sleep(1);
}

void put_fork(int i)
{
    printf("Returning fork at position %d.\n\n", i);
}

void philosopher(int i)
{
    while (1)
    {
        int left = i;
        int right = (i + 1) % qtPhilosophers;
        think(i);
        take_fork(left);
        take_fork(right);
        eat();
        put_fork(right); // Returning in inverse order of retrieval
        put_fork(left);  // increases parallelism.
    }
}
//--8<-- [end:solucao1]
