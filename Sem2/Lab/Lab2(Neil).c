#include <stdio.h>
int partition(int arr1[], int low, int high, int arr2[]) {
    int pivot = arr1[low];
    int i = low + 1;
    int j = high;
    int temp;
    int temp2;
    while (i <= j) {
        while (i <= high && (arr1[i] < pivot || (arr1[i] == pivot && arr2[i] <= arr2[low]))) {
            i++;
        }
        while (j >= low + 1 && (arr1[j] > pivot || (arr1[j] == pivot && arr2[j] > arr2[low]))) {
            j--;
        }
        if (i < j) {
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;

            temp2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp2;
        }
    }
    temp = arr1[low];
    arr1[low] = arr1[j];
    arr1[j] = temp;

    temp2 = arr2[low];
    arr2[low] = arr2[j];
    arr2[j] = temp2;

    return j;
}

void quicksort(int arr1[], int low, int high, int arr2[]) {
    int part_index;
    if (low < high) {
        part_index = partition(arr1, low, high, arr2);
        quicksort(arr1, low, part_index - 1, arr2);
        quicksort(arr1, part_index + 1, high, arr2);
    }
}


int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int arr[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int arr1[100];
    int arr2[100];
    for (int j = 0; j < n; j++) {
        arr2[j]=j;
        arr1[j] = 0;  // initialize arr1[j] to 0 before summing
        for (int i = 0; i < m; i++) {
            arr1[j] += arr[i][j];
        }
    }
    quicksort(arr1,0,n-1,arr2);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x=arr2[j];
            printf("%d ",arr[i][x]);

        }
        printf("\n");
    }


    return 0;
}