#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int heap_size;
    int arr_size;
    int *arr;
}heap;

void min_elt(heap* elts){
    
}

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