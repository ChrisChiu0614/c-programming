void rotate(char matrix[10][10])
{
    int size = 10;
    char result[size][size];
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            result[j][size - i - 1] = matrix[i][j];
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matrix[i][j] = result[i][j];
        }
    }
    
}
