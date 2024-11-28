#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix[10][10])
{
    char temp[10][10] = {0};
    // rotate
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            temp[j][10 - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}
void printError(const char *msg, FILE *file)
{
    fprintf(stderr, "Error: %s\n", msg);
    if (file != NULL)
    {
        fclose(file);
    }
}

void read_matrix(char matrix[10][10], char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file==NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int rows = 0, columns = 0;
    int c;

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            if (columns < 10)
            {
                printError("Columns are too short in this row", file);
                exit(EXIT_FAILURE);
            }
            else
            {
                columns = 0;
                rows++;
                continue;
            }
        }
        else
        {
            if (columns >= 10)
            {
                printError("Too many characters in a row", file);
                exit(EXIT_FAILURE);
            }
            if (rows >= 10)
            {
                printError("Too many rows in the file", file);
                exit(EXIT_FAILURE);
            }
            matrix[rows][columns] = c;
            columns++;
        }
    }
    // Validate the number of rows and columns after reading
    if (rows < 10)
    {
        printError("File has too few rows", file);
        exit(EXIT_FAILURE);
    }
    if (columns != 0)
    {
        printError("Last row is incomplete", file);
        exit(EXIT_FAILURE);
    }

    if (fclose(file) != 0)
    {
        perror("Failed to close the file");
        exit(EXIT_FAILURE);
    }
}

void print_matrix(char matrix[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments\n");
        exit(EXIT_FAILURE);
    }

    char matrix[10][10]={0};
    read_matrix(matrix, argv[1]);
    rotate(matrix);
    print_matrix(matrix);
}
