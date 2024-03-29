#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct heap{
    long int * arr;
    long int capacity;
    long int elements;
}heap;

void hepify(heap* heap){
    for(int i=0;i<heap->elements;i++){
        int parent = heap->arr[(i-1)/2];
        if(parent>heap->arr[i]){
            int j=(i-1)/2;
            int factor=1;
            int k=i;
            do{
                if(heap->arr[j]<heap->arr[k]){
                    break;
                }
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

long long int heap_sum(heap* heap){
    long long int sum=0;
    for(int i=0;i<heap->elements;i++){
        sum+=heap->arr[i];
    }
    return sum;
}
int main(){
    long int num,*arr;
    heap* sandheap;
    scanf("%lld",&num);
    arr=(long int*)malloc(num*sizeof(long int));
    sandheap=(heap*)malloc(sizeof(heap));
    sandheap->elements=num;
    sandheap->capacity=(int)pow(2,(int)log2(num));
    for(int i=0;i<num;i++){
        scanf("%lld",arr+i);
    } 
    long long int sum;
    sandheap->arr=arr;
    hepify(sandheap);
    for(int i=0;i<num-1;i++){
        long long int min = del_min(sandheap); 
        long long int max = del_max(sandheap);
        add_elt(sandheap,max-min);
        sum=heap_sum(sandheap);
        printf("%lld\n",sum);
    }
    return 0;
}