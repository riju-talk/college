#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    list *node;
}list;

list create(int data){   
    list* new;
    new->data=data;
    new->node=NULL;
    return *new;
}
void append(list*head,int data){
    list* y;
    for(;y!=NULL;y=y->node){
        if(y->node==NULL){
            y->node=create(data);
        }       
    }
}
void traverse(list*h){
    list* y;
    for(;y!=NULL;y=y->node){
        printf("%d",y->data);
        printf("->");   
    }
}
int main(){
    list* head;
    head->data=12;
    head->node=NULL;
    return 0;
}