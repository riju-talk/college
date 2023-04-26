#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, *arr, rohu = 0, ishu = 0, max, head, max_ind, start = 0;
    scanf("%d%d", &n, &k);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    head = 0;
    while (n >= k)
    {
        max = arr[start];
        for (int i = start; i < (k + start); i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        if (head == 0)
        {
            ishu += max;
        }
        else
        {
            rohu += max;
        }
        head = !head;
        start++;
        n--;
    }
    free(arr);
    //----------------------------------------------------
    if (rohu > ishu)
    {
        printf("rohu");
    }
    else if (ishu > rohu)
    {
        printf("ishu");
    }
    else
    {
        printf("draw");
    }
    return 0;
}
