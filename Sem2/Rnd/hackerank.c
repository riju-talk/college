#include <stdio.h>
void merge(int A[],int B[],int l, int m, int h){
    int i=l,j=m,k=0;
    while(i<m && j<h){
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
    while(i<m){
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<h){
        B[k]=A[j];
        j++;
        k++;
    }
    for(int i=0;i<k;i++){
        A[l+i]=B[i];
    }
}
void sort(int A[],int B[], int l,int h){
    if(h-l<2){
        return;
    }
    else{
    int m=(h+l)/2;
    sort(A,B,l,m);
    sort(A,B,m,h);
    merge(A,B,l,m,h);
    }
}
int main()
{
    int cpy[10] = {1, 2, 4, 3};
    int arr[10];
    sort(cpy,arr,0,4);
    for(int i=0;i<4;i++){
        printf("%d ",cpy[i]);
    }
    return 0;
}
