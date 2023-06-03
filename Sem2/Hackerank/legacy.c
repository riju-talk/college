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

int deque(queue* verts){
    if(!isempty(verts)){
        int temp=verts->elts[verts->tail];
        verts->tail++;
        verts->size--;
        return temp;
    }
    return -1;
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

typedef struct graph{
    int **matrix;
    int V;
    int E;
    int h_weight;
    int dim;
}graph;

graph* create_g(int V,int E){
    graph *temp;
    temp=(graph*)malloc(sizeof(graph));
    temp->V=V;
    temp->E=E;
    temp->matrix=(int**)malloc(sizeof(int*)*V);
    for(int i=0;i<V;i++){
        temp->matrix[i]=(int*)malloc(sizeof(int)*V);
        for(int j=0;j<V;j++){
            temp->matrix[i][j]=0;
        }
    }
    temp->h_weight=0;
    temp->dim=V;
    return temp;
}

void make_edge(graph* g,int i,int j){
    int old_dim=g->dim;
    if(i>g->h_weight){
        g->h_weight=i;
    }
    else if(j>g->h_weight){
        g->h_weight=j;
    }
    if(g->h_weight>=g->V){
        int n_dim=g->h_weight+1;
        int **mat=(int**)malloc(sizeof(int*)*n_dim);
        for(int i=0;i<n_dim;i++){
            mat[i]=(int*)malloc(sizeof(int)*n_dim);
            for(int j=0;j<n_dim;j++){
                mat[i][j]=0;
            }
        }
        for(int i=0;i<old_dim;i++){
            for(int j=0;j<old_dim;j++){
                mat[i][j]=g->matrix[i][j];
            }
        }
        g->matrix=mat;
        g->dim=n_dim;
    }
    g->matrix[i][j]=1;
}

void bfs(graph* proxy, queue* visit, queue* explore, int *explored){
    // explored {0,0,0,0}
    int i=0;
    enque(visit,i);
    enque(explore,i);
    explored[0]=1;
    while(!isempty(visit)){
        int interm=deque(visit);
        for(int j=0;j<proxy->dim;j++){
            if(proxy->matrix[interm][j]==1 && explored[j]==0){
                enque(visit,j);
                enque(explore,j);  
                explored[j]=1;
            }
        }
    }
}
int main()
{
    // rows are source
    // colums are destination
    int v=6,e=7;
    graph* maki;
    maki=create_g(v,e);
    queue* visited,*visting;
    visited=create(v);
    visting=create(v);
    /*for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",maki->matrix[i][j]);
        }
        printf("\n");
    }*/
    make_edge(maki,0,1);
    make_edge(maki,0,2);
    make_edge(maki,0,3);
    make_edge(maki,1,3);
    make_edge(maki,2,3);
    make_edge(maki,2,4);
    make_edge(maki,2,6);
    /*for(int i=0;i<maki->h_weight+1;i++){
        for(int j=0;j<maki->h_weight+1;j++){
            printf("%d ",maki->matrix[i][j]);
        }
        printf("\n");
    }*/
    int *explored;
    explored=(int*)malloc(sizeof(int)*maki->dim);
    for(int i=0;i<maki->dim;i++){
        explored[i]=0;
    }
    bfs(maki,visting,visited,explored);
    for(int i=0;i<v;i++){
        printf("%d ",visited->elts[i]);
    }
    return 0;
}
