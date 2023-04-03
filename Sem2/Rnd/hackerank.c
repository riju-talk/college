#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int B[], int ll, int lh, int rl, int rh) {
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

void sort(int A[], int B[], int l, int h) {
    if (h - l < 2) {
        return;
    }
    int m = (l + h) / 2;
    sort(A, B, l, m);
    sort(A, B, m, h);
    merge(A, B, l, m, m, h);
}

int search(int arr[], int start, int end, int target) {
    int lo = start, hi = end - 1, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    int a;
    scanf("%d", &a);
    int arr[500];
    int tes_arr[500];
    int emp[500];
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]); 
    }
    for (int i = 0; i < a; i++) {
        tes_arr[i] = arr[i];
    }
    sort(tes_arr, emp, 0, a);
    int count = 0;
    for (int i = 0; i < a; i++) {
        if(arr[i]==tes_arr[i]){
            continue;
        }
        else{
            int j = search(tes_arr, i+1, a, arr[i]);
            if (j == -1) {
                break;
            }
            int temp = tes_arr[i];
            tes_arr[i] = tes_arr[j];
            tes_arr[j] = temp;
            count++;
        }
    }
    printf("%d", count);

    return 0;
}
