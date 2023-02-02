#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file1, *file2;
    for (int i = 1; i < argc; i++)
    {
        file1 = fopen(argv[i], "rb");
        file2 = fopen(argv[i + 1], "rb");

        if (file1 && file2)
        {
            fseek(file1, 0, SEEK_END);
            fseek(file2, 0, SEEK_END);

            long size1 = ftell(file1);
            long size2 = ftell(file2);

            if (size1 != size2)
                printf("%s %s diferentes\n", argv[i], argv[i + 1]);
            else
            {
                fseek(file1, 0, SEEK_SET);
                fseek(file2, 0, SEEK_SET);

                int *a, *b;
                int t;

                a = malloc(sizeof(int));
                b = malloc(sizeof(int));

                while (fread(a, 1, 1, file1) != 0 && fread(b, 1, 1, file2) != 0)
                {
                    if (*a != *b)
                    {
                        printf("%s %s diferentes\n", argv[i], argv[i + 1]);
                        break;
                    }
                }
                printf("%s %s iguais\n", argv[i], argv[i + 1]);
            }

            fclose(file1);
            fclose(file2);
        }
    }
    return 0;
}
