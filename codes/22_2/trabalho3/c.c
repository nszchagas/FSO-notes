#include <stdlib.h>
#include <stdio.h>

// Implementar buffer circular guardando nós com a última posição acessada. Trocar o que tem a menor

int time = 0;

typedef struct no
{
    int number;
    int last_used;

} no;

int replace_lru(no *pages, int size, int new_page)
{

    int min = time;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (pages[i].number == -1)
        {
            pages[i].number = new_page;
            pages[i].last_used = time;
            return 1;
        }
        if (pages[i].number == new_page)
        {
            pages[i].last_used = time;
            return 0;
        }
        if (pages[i].last_used < min)
        {
            min = pages[i].last_used;
            index = i;
        }
    }
    pages[index].number = new_page;
    pages[index].last_used = time;
    return 1;
}

void print_list(no *v, int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("(%d, lu: %d), ", v[i].number, v[i].last_used);
    }
    printf(" (%d, lu: %d)]\n", v[size - 1].number, v[size - 1].last_used);
}

int main()
{
    int frames_available, references, page_faults = 0, curr_page;
    scanf("%d", &frames_available);
    scanf("%d", &references);
    no *ram_pages = malloc(frames_available * sizeof(no));

    for (int i = 0; i < frames_available; i++)
    {
        ram_pages[i].number = -1;
    }

    for (; time < references; time++)
    {
        scanf("%d", &curr_page);
        page_faults += replace_lru(ram_pages, frames_available, curr_page);

        // printf("%d    ->   ", time + 1);
        // print_list(ram_pages, frames_available);
    }
    printf("%d", page_faults);

    return 0;
}