#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int data;
    int quant;
    struct bst* left;
    struct bst* right;
}bst;
void insert(bst** root, int data){
    
    if(root==NULL){
        *root = create(data);
        return;
    }
    else{
        if(data>(*root)->data){
            insert((*root)->left,data);
        }
        else if(data<(*root)->data){
            insert((*root)->left,data);
        }
        else if (data==(*root)->data)
        {
            (*root)->quant++;
        }
        
    }
    return (*root);
}

int del_min(bst* root){
    bst* temp=NULL;
    while(root!=NULL){
        temp=root;
        root=root->right;
    }
    if(root->quant>1){
        root->quant--;
    }
    else{
        temp=NULL;
    }
    return root->data;
}

int del_max(bst* root){
    bst* temp=NULL;
    while(root!=NULL){
        temp=root;
        root=root->left;
    }
    if(root->quant>1){
        root->quant--;
    }
    else{
        temp=NULL;
    }
    return root->data;
}
int main(){
    int num,*arr,imm_len;
    bst* tree;
    tree=(bst*)malloc(sizeof(bst));
    scanf("%d",&num);
    arr=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",arr+i);
    }
    for(int i=0;i<num;i++){
        insert(tree,arr[i]);
    }
    imm_len=num;
    for(int i=0;i<num-1;i++){
        int min=del_min(tree);
        int max=del_max(tree);
        insert(tree,max-min);
        
    }
    return 0;
}