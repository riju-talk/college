#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort1(int n, int arr_count, int* arr) {
    int j,key;
    for(int i=1;i<arr_count;i++){
        if(arr[i]<arr[i-1]){
            key=arr[i];
            j=i;
            while(j>0 && key<arr[j-1]){
                arr[j]=arr[j-1];
                for(int k=0;k<n;k++){
                    printf("%d ",arr[k]);
                }
                printf("\n");
                j--;
            }
            arr[j]=key;
            for(int k=0;k<n;k++){
                printf("%d ",arr[k]);
            }
        }
    }
}

int main()
{
    int a[5]={2,4,6,8,3};
    insertionSort1(5,5,a);
    return 0;
}
