
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

void print_process(process p)
{
    printf("{pid: %ld, remaining_time: %ld}\n", p.pid, p.remaining_time);
}
int main()
{
    int qt_processes;
    long int quantum;
    process *processes;

    // Reading input
    scanf("%d", &qt_processes);
    scanf("%ld", &quantum);

    // Allocating memory for process array.
    processes = malloc(qt_processes * sizeof(process));

    // Reading processes

    long int pid;
    long int remaining_time;
    for (int i = 0; i < qt_processes; i++)
    {
        scanf("%ld %ld", &pid, &remaining_time);
        // Converting from seconds to milisseconds
        remaining_time *= 1000;

        processes[i].pid = pid;
        processes[i].remaining_time = remaining_time;
    }

    // Running processor

    int qt_finished = 0;
    int i = 0;
    long int time = 0;
    long int iteration_time = quantum;
    // While there are processes to run, circle through processes.
    while (qt_finished != qt_processes)
    {
        if (processes[i].remaining_time != 0)
        {
            if (processes[i].remaining_time > iteration_time)
            {
                processes[i].remaining_time -= iteration_time;
                time += iteration_time;
            }
            else
            {
                time += processes[i].remaining_time;
                printf("%ld (%ld)\n", processes[i].pid, time);
                processes[i].remaining_time = 0;
                qt_finished++;
            }
        }
        i = (i + 1) % qt_processes;
    }
    return 0;
}
