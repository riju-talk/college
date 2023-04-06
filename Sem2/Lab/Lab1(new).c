#include<stdio.h>

typedef struct{
    int data;
    int index;
} record;
void merge(record A[],record B[],int l,int m,int h){
    int i=l,j=m,k=0;
    while(i<m && j<h){
        if(A[i].data<A[j].data){
            B[k].data=A[i].data;
            B[k].index=A[i].index;
            i++;
        }
        else{
            B[k].data=A[j].data;
            B[k].index=A[j].index;
            j++;
        }        
        k++;
    }
    while(i<m){
        B[k].data=A[i].data;
        B[k].index=A[i].index;
        i++;
        k++;
    }
    while(j<h){
        B[k].data=A[j].data;
        B[k].index=A[j].index;
        j++;
        k++;
    }
    for(int i=0;i<k;i++){
        A[l+i].data=B[i].data;
        A[l+i].index=B[i].index;
    }
}
void sort(record A[],record B[],int l,int h){
    if(h-l<2){
        return;
    }
    else{
        int m=(l+h)/2;
        sort(A,B,l,m);
        sort(A,B,m,h);
        merge(A,B,l,m,h);
    }
}

int search(int arr[], int n, int x, int i) {
    int left = i;
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
int main(){
    int num,swaps=0;
    int arr[1000];
    record rubbish[1000],cpy[1000],emp[1000];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++){
        rubbish[i].data=arr[i];
        rubbish[i].index=i;
    }
    for(int i=0;i<num;i++){
        cpy[i].data=rubbish[i].data;
        cpy[i].index=rubbish[i].index;
    }
    sort(rubbish,emp,0,num);
    for(int i=0;i<num;i++){
        if(i==rubbish[i].index){
            continue;
        }
        else{
            while(i!=rubbish[i].index){
            int index=rubbish[i].index;
            record temp;
            temp=rubbish[i];
            rubbish[i]=rubbish[index];
            rubbish[index]=temp;
            swaps++;
            }
        }
    }
    printf("%d",swaps);
    return 0;
}