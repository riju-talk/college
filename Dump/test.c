#include<stdio.h>
#include<stdlib.h>

int* reverseArray(int a_count, int* a, int* result_count) {
    int* result;
    result=(int*)malloc(sizeof(int)*a_count);
    int k=0;
    for(int i=(a_count-1);i>=0;i--){
        result[k]=a[i];
        k++;
    }
    *result_count=a_count;
    return result;
}

int main(){
    int A[4]={1,4,3,2};
    int count_b;
    int *B=reverseArray(4,A,&count_b);
    for (int i=0;i<count_b;i++){
        printf("%d ",B[i]);
    }
    return 0;
}