#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void loadhandler(FILE *file)
{
    char **array = NULL;
    char *line = NULL;
    size_t sz = 0;
    size_t count = 0;
    while (getline(&line, &sz, file) >= 0)
    {
        array = realloc(array, (count + 1) * sizeof(*array));
        array[count] = line;
        line = NULL;
        count++;
    }
    free(line);
    sortData(array, count);
    for (int i = 0; i < count; i++)
    {
        printf("%s", array[i]);
        free(array[i]);
    }
    free(array);
    
}

int main(int argc, char **argv)
{

    if (argc == 1)
    {
        loadhandler(stdin);
    }
    else if (argc > 1)
    {
        
        for (int i = 1; i<argc; i++)
        {
            FILE* file = fopen(argv[i],"r");
            if(!file){
                perror("failed to open the file.");
                return EXIT_FAILURE;
            }
            loadhandler(file);
	    if(fclose(file)!=0){
	        perror("failed to clode the file.");
	        return EXIT_FAILURE;
	    }
        }
    }

    return EXIT_SUCCESS;
}
