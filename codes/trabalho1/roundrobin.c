
#include <stdlib.h>
#include <stdio.h>

/*
Entrada:
A primeira linha da entrada é um número inteiro N, entre 1 e 100, indicando o número de processos que serão escalonados.
A segunda linha contém a janela de tempo (100 < T <= 1000) em MILISSEGUNDOS. As próximas N linhas da entrada
possuem um identificador único (pid) e o tempo total de execução em SEGUNDOS que esse processo precisa para executar.

Saída:
A saída contém N linhas, onde os processos são impressos na ordem que terminaram a execução. Considere que todos
os processos iniciam a execução no tempo 0. Para cada um dos processos, também é impresso o tempo total quando o
processo terminou a execução, ou seja, o turnaround de cada processo.

Exemplo:
Exemplo de entrada

3
500
23 6
186 2
59 2
Saída para o exemplo de entrada

186 (5500)
59 (6000)
23 (10000
*/

typedef struct process
{
    long int pid;
    long int remaining_time;

} process;

void remove_index(process *p, int start, int size)
{
    for (int i = start; i < size; i++)
        p[i] = p[i + 1];
}

void print_process(process p)
{
    printf("%ld(-%ld) ", p.pid, p.remaining_time);
}
void print_processes(process *p, int size)
{
    for (int i = 0; i < size; i++)
        print_process(p[i]);
    printf("\n");
}
int main()
{
    int qt_processes;
    long int quantum;
    process *p;

    // Reading input
    scanf("%d", &qt_processes);
    scanf("%ld", &quantum);

    // Allocating memory for process array.
    p = malloc(qt_processes * sizeof(process));

    // Reading processes
    long int pid;
    long int remaining_time;
    for (int i = 0; i < qt_processes; i++)
    {
        scanf("%ld %ld", &pid, &remaining_time);
        // Converting from seconds to milisseconds
        remaining_time *= 1000;

        p[i].pid = pid;
        p[i].remaining_time = remaining_time;
    }

    long int time = 0;
    while (qt_processes > 0)
    {
        for (int i = 0; i < qt_processes; i++, time += quantum)
        {
            if (p[i].remaining_time > quantum)
                p[i].remaining_time -= quantum;
            else
            {
                printf("%ld (%ld)\n", p[i].pid, time + p[i].remaining_time);
                remove_index(p, i, qt_processes);
                qt_processes--;
                i--;
            }
            // print_processes(p, qt_processes);
        }
    }
    return 0;
}
