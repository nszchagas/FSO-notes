#include <stdlib.h>
#include <stdio.h>

// Substituir o valor que está mais longe de se repetir.

int time = 0;
int *pages_accessed;
int *ram_pages;
int number_accesses;

int next_use(int value)
{
    for (int i = time; i < number_accesses; i++)
    {
        if (pages_accessed[i] == value)
            return i;
    }
    return -1; // Won't be used anymore.
}

int get_index_to_remove(int *ram_pages, int ram_size)
{
    int dist = next_use(ram_pages[0]);
    if (dist == -1)
        return 0;

    int index = 0;
    for (int i = 1; i < ram_size; i++)
    {
        int t = next_use(ram_pages[i]);
        if (t == -1)
            return i; // This page won't be used and can be removed.
        if (t > dist)
        {
            dist = t;
            index = i;
        }
    }
    return index;
}

int replace_opt(int *pages, int size, int new_page)
{
    for (int i = 0; i < size; i++)
    {
        if (pages[i] == -1)
        {
            pages[i] = new_page;
            return 1;
        }
        if (pages[i] == new_page)
        {
            return 0;
        }
    }
    int index = get_index_to_remove(pages, size);

    pages[index] = new_page;

    return 1;
}

int main()
{
    int frames_available, page_faults = 0, curr_page;
    scanf("%d", &frames_available);
    scanf("%d", &number_accesses);
    pages_accessed = malloc(sizeof(int) * number_accesses);
    ram_pages = malloc(sizeof(int) * frames_available);
    int ram_pos = 0;
    for (int i = 0; i < number_accesses; i++)
        scanf("%d", &pages_accessed[i]);

    for (int i = 0; i < frames_available; i++)
        ram_pages[i] = -1;
    for (time = 0; time < number_accesses; time++)
        page_faults += replace_opt(ram_pages, frames_available, pages_accessed[time]);
    printf("%d", page_faults);
    return 0;
}