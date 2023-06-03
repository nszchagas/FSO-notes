#include <stdlib.h>
#include <stdio.h>

int pos = 0;

void print_list(int *v, int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf(" %d]\n", v[size - 1]);
}

int insert_page(int *v, int size, int page)
{
    for (int i = 0; i < size; i++)
        if (v[i] == page)
            return 0;

    v[pos] = page;
    pos = (pos + 1) % size;
    return 1;
}

int main()
{
    int frames_available, references, page_faults = 0, curr_page;
    scanf("%d", &frames_available);
    scanf("%d", &references);
    int *ram_pages = malloc(frames_available * sizeof(int));
    for (int i = 0; i < frames_available; i++)
    {
        ram_pages[i] = -1;
    }

    for (int i = 0; i < references; i++)
    {
        scanf("%d", &curr_page);
        page_faults += insert_page(ram_pages, frames_available, curr_page);
        
    }
    printf("%d", page_faults);

    return 0;
}