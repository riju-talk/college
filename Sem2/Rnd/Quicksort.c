#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int l, int h)
{
    int c = arr[l];
    int i = l + 1, j = h;
    do{
        while (arr[i]<c)
        {
            i++;
        }
        while (arr[j]>=c)
        {
            j--;
        }
        if (j > i)
        {
            swap(&arr[i], &arr[j]);
        }
    }while (j > i);
    swap(&arr[l], &arr[j]);
    return j;
}
void sort(int *arr, int l, int h)
{
    if (l >= h)
    {
        return;
    }
    else
    {
        int part;
        part = partition(arr, l, h);
        sort(arr, l, part - 1);
        sort(arr, part + 1, h);
    }
}

void print_ar(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int d[] = {9, 8, 13, 67, 100, 34, 2, 0, 3, 4, 3};
    int *ptr;
    ptr = (int *)malloc(11 * sizeof(int));
    for (int i = 0; i < 11; i++)
    {
        ptr[i] = d[i];
    }
    print_ar(ptr, 11);
    sort(ptr, 0, 10);
    printf("\n");
    print_ar(ptr, 11);
    return 0;
}