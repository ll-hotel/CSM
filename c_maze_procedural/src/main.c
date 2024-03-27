#include <stdio.h>
#include <stdlib.h>
#define ML 90
#define MC 200

enum
{
    dead, alive
};

void print_matrix(char **m, const int ml, const int mc)
{
    for(int i = 0; i < mc+2; i++)
    {
        printf("--");
    }
    printf("\n");
    for(int i = 0; i < ml; i++)
    {
        printf("| ");
        for(int j = 0; j < mc; j++)
        {
            if(m + i*mc + j)
            {
                printf("\033[105m \033[0m");
            }
            else
            {
                printf("  ");
            }
        }
        printf(" |\n");
    }
    for(int i = 0; i < mc+2; i++)
    {
        printf("--");
    }
    printf("\n");
}

int	main(void)
{
    char matrix[ML][MC] = {dead};
    print_matrix(matrix, ML, MC);


    return 0;
}