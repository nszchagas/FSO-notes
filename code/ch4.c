#include <omp.h>
#include <stdio.h>

int main(int argc, char *argsv[])
{

#pragma omp parallel {
    printf("Parallel thread");
}

return 0;
}