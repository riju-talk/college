#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *node;
} list;

list* create(int data) {
    list* new = (list*) malloc(sizeof(list));
    new->data = data;
    new->node = NULL;
    return new;
}

list* append(list* head, int data) {
    list* y = head;
    while (y->node != NULL) {
        y = y->node;
    }
    y->node = create(data);
    return head;
}

list* insert(list* head,int data){
    list *k = create(data);
    k->node=head;
    head=k;
    return head;
}

list* enter(list* head,int data,int index){
    if(index<1){
        return insert(head,data);
    }
    else{
        int count=0;
        list* y=head,*z;
        while(count<index){
            
            y=y->node;
        }
    }
}
void traverse(list* h) {
    list* y;
    for (y = h; y != NULL; y = y->node) {
        printf("%d", y->data);
        printf("->");
    }
    printf("NULL");
}
int main() {
    list* head = create(12);
    head=append(head, 89);
    head=append(head, 90);
    traverse(head);
    head=insert(head, 178);
    printf("\n");
    traverse(head);
    return 0;
}
