#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, colums, *fact, t_max, perry;
    scanf("%d%d", &rows, &colums);
    int **mat;
    mat = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        mat[i] = (int *)malloc(sizeof(int) * colums);
    }
    char c;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            scanf(" %c", &c);
            if (c == 'X')
            {
                mat[i][j] = 0;
            }
            else if (c == '.')
            {
                mat[i][j] = 1;
            }
        }
    }
    t_max = 0;
    fact = (int *)malloc(colums * sizeof(int));
    for (int i = 0; i < colums; i++)
    {
        fact[i] = 0;
    }
    for (int i = 0; i < rows; i++)
    {
        //------------------------------
        for (int k = 0; k < colums; k++)
        {
            if (mat[i][k] == 0)
            {
                fact[k] = 0;
            }
            else
            {
                fact[k] += mat[i][k];
            }
        }
        //-------------------------------
        int perimeter = 0;
        int max = 2 * fact[0] + 2 - 1;
        int hight;
        int width;
        for (int i = 0; i < colums; i++)
        {
            hight = fact[i];
            if (hight == 0)
            {
                continue;
            }
            for (int j = i; j < colums; j++)
            {
                width = (j - i + 1);
                if (fact[j] < hight && fact[j] != 0)
                {
                    hight = fact[j];
                }
                if (fact[j] == 0)
                {
                    break;
                }
                perimeter = 2 * width + 2 * hight - 1;
                if (perimeter > max)
                {
                    max = perimeter;
                }
            }
        }
        perry = max;
        if (t_max < perry)
        {
            t_max = perry;
        }
        //--------------------------------------------------
    }
    printf("%d", t_max);
    return 0;
}