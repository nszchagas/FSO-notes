#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS = 2;
void *ordena(int *vetor);

int array_size; // Global so the threads can share it
int *v1, *v2;

void read_array(int *v)
{
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &v[i]);
    }
}

void print_array(int *v)
{
    printf("[");
    for (int i = 0; i < array_size - 1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[array_size - 1]);
}

/* Puts the median between fist, middle and last elements of an array at the last position*/
void put_median_end(int *v, int l, int r)
{
    int middle = (r - l) / 2;
    int f = v[l], m = v[middle], e = v[r], t;
    if (f >= m && f <= e || f >= e && f <= m)      // f is median
        t = v[r], v[r] = v[l], v[l] = t;           // Changes first and last element
    else if (m >= f && m <= e || m >= e && m <= f) // m is median
        t = v[r], v[r] = v[middle], v[middle] = t; // Changes middle and last element
}

void change(int *v, int l, int r)
{
    int pivot = v[r];
    int j = l, t;
    for (int i = l; i < r; i++)
    {
        if (v[i] <= pivot)
        {
            t = v[j], v[j] = v[i], v[i] = t;
            j++;
        }
    }
    t = v[j], v[j] = v[r], v[r] = t;
}

void *ordena(int *v)
{
}

int main(int argc, char *argv[])
{

    scanf("%d", &array_size);
    v1 = malloc(array_size * sizeof(int));
    v2 = malloc(array_size * sizeof(int));
    read_array(v1);
    read_array(v2);
    put_median_end(v1, 0, array_size - 1);
    put_median_end(v2, 0, array_size - 1);
    print_array(v1);
    print_array(v2);
}