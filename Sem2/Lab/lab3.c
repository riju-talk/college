#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree* right;
    struct tree* left;
    struct tree* parent;
}tree;


void createtree(tree* root,int* arr,int n){
    tree** arrtree;
    tree** emp;
    int level=0;
    int i=0;
    arrtree=(tree**)malloc((2*n-1)*sizeof(tree*));
    emp=(tree**)malloc((2*n-1)*sizeof(tree*));
    for(int j=0;j<(2*n-1);j++){
        arrtree[j]=(tree*)malloc((2*n-1)*sizeof(tree));
        emp[j]=(tree*)malloc((2*n-1)*sizeof(tree));
    }
    while(i<(2*n-1)){
        tree* temp;

        while(i<(2*level)){
        }
        level++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(sizeof(int)*(2*n-1));
    for(int i=0;i<(2*n-1);i++){
        scanf("%d ",&ptr[i]);
    }

    return 0;
}