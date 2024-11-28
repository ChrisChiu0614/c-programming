#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int get_max_id(int *count, size_t size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (count[i] > count[max])
        {
            max = i;
        }
    }
    return max;
}

void count_f(FILE *file, int *count)
{
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            c -= 'a';
            count[c] += 1;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Usage: <fileName>");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("failed to open file");
        return EXIT_FAILURE;
    }

    // count[0,25]
    int count[26] = {0};
    count_f(file, count);
    int max_idx = get_max_id(count, 26);
    int key = (max_idx - ('e' - 'a') + 26) % 26;
    printf("%d\n", key);
    return EXIT_SUCCESS;
}
