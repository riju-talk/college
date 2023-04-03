#include<stdio.h>
void merge(int* A, int* B, int ll, int lh, int rl, int rh) {
    int i = ll, j = rl, k = 0;
    while (i < lh && j < rh) {
        if (A[i] > A[j]) {
            B[k] = A[j];
            j++;
        }
        else {
            B[k] = A[i];
            i++;
        }
        k++;
    }
    while (i < lh) {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j < rh) {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = 0; i < k; i++) {
        A[ll + i] = B[i];
    }
}
void sort(int* A, int* B, int l, int h) {
    if (h - l < 2) {
        return;
    }
    int m = (l + h)/ 2;
    sort(A, B, l, m);
    sort(A, B, m, h);
    merge(A, B, l, m, m, h);
}
int main(){
    int arr[100];
    int n,q,l,r,k;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[n]);
    }
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&l,&r,&k);
    }
    return 0;
}