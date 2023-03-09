#include<stdio.h>
#include<stdlib.h>
#define MAX 10


int main(){
    int key,n;
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    //*************search algo****************
    scanf("%d",&key);
    while(n==1){
        int f=n/2,g;
        g=arr[f];
        if(key<g){
            n=f;
            arr=realloc(arr,n*sizeof(int));
            for(int k==1)
        }
        else if(key>g){
            n=n-f;
            arr=realloc(arr,n*sizeof(int));
        }
    }


    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    } 
    return 0;
}