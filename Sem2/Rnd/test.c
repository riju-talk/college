#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void push(int** mat,int* arr,int n,int m){
    for(int i=0;i<n;i++){
        mat[m][i]=arr[i];
    }
}

void comb(int* arr,int l, int r,int** mat,int* index){
    if(l==r){
        push(mat,arr,r,*index);
        (*index)++;
    }
    else{
        for(int i=l;i<r;i++){
            swap(&arr[l],&arr[i]);
            comb(arr,l+1,r,mat,index);
            swap(&arr[l],&arr[i]);
        }
    } 
}

int factorial(int c){
    int prod=1;
    for(int i=1;i<=c;i++){
        prod*=i;
    }
    return prod;
}

int** perm(int* arr,int n){
    int** mat;
    int index=0;
    mat=(int**)malloc(factorial(n)*sizeof(int*));
    for(int i=0;i<factorial(n);i++){
        mat[i]=(int*)malloc(n*sizeof(int));
    }
    comb(arr,0,n,mat,&index);
    return mat;
}

int main() 
{
    int* arr;
    arr=(int*)malloc(3*sizeof(int));
    for(int i=0;i<3;i++){
        arr[i]=i+1;
    }
    int** mat;
    mat=perm(arr,3);
    for(int i=0;i<factorial(3);i++){
        for(int j=0;j<3;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
