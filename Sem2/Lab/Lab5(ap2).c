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
    max = arr[0];
    max_ind = 0;
    for (int i = 1; i < k; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_ind = i;
        }
    }
    for (int i = 0; i <= n - k; i++)
    {
        if (max_ind < i)
        {
            max = arr[i];
            max_ind = i;
            for (int j = i + 1; j < i + k; j++)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                    max_ind = j;
                }
            }
        }
        else if (arr[i + k - 1] > max)
        {
            max = arr[i + k - 1];
            max_ind = i + k - 1;
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
    }
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
