#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char *computeOutputFileName(const char *inputName)
{
    if (strlen(inputName) <= 0)
    {
        return NULL;
    }

    char *outputName = malloc(strlen(inputName) + 9 * sizeof(*outputName));

    strcpy(outputName, inputName);
    strcat(outputName, ".counts");

    return outputName;
}
