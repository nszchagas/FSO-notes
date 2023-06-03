#include <stdlib.h>
#include <stdio.h>

typedef struct process
{
    long int pid;
    long int duration_time;
    long int finished_at;

} process;

// TODO: change to local

void ls_ps(int qt_processes, process *ps)
{
    for (int i = 0; i < qt_processes; i++)
        printf("> {pid: %ld, duration_time: %ld, finished_at: %ld}\n", ps[i].pid, ps[i].duration_time, ps[i].finished_at);
}

int main()
{
    int NOT_FINISHED = -1;
    process *ps;
    long int qt_processes;
    long int quantum;

    scanf("%ld", &qt_processes);

    ps = malloc(qt_processes * sizeof(process));
    scanf("%ld", &quantum);

    for (int i = 0; i < qt_processes; i++)
    {
        int time;
        scanf("%ld %ld", &ps[i].pid, &time);
        ps[i].duration_time = 1000 * time;
        ps[i].finished_at = -1;
    }
    int finished = 0;
    int time = 0, j = 0;
    while (finished != qt_processes)
    {
        time += quantum;

        int iter_time = quantum;
        do
        {
            if (ps[j].finished_at == NOT_FINISHED && iter_time > 0)
            {
                int temp = ps[j].duration_time;
                ps[j].duration_time -= iter_time;
                iter_time = iter_time - temp;
                if (ps[j].duration_time <= 0 && ps[j].finished_at == -1)
                {
                    ps[j].finished_at = time + quantum - iter_time;
                    finished++;
                    printf("%ld (%ld)\n", ps[j].pid, ps[j].finished_at);
                }
            }

            j = (j + 1) % qt_processes;
        } while (iter_time > 0 && finished != qt_processes);
    }
    free(ps);

    return 0;
}