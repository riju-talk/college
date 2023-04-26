#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list *pnext;
}list;

list* reverse(list *head){
    list *temp1;
    list *temp2;
    temp1=(list*)malloc(sizeof(list));
    temp2=(list*)malloc(sizeof(list));
    temp1=NULL;
    temp2=head->pnext;
    /*list *n_head;
    n_head=(list*)malloc(sizeof(list));*/
    while(temp2!=NULL){
        head->pnext=temp1;
        temp1=head;
        head=temp2;
        temp2=temp2->pnext;
    }
    head->pnext=temp1;
    return head;
}
int main(){
    list *head;
    head=NULL;
    head=(list*)malloc(sizeof(list));
    list *node1;
    node1=NULL;
    node1=(list*)malloc(sizeof(list));
    list *node2;
    node2=NULL;
    node2=(list*)malloc(sizeof(list));
    list *node3;
    node3=NULL;
    node3=(list*)malloc(sizeof(list));
    list *node4;
    node4=NULL;
    node4=(list*)malloc(sizeof(list));
    list *node5;
    node5=NULL;
    node5=(list*)malloc(sizeof(list));
    list *node6;
    node6=NULL;
    node6=(list*)malloc(sizeof(list));
    head->data=89;
    head->pnext=node1;
    node1->data=78;
    node1->pnext=node2;
    node2->data=69;
    node2->pnext=node3;
    node3->data=1900;
    node3->pnext=node4;
    node4->data=196;
    node4->pnext=node5;
    node5->data=14;
    node5->pnext=node6;
    node6->data=90;
    node6->pnext=NULL;
    for(list* i=head;i!=NULL;i=i->pnext){
        printf("%d",i->data);
        printf("->");
    }
    head = reverse(head);
    printf("\n");
    for(list* i=head;i!=NULL;i=i->pnext){
        printf("%d",i->data);
        printf("->");
    }
    return 0;
}