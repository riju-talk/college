#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list* pnext;
} list;

list* create(int data) {
    list* node = (list*)malloc(sizeof(list));
    node->data = data;
    node->pnext = NULL;
    return node;
}

void add(list** phead, int data) {
    if (*phead == NULL) {
        *phead = create(data);
    } else {
        list* temp = *phead;
        while (temp->pnext != NULL) {
            temp = temp->pnext;
        }
        temp->pnext = create(data);
    }
}

void reverse(list** head){
    list *current, *prev, *next, *iterator;
    iterator=*head;
    prev=iterator;
    current=iterator->pnext;
    next=iterator->pnext->pnext;
    while(next!=NULL){
        
    }
}

int main() {
    list* start = NULL;
    int temp1;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &temp1);
        add(&start, temp1);
    }
    list* temp = start;
    while (temp != NULL) {
        printf("%d", temp->data);
        printf("->");
        temp = temp->pnext;
    }
    return 0;
}
