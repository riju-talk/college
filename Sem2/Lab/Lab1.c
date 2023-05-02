#include<stdio.h>
#include<stdlib.h>


typedef struct directory
{
    char *name;
    struct directory* next;
    struct directory* parent;
    struct directory* child;  
}directory;

main(){

    directory* root;
    root=(directory*)malloc(sizeof(directory));
    root->name="root";
    root->parent=NULL;
    root->next=NULL;
    root->child=NULL;

    int q;
    scanf("%d",&q);
    directory* master_temp;
    master_temp=root;
    while(q>0){
        int n;
        scanf("%d",&n);
        if(n==1){
            char *g;
            scanf("%s",g);
            if(g=="ls"){
                directory* temp;
                temp=master_temp;
                while(temp!=NULL){
                    printf("%s",temp->name);
                    printf(" ");
                }
            }
            else if(g=="pwd"){
                directory* temp;
                temp=root;
                while(temp!=master_temp){
                    printf("%s",temp->child);
                    if(temp->child!=NULL){
                        printf("/");
                    }
                }
            }
        }
        else if(n==2){
            char *g;
            char *h;
            scanf("%s",g);
            scanf("%s",h);
            if(g=="cd"){
                
            }
        }
        else if(n==3){

        }
    }
    return 0;
}