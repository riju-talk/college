#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int size;
    int *arr;
}heap;


int main(){
    int n,tu;
    scanf("%d %d",&n,&tu);
    int *arr;
    arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        printf("\n");
    }
    return 0;
}