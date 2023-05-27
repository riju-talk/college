#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct heap{
    int * arr;
    int capacity;
    int elements;
}heap;

void hepify(heap* heap){
    for(int i=0;i<heap->elements;i++){
        int parent = heap->arr[(i-1)/2];
        if(parent>heap->arr[i]){
            int j=(i-1)/2;
            int factor=1;
            int k=i;
            do{
                int temp;
                temp=heap->arr[j];
                heap->arr[j]=heap->arr[k];
                heap->arr[k]=temp;
                k=j;
                factor=j-1;
                j=(j-1)/2;
            }while(j>=0 && factor>=0);
        }
    }
}


long int del_min(heap* heap){
    long int temp=heap->arr[0];
    heap->arr[0]=heap->arr[heap->elements-1];
    heap->elements--;
    hepify(heap);
    return temp;
}

long int del_max(heap* heap){
    long int max=heap->arr[0];
    int k;
    for(int i=0;i<heap->elements;i++){
        if(heap->arr[i]>max){
            max=heap->arr[i];
            k=i;
        }
    }
    for(int i=k+1;i<heap->elements;i++){
        heap->arr[i-1]=heap->arr[i];
    }
    heap->elements--;
    return max;
}

void add_elt(heap* heap,int data){
    heap->arr[heap->elements]=data;
    heap->elements++;
    hepify(heap);
}
int main(){
    heap* sandheap;
    sandheap=(heap*)malloc(sizeof(heap));
    sandheap->arr=(int*)malloc(sizeof(int)*4);
    sandheap->elements=3;
    sandheap->capacity=8;
    for(int i=0;i<3;i++){
        scanf("%d",&sandheap->arr[i]);
    }
    hepify(sandheap);
    for(int i=0;i<sandheap->elements;i++){
        printf("%d ",sandheap->arr[i]);
    }
    add_elt(sandheap,2);
    printf("\n");
    for(int i=0;i<sandheap->elements;i++){
        printf("%d ",sandheap->arr[i]);
    }
    return 0;
}