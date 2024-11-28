#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t *createCounts(void)
{
    // WRITE ME
    counts_t *counts = malloc(sizeof(*counts));
    counts->one_count = malloc(sizeof(*counts->one_count));
    counts->len = 0;
    counts->unknown = 0;

    return counts;
}
void addCount(counts_t *c, const char *name)
{
    // WRITE ME

    if (c == NULL)
    {
        return;
    }
    if (name == NULL)
    {
        c->unknown++;
        return;
    }

    for (size_t i = 0; i < c->len; i++)
    {

        if (strcmp(c->one_count[i]->name, name) == 0)
        {
            c->one_count[i]->count++;
            return;
        }
    }
    c->one_count = realloc(c->one_count, (c->len + 1) * sizeof(c->one_count));

    c->one_count[c->len] = malloc(sizeof(**c->one_count));

    c->one_count[c->len]->name = strdup(name);

    c->one_count[c->len]->count = 1;
    c->len++;
}
void printCounts(counts_t *c, FILE *outFile)
{
    // WRITE ME
    if (c == NULL)
    {
        return;
    }

    if (outFile == NULL)
    {
        return;
    }

    for (size_t i = 0; i < c->len; i++)
    {
        fprintf(outFile, "%s: %lu\n", c->one_count[i]->name, c->one_count[i]->count);
    }
    if (c->unknown > 0)
    {
        fprintf(outFile, "<unknown> : %ld\n", c->unknown);
    }
}

void freeCounts(counts_t *c)
{
    // WRITE ME
    for (size_t i = 0; i < c->len; i++)
    {
        if (c->one_count[i] != NULL)
        {
            free(c->one_count[i]->name);
            free(c->one_count[i]);
        }
    }
    free(c->one_count);
    free(c);
}
