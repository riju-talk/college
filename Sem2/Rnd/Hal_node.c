#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int data;
    struct tree* left;
    struct tree* right;

}tree;
 
tree *create(int data)
{
    tree *yes;
    yes = (tree *)malloc(sizeof(tree));
    yes->data = data;
    yes->left = NULL;
    yes->right = NULL;
    return yes;
}

int half_node(tree* root){
    if(root==NULL){
        return 0;
    }
    else if(root->left!=NULL && root->right==NULL || root->left==NULL && root->right!=NULL ){
        return 1;
    }
    else{
        return half_node(root->left) + half_node(root->right);
    }
}
int main(){
    tree *root;
    tree *temp1;
    tree *temp2;
    root = create(4);
    root->left = create(7);
    root->right = create(8);
    temp1 = root->left;
    temp2 = root->right;
    temp1->left = create(9);
    temp1->right = create(10);
    temp2->left = create(11);
    temp2 = temp1->left;
    temp2->left = create(12);
    printf("%d",half_node(root));
    return 0;
}