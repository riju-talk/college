#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int front;
    int back;
    int *elts;
    int size;

}queue;
typedef struct
{
    int size;
    queue** elements;
    queue* top;
    int top_ind;

} stack;
int main(){
    int q=0;
    scanf("%d",&q);
    stack *s;
    int op;
    s->elements=(queue*)malloc(sizeof(queue));
    s->elements=(queue*)realloc(s->elements,0*sizeof(queue));
    for(int i=0;i<q;i++){
        char string[20];
        scanf("%s%d",string,&op);
        int op;
        if(string=="Push"){
            int k=sizeof(s->elements)/sizeof(queue);
            s->elements=(queue*)realloc(s->elements,(k+1)*sizeof(queue));
            queue *l;
            l->elts[l->front]=op;
            l->front++;
            s->elements[s->top_ind]=l;
            s->top=l;
            s->top_ind++;
        }
        if(string=="Pop"){
            s->top=NULL;
            s->top_ind--;
        }
        if(string=="Enqueue"){
            
        }
    }   
    return 0;
    }