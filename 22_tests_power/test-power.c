#include<stdlib.h>
#include<stdio.h>


unsigned power(unsigned x, unsigned y);

int main()
{
    typedef struct param_tag
    {
        unsigned x;
        unsigned y;
        unsigned expected;
    } param_t;

    size_t size = 7;
    param_t param[] = {
        {.x = 0, .y = 0, .expected = 1},
        {.x = 1, .y = -1, .expected = 1},
        {.x = -2, .y = 0, .expected = 1},
        {.x = -2, .y = 2, .expected = 4},
        {.x = -2, .y = 3, .expected = -8},
        {.x = 0, .y = -1, .expected = 0},
        {.x = -1, .y = -1, .expected = -1},

    };

    for (int i = 0; i < size; i++)
    {
         printf("For x=%d, y=%d, expected %d, got %d\n",
		param[i].x,param[i].y,param[i].expected,(int)power(param[i].x,param[i].y));
         if(power(param[i].x, param[i].y)!=param[i].expected){
            return EXIT_FAILURE;
         }
    }

    return EXIT_SUCCESS;
}

