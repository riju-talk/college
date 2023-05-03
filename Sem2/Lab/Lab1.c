#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct directory
{
    char *name;
    struct directory* next;
    struct directory* parent;
    struct directory* child;  
}directory;

int main(){
    directory* root;
    root=(directory*)malloc(sizeof(directory));
    root->child=NULL;
    root->parent=NULL;
    root->next=NULL;
    root->name=(char*)malloc(5*sizeof(char));
    root->name="root";
    int q;
    scanf("%d",&q);
    directory* master_temp;
    master_temp=root;
    while(q>0){
        int n;
        scanf("%d",&n);
        if(n==1){
            char *g;
            g=(char*)malloc(20*sizeof(char));
            scanf("%s",g);
            g=(char*)realloc(g,strlen(g)+1);
            if(strcmp(g,"ls")==0){
                directory* temp;
                while(temp!=NULL){
                    printf("%s",temp->name);
                    printf(" ");
                }
            }
            else if(strcmp(g,"pwd")==0){
                directory* temp;
                temp=root;
                while(temp!=master_temp){
                    printf("%s",temp->name);
                    if(temp->child!=NULL){
                        printf("/");
                    }
                    temp=temp->child;
                }
                printf("%s",temp->name);
            }
        }
        /*else if(n==2){
            char *g;
            char *h;

            scanf("%s %s",g,h);
            if(g=="cd"){
                if(h==".."){
                    master_temp=master_temp->parent;
                }
                else{
                    master_temp=master_temp->parent;
                    directory* temp;
                    for(temp=master_temp;temp=temp->next;temp!=NULL){
                        if(temp->name==h){
                            master_temp=temp;
                            break;
                        }
                    }
                    if(temp==NULL){
                        printf("-1");
                    }
                }
            }
            else if(g=="mkdir"){
                directory* temp2;
                temp2=(directory*)malloc(sizeof(directory));
                temp2->name=h;
                temp2->parent=master_temp;
                temp2->next=NULL;
                if(master_temp->child==NULL){
                    master_temp->child=temp2;
                }
                else{
                    int flag=0;
                    directory* temp1;
                    temp1= master_temp->child;
                    while(temp1->child!=NULL){
                        if(temp1->child->name==h){
                            printf("-1");
                            break;
                        }
                        temp1=temp1->child;
                    }
                    if(flag==1){
                    temp1->next=temp2;
                    }
                }
            }
        }
        else if(n==3){
            char *entry1;
            char *entry2;
            char *entry3;
            scanf("%s %s %s",entry1,entry2,entry3);
            directory *temp;
            temp=master_temp;
            int flag=0;
            while(temp!=NULL){
                if(temp->name==entry3){
                    directory* temp1;
                    directory* temp2;
                    temp1=temp->next;
                    temp2=temp;
                    temp=temp->parent;
                    temp->child=temp1;
                    free(temp2);
                    flag=1;
                }
                temp=temp->next;
            }
            if(flag==0){
                printf("-1");
            }
        }*/
        q--;
    }
    return 0;
}