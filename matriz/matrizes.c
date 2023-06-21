#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int x[7][8];
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 8; j++)
        {
            x[i][j] = 1;
            if (x[i][j] == x[j][i])
            {
                x[i][j] = 0;
            }
            printf("%d", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}