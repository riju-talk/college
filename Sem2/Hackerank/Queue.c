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


typedef struct queue{
    int *elts;
    int head;
    int tail;
    int size;
    int capacity;
}queue;

int isempty(queue* verts){
    if(0==verts->size){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(queue* verts){
    if(verts->capacity==verts->size){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(queue* verts,int data){
    if(isfull(verts)){
        return;
    }
    else{
        verts->elts[verts->head]=data;
        verts->size++;
        verts->head++;
    }
}

void deque(queue* verts){
    if(isempty(verts)){
        return;
    }
    else{
        verts->tail++;
        verts->size--;
    }
}

queue* create(int capacity){
    queue* q;
    q=(queue*)malloc(sizeof(queue));
    q->elts=(int*)malloc(sizeof(int)*capacity);
    q->capacity=capacity;
    q->size=0;
    q->head=0;
    q->tail=0;
    return q;
}

void printq(queue* elet){
    for(int i=elet->tail;i!=elet->head;i=(i+1)%elet->capacity){
        printf("%d ",elet->elts[i]);
    }
}

int main(){
    
    return 0;
}
