#include<stdio.h>
#include<stdlib.h>

void create(int* S,int total){
    for(int i=0;i<=total;i++){
        S[i]=i;
    }
}

int find(int* S,int data, int total){
    if(S[data]==data){
        return data;
    }
    else if(data>total || data<0){
        return -1;
    }
    else{
        return find(S,S[data],total);
    }
}

void union_set(int* S,int set1, int set2,int total){
    if(find(S,set1,total)==find(S,set2,total)){
        return;
    }
    if((set1<0 && set1>total) && (set2<0 && set2>total)){
        return;
    }
    S[set2]=set1;
}

int main(){
    int V, E;
    int* set,*parents;
    int parent=0;
    set=(int*)malloc(sizeof(int)*(V+1));
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        union_set(set,x,y,V+1);
    }
    for(int i=0;i<V+1;i++){
        parent=parent^find(set,i,V+1);
    }
    if(parent==0){
        printf("Yes");
    }
    else{
        printf("NO");
    }
    return 0;
}