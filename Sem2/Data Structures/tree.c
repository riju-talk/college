#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

typedef struct queue{
    tree** arr;
    int head;
    int tail;
    int size;
}queue;

tree* create(int data){
    tree* yes;
    yes=(tree*)malloc(sizeof(tree));
    yes->data=data;
    yes->left=NULL;
    yes->right=NULL;
    return yes;
}

queue* create_q(int size){
    queue* yes;
    yes=(queue*)malloc(sizeof(queue));
    yes->head=0;
    yes->tail=0;
    yes->size=size;
    yes->arr=(tree**)malloc(sizeof(size*sizeof(tree*)));
}

int is_full(queue* q){
    if((q->head+1)%q->size==q->tail){
        return 1;
    }
    else{
        return 0;
    }
}
int is_emp(queue* q){
    if(q->head==q->tail){
        return 1;
    }
    else{
        return 0;
    }
}
void enque(queue* list,tree* d){
    if(is_full(list)){
        return;
    }
    else{
        list->arr[list->head]=d;
        list->head=(list->head+1)%list->size;
    }
}

void deque(queue* list,tree* d){
    if(is_emp(list)){
        return;
    }
    else{
        list->tail=(list->tail+1)%list->size;
    }
}

tree* create_tree(int* data,int n){
    tree* n_root;
    queue* elts=create_q(n),queue, *emp=create_q(n);
}

void travel(tree* root){
    if(root!=NULL){
        travel(root->left);
        travel(root->right);
        printf("%d ",root->data);
    }
    else{
        return;
    }
}

void level_o_traversal(tree* root){

}
int main(){
    tree* root;
    tree* temp1;
    tree* temp2;
    root=create(4);
    root->left=create(7);
    root->right=create(8);
    temp1=root->left;
    temp2=root->right;
    temp1->left=create(9);
    temp1->right=create(10);
    temp2->left=create(11);
    temp2=temp1->left;
    temp2->left=create(12);
    temp2->right=create(13);
    travel(root);
    return 0;
}