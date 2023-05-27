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
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
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
int get_height(avl* root){
    int temp;
    if(root==NULL){
        return 0;
    }
    return root->height;
}

avl* right_right(avl* root){
    avl *temp1,*temp2;
    temp1=root->left;
    temp2=temp1->right;

    root->left=temp2;
    temp1->right=root;

    root->height=max(get_height(root->left),get_height(root->right)) + 1;
    temp1->height=max(get_height(temp1->left),get_height(temp2->right)) + 1;
    return temp1;
}

avl* left_left(avl* root){
    avl *temp1,*temp2;
    temp1=root->right;
    temp2=temp1->left;
    
    root->right=temp2;
    temp1->left=root;

    root->height=max(get_height(root->left),get_height(root->right)) + 1;
    temp1->height=max(get_height(temp1->left),get_height(temp2->right)) + 1;
    return temp1;
}

int balancefactor(avl* root){
    if(root!=NULL){
        return get_height(root->right) - get_height(root->left);
    }
    else{
        return 0;
    }
}

avl* insert(avl* root, int data){
    if(root==NULL){
        root = create(data);
        return root;
    }
    else{
        avl *temp=root;
        if(data>root->data){
            root->right=insert(root->right,data);
        }
        else if(data<root->data){
            root->left=insert(root->left,data);
        }
    }
    root->height=1+max(get_height(root->left),get_height(root->right));
}
  
avl* rotate(avl* root,int left, int right){  
    int factor = balancefactor(root);
    // left left case
    if(factor<-1 && root->data > root->right->data){
        root=left_left(root);
        left++;
    }
    // left right case
    if(factor<-1 && root->data < root->left->data){
        root->left=left_left(root->left);
        root=right_right(root);
        left++;
        right++;
    }
    // right left case
    if(factor>1 && root->data > root->left->data){
        root->right=right_right(root->left);
        root=left_left(root);
        left++;
        right++;
    }
    // right right case
    if(factor>1 && root->data < root->left->data){
        root=right_right(root);
        right++;
    }
    return root;
}

avl* search(avl* root,int x){
    avl* temp;
    temp=root;
    while(1){
        if(root->data>x){
            temp=temp->right;
        }
        else if(root->data>x){
            temp=temp->left;
        }
        if(root->data==x){
            return temp;
        }
    }

}


int sum(avl*root){
    if(root==NULL){
        return 0;
    }
    else{
        return root->data+sum(root->left)+sum(root->right);
    }
}
void sumtree(avl*root,int x){
    avl* temp = search(root,x);
    if(temp!=NULL){
        printf("%d\n",sum(temp));
    }
    else{
        printf("NA\n");
    }
}
int main(){
    int num;
    avl* root=NULL;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        char * string;
        string=(char*)malloc(7*sizeof(char));
        int fact;
        scanf("%s %d",string,&fact);
        if(strcmp(string,"insert")==0){
            int left=0;
            int right=0;
            root=insert(root,fact);
            rotate(root,left,right);
        }
        else if (strcmp(string,"subtree")==0)
        {
            sumtree(root,fact);
        }
        
    }
    return 0;
}