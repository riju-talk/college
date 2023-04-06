#include<stdio.h>

void merge(int A[],int B[],int l,int m,int h){
    int i=l,j=m,k=0;
    while(i<m && j<h){
        if(A[i]<A[j]){
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
void sort(int A[],int B[],int l,int h){
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
    int arr[90000],emp[90000],cpy[90000],stack[900];
    int top=-1;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++){
        cpy[i]=arr[i];
    }
    sort(arr,emp,0,num);
    for (int i = 0; i < num; i++)
    {
        if(cpy[i]==arr[i]){
            continue;
        }
        else{
            int index,temp;
            for(int j=i+1;j<num;j++){
                if(cpy[j]==arr[i]){
                    index=j;
                }
            }
            temp=cpy[i];
            cpy[i]=cpy[index];
            cpy[index]=temp;
            swaps++;
        }
    }
    printf("%d",swaps);
    return 0;
}