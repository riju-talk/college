#include <stdio.h>

int colsum(int arr[100][100], int rows, int column) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += arr[i][column];
    }
    return sum;
}

int partition(int arr[100][100], int low, int high, int rows) {
    int pivot = colsum(arr, rows, low);
    int i = low + 1, j = high;
    int coll = colsum(arr,rows,low);
    while (i <= j) {
        int coli=colsum(arr,rows,i);
        int colj=colsum(arr,rows,j);
        while (coli<coll && coli!=coll) {
            i++;
            coli=colsum(arr,rows,i);
        }
        while (colj>=coll && colj>colsum(arr,rows,low)) {
            j--;
            coli=colsum(arr,rows,j);
        }
        if (i < j) {
            for (int k = 0; k < rows; k++) {
                int temp = arr[k][i];
                arr[k][i] = arr[k][j];
                arr[k][j] = temp;
            }
        }
    }
    for (int k = 0; k < rows; k++) {
        int temp = arr[k][low];
        arr[k][low] = arr[k][j];
        arr[k][j] = temp;
    }
    return j;
}

void quicksort(int arr[100][100], int low, int high, int rows) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, rows);
        quicksort(arr, low, pivotIndex - 1, rows);
        quicksort(arr, pivotIndex + 1, high, rows);
    }
}

int main() {
    // Input
    int arr[100][100];
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Sorting
    quicksort(arr, 0, cols - 1, rows);

    printf("\n");
    // Output
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}