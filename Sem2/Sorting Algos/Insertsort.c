#include<stdio.h>
void sort(int A[],int n){
    for(int i=1;i<=n;i++){
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
int main(){
    int A[]={4,4,5,3,194,194,0,-14,48,1,4,14,9};
    sort(A,13);
    for(int i=0;i<13;i++){
        printf("%d ",A[i]);
    }
    return 0;
}