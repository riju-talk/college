#include<stdio.h>
#include<stdlib.h>

// implmenting sets
/*
let S = {0,1,2,3,4,5,6,7}
here indexes are elements and values are parents


let initially S = {0,1,2,3,4,5,6,7}
0 is elt of 0
1 is elt of 1

let heirarchy 2->3->4
3 is a parent of four and 2 is parent of 4
S = {0,1,2,2,3,5,6,7}

let another heirarchy be 5->6
S = {0,1,2,2,3,5,5,7}
union 3->5
S = {0,1,2,2,3,2,5,7}
*/

void create(int* S,int total){
    for(int i=0;i<total;i++){
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
    int* Set;
    int total=7;
    Set=(int*)malloc(sizeof(int)*total+1);
    create(Set,total+1);
    for(int i=0;i<total+1;i++){
        printf("%d ",Set[i]);
    }
    int x = find(Set,7,total),y = find(Set,8,total);
    printf("\n%d %d",x,y);
    union_set(Set,2,3,total);
    union_set(Set,3,4,total);
    printf("\n");
    for(int i=0;i<total+1;i++){
        printf("%d ",Set[i]);
    }
    union_set(Set,5,6,total);
    printf("\n");
    for(int i=0;i<total+1;i++){
        printf("%d ",Set[i]);
    }
    union_set(Set,2,5,total);
    printf("\n");
    for(int i=0;i<total+1;i++){
        printf("%d ",Set[i]);
    }
    return 0;
}