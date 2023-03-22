#include <stdio.h>
#include <stdlib.h>

void print_ar(int* arr, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
}

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

int main() {
    int C[11] = {9, 8, 13, 67, 100, 34, 2, 0, 3, 4, 3};
int *A;
int *B;
B = (int*)malloc(11*sizeof(int));
A = (int*)malloc(11*sizeof(int));
for(int i=0;i<11;i++){
   A[i] = C[i];
}
    sort(A, B, 0, 11);
    print_ar(A, 11);
    return 0;
}