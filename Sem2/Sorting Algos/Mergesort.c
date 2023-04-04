#include<stdio.h>
void merge(int A[],int B[],int l1, int h1,int l2, int h2){
    int i=l1,j=l2,k=0;
    while(i<h1 && j<h2){
        if(A[i]>A[j]){
            B[k]=A[j];
            j++;
        }
        else
        {
            B[k]=A[i];
            i++;
        }
        k++;
    }
    while(i<h1){
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<h2){
        B[k]=A[j];
        j++;
        k++;
    }
    for(int i=0;i<k;i++){
        A[l1+i]=B[i];
    }
}
void mergesort(int A[],int B[], int l,int h){
    if(h-l<2){
        return;
    }
    else{
    int m=(h+l)/2;
    mergesort(A,B,l,m);
    mergesort(A,B,m,h);
    merge(A,B,l,m,m,h);
    }
}
int main()
{
    int cpy[10] = {1, 2, 4, 3};
    int arr[10];
    mergesort(cpy,arr,0,4);
    for(int i=0;i<4;i++){
        printf("%d ",cpy[i]);
    }
    return 0;
}