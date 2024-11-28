#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t *countFile(const char *filename, kvarray_t *kvPairs)
{
    // WRITE ME
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        perror("Failed to open the file.");
        return NULL;
    }
    size_t sz = 0;
    char *key = NULL;
    counts_t *c = createCounts();
    while (getline(&key, &sz, f) > 0)
    {
        replaceNewlineWithNull(key);
        char *value = lookupValue(kvPairs, key);
        addCount(c, value);
        free(key);
        key = NULL;
    }
    free(key);
    fclose(f);
    return c;
}

int main(int argc, char **argv)
{
    // WRITE ME (plus add appropriate error checking!)
    if (argc < 3)
    {
        perror("error argc counts");
        return EXIT_FAILURE;
    }
    // read the key/value pairs from the file named by argv[1] (call the result kv) 
    kvarray_t *kv = readKVs(argv[1]);
    // count from 2 to argc (call the number you count i)
    for (size_t i = 2; i < argc; i++)
    {
        // count the values that appear in the file named by argv[i], using kv as the key/value pair
        //    (call this result c)
        
        counts_t *c = countFile(argv[i], kv);
        if (c == NULL)
        {
            freeKVs(kv);
            return EXIT_FAILURE;
        }
        // compute the output file name from argv[i] (call this outName)
        char *outputName = computeOutputFileName(argv[i]);
        // open the file named by outName (call that f)
        FILE *f = fopen(outputName, "w+");
        if (!f)
        {
            freeKVs(kv);
            freeCounts(c);
            perror("Failed to open the file.");
            return EXIT_FAILURE;
        }
        // print the counts from c into the FILE f
        printCounts(c, f);
        // close f
        fclose(f);
        // free the memory for outName and c
        freeCounts(c);
        free(outputName);
    }

    // free the memory for kv
    freeKVs(kv);
    return EXIT_SUCCESS;
}
