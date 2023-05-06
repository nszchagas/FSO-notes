#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[])
{

    int (*imprime)(void);
    int (*calcula)(int a, int b);
    int (*trigo)(double a, double *b);
    if (argc == 5)
    {
        int a, b;
        double c;
        a = atoi(args[2]);
        b = atoi(args[3]);
        c = atof(args[4]);
        void *mylib;

        if (args[1] != NULL)
        {
            mylib = dlopen(args[1], RTLD_NOW);
            if (!mylib)
            {
                printf("nao disponivel");
                return 0;
            }
        }
        else
        {
            printf("nao disponivel");
            return 0;
        }
        *(int **)(&imprime) = dlsym(mylib, "imprime");
        *(int **)(&calcula) = dlsym(mylib, "calcula");
        *(int **)(&trigo) = dlsym(mylib, "trigo");

        if (!imprime)
            printf("nao implementado\n");
        else
            printf("%d\n", imprime());
        if (!calcula)
            printf("nao implementado\n");
        else
            printf("%d\n", calcula(a, b));
        if (!trigo)
            printf("nao implementado\n");
        else
            printf("%d\n", trigo(c, &c));

        dlclose(mylib);
    }
    return 0;
}