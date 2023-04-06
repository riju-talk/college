#include<stdio.h>
typedef struct{
    int data;
    int index;
}record;
int sort(record arr1[], int l, int h) {
    int i = l + 1, j = h;
    record pivot=arr1[l];
    do {
        // I want it to increment when the value is less than pivot
        while((arr1[i].data<pivot.data || (arr1[i].data==pivot.data && arr1[i].index<pivot.index)) && i<h) {
            i++;
        }
        // I want it to decrement when the value is more than pivot
        while((arr1[j].data>pivot.data || (arr1[j].data==pivot.data && arr1[j].index>pivot.index)) && j>l) {
            j--;
        }
        if(j > i) {
            record temp = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = temp;
        }
    } while(j > i);
        record temp = arr1[j];
        arr1[j] = arr1[l];
        arr1[l] = temp;
    return j;
}
void quick(record mat[],int l, int h){
    if(h>l){
        int pivot=sort(mat, l, h);
        quick(mat,pivot+1,h);
        quick(mat,l,pivot-1);
    }
}
int main(){
    int rows,colums;
    int mat[500][500];
    record arr[500];
    scanf("%d%d",&rows,&colums);
    for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(int i=0;i<colums;i++){
        int sum=0;
        for(int j=0;j<rows;j++){
            sum+=mat[j][i];
        }
        arr[i].data=sum;
        arr[i].index=i;
    }
    quick(arr,0,colums-1);
    for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            printf("%d ",mat[i][arr[j].index]);
        }
        printf("\n");
    }
    return 0;
}