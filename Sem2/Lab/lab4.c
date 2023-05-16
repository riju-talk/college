#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct avl{
    int height;
    int data;
    struct avl* left;
    struct avl* right;
}avl;

avl* create(int data){
    avl* temp;
    temp=(avl*)malloc(sizeof(avl));
    temp->data=data;
    temp->height=0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int height(avl* root){
    int temp;
    if(root->left!=NULL && root->right!=NULL){
        return 0;
    }
    else{
        return 1 + max(height(root->left),height(root->right));
    }
}

void insert(avl* root, int data){
    if(root==NULL){
        root=create(data);
        root->height=0;
    }
    else{
        avl* temp=root;
        avl* temp_parent=NULL;
        while(temp!=NULL){
            temp_parent=temp;
            if(data > temp->data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        temp=create(data);
        if((temp_parent->left==temp || temp_parent->right==NULL) || (temp_parent->left==temp || temp_parent->right==NULL))
        {
            temp_parent->height=1+
        }
        temp->height=height(temp)
    }
}
int main(){

    return 0;
}