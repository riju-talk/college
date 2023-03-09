#include<stdio.h>
#include<stdlib.h>

void sort(int* arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}

int main(){
    int* arr;
    arr= (int*)malloc(7*sizeof(int));
    for(int i=0;i<7;i++){
        scanf("%d",&arr[i]);
    }
    int m=7;
    sort(arr,m);
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}