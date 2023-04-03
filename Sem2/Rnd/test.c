#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int bruh(int arr[], int cmp[], int index, int lencmp){
    if(lencmp <= index){
        return 0;
    }
    else{
        if(arr[index] == cmp[index]){
            return bruh(arr, cmp, index + 1, lencmp);
        }
        else{
            int j = index;
            while(j<lencmp){
                if(arr[j]!=cmp[j]){
                    swap(&arr[index], &arr[j]);
                    j++;
                }
                else{
                    break;
                }
            }
            return 1 + bruh(arr, cmp, index + 1, lencmp);
        }
    }
}

int main() 
{
    int arr[]={5,1,10,7,2};
    int cmp[]={1,2,5,7,10};
    int *fish=0;
    int k=bruh(arr,cmp,0,5);
    printf("%d",k);
    return 0;
}
