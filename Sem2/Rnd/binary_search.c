#include<stdio.h>
#include<stdlib.h>
#define MAX 10

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

int bin_search(int* arr,int n,int key){
    int ll=0, hl=n-1;
    int i=0;
    while(ll<=hl){
    int f=(hl+ll)/2;
    if(key==arr[f]){
        return f;
    }
    else if(key>arr[f]){
        ll=f+1;
    }
    else if(key<arr[f]){ 
        hl=f-1;
    }
    i++;
    }
    return -1;
}

int main(){
    int key,n,g;
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    //*************search algo****************
    scanf("%d",&key);
    sort(arr,n);
    int var=bin_search(arr,n,key);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    printf("\nThe index of %d is %d",key,var);
    //printf("\n%d",g); 
    return 0;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // If element not found
}




