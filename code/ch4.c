#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int sum;                   // Data shared by the threads.
void *runner(void *param); // Pointer to the function to be shared by the threads.

int main(int argc, char *argv[])
{
    pthread_t tid;       // Thread identifier.
    pthread_attr_t attr; // Set of thread attributes.

    if (argc != 2) // If this program isn't called with an argument (beside its name) an error occurs
    {
        fprintf(stderr, "Usage: a.out <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >=0 \n", atoi(argv[1]));
        return -1;
    }

    pthread_attr_init(&attr); // Initialize thread attributes.

    /* Creates thread identified by tid (passed by reference) to run the runner function
                with param = argv[1] (passed by reference) */
    pthread_create(&tid, &attr, runner, argv[1]);

    /* The calling thread waits for completion of child thread
            The return status is not stored (NULL param); */
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);

    return 0;
}

// This function is controlled by the thread
void *runner(void *param)
{
    sum = 0;
    int i, upper = atoi(param);
    for (i = 1; i <= upper; i++)
        sum += i;
    pthread_exit(0);
}