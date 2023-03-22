#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_mat(int** mat,int rows,int colums){
    for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
int cost(int** first,int**second){
    int cost=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cost+=abs(first[i][j]-second[i][j]);
        }
    }
    return cost;
}
void push(int** mat,int* arr,int n,int m){
    for(int i=0;i<n;i++){
        mat[m][i]=arr[i];
    }
}
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int if_ms(int* mat) {
    int* fact;
    fact = (int*)malloc(8 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        int cost = 0;
        for (int j = 0; j < 3; j++) {
            cost += *(mat + i * 3 + j);
        }
        fact[i] = cost;
    }
    for (int i = 0; i < 3; i++) {
        int cost = 0;
        for (int j = 0; j < 3; j++) {
            cost += *(mat + j * 3 + i);
        }
        fact[i + 3] = cost;
    }
    int cost = 0;
    for (int i = 0; i < 3; i++) {
        cost += *(mat + i * 3 + i);
    }
    fact[6] = cost;
    cost = 0;
    for (int i = 0; i < 3; i++) {
        cost += *(mat + (2 - i) * 3 + 2 - i);
    }
    fact[7] = cost;
    int test = fact[0];
    for (int i = 1; i < 8; i++) {
        if (fact[i] != test) {
            free(fact);
            return 0;
        }
    }
    free(fact);
    return 1;
}
int** m_square(int* arr){
    int** mat=(int**)malloc(3*sizeof(int*));
    if(if_ms(arr)){
        for(int i=0;i<3;i++){
            mat[i]=(int*)malloc(3*sizeof(int));
            for(int j=0;j<3;j++){
                mat[i][j]=*(arr+i*3+j);
            }
        }
    }
    return mat;
}
void comb(int* arr,int l, int r,int** mat,int* index){
    if(l==r){
        if(if_ms(arr)){
            mat[*index]=(int*)malloc(9*sizeof(int));
            push(mat,arr,9,*index);
            (*index)++;
        }
    }
    else{
        for(int i=l;i<r;i++){
            swap(&arr[l],&arr[i]);
            comb(arr,l+1,r,mat,index);
            swap(&arr[l],&arr[i]);
        }
    } 
}
int main(){
    int* ar=(int*)malloc(9*sizeof(int));
    for(int i=0;i<9;i++){
        ar[i]=i+1;
    }
    int** mat;
    mat=(int**)malloc(9*sizeof(int*));
    int index=0;
    comb(ar,0,9,mat,&index);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}