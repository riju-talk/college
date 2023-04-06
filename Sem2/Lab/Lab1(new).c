#include<stdio.h>

typedef struct{
    int data;
    int index;
} record;
void merge(record A[],record B[],int l,int m,int h){
    int i=l,j=m,k=0;
    while(i<m && j<h){
        if(A[i].data<A[j].data){
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
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
int main(){
    int num,swaps=0;
    int arr[900000],cpy[900000];
    record rubbish[900000],emp[900000];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++){
        rubbish[i].data=arr[i];
        rubbish[i].index=i;
        cpy[i]=arr[i];
    }
    sort(rubbish,emp,0,num);
    for(int i=0;i<num;i++){
        if(cpy[i]==rubbish[i].data){
            continue;
        }
        else{
            swaps++;
            int index=rubbish[i].index;
            record temp;
            temp=rubbish[i];
            rubbish[i]=rubbish[index];
            rubbish[index]=temp;
            i--;
        }
    }
    printf("%d",swaps);
    return 0;
}