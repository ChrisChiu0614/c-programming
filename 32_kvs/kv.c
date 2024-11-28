#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void replaceNewlineWithNull(char *line)
{
    for (char *p = line; *p != '\0'; p++)
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
    }
}

kvarray_t *readKVs(const char *fname)
{
    // WRITE ME

    FILE *f = fopen(fname, "r");
    if (!f)
    {
        perror("failed to open the file.");
        return NULL;
    }

    size_t n = 0;
    char *line = NULL;
    kvarray_t *kv_arr = malloc(sizeof(*kv_arr));

    kv_arr->entry = NULL;
    kv_arr->len = 0;
    while (getline(&line, &n, f) > 0)
    {
        kv_arr->entry = realloc(kv_arr->entry, (kv_arr->len+1) * sizeof(*kv_arr->entry));

        replaceNewlineWithNull(line);

        char *equal_sign = strchr(line, '=');
        if (equal_sign != NULL)
        {
            size_t key_len = equal_sign - line;
            char *key = strndup(line, key_len);
            char *value = strdup(equal_sign + 1);
            kv_arr->entry[kv_arr->len] = NULL;
            kv_arr->entry[kv_arr->len] = realloc(kv_arr->entry[kv_arr->len], sizeof(*kv_arr->entry[kv_arr->len]));
            kv_arr->entry[kv_arr->len]->key = key;
            kv_arr->entry[kv_arr->len]->value = value;
            kv_arr->len++;
        }
        free(line);
        line = NULL;
    }
    free(line);
    fclose(f);
    return kv_arr;
}

void freeKVs(kvarray_t *pairs)
{
    // WRITE ME
    size_t n = pairs->len;
    for (size_t i = 0; i < n; i++)
    {
        free(pairs->entry[i]->key);
        free(pairs->entry[i]->value);
        free(pairs->entry[i]);
    }
    free(pairs->entry);
    free(pairs);
}

void printKVs(kvarray_t *pairs)
{
    // WRITE ME
    size_t n = pairs->len;
    for (size_t i = 0; i < n; i++)
    {
        printf("key = '%s' value = '%s'\n", pairs->entry[i]->key, pairs->entry[i]->value);
    }
}

char *lookupValue(kvarray_t *pairs, const char *key)
{
    // WRITE ME
    size_t n = pairs->len;
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(pairs->entry[i]->key, key) == 0)
        {
            return pairs->entry[i]->value;
        }
    }
    return NULL;
}
