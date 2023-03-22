#include <stdio.h>
#include <stdlib.h>
void print_arr(int*,int);
void towerofhanoi(int* initarr, int* midarr, int* finalarr, int count, int index){
    if (count == 1) {
        finalarr[index] = initarr[0];
    } else {   
        // Copy initarr to midarr
        for (int i = 0; i < count; i++) {
            midarr[i] = initarr[i];
        }
        printf("Middle array:- ");
        print_arr(midarr,count);
        printf("\n");
        // Allocate new memory for initarr and copy values from midarr
        int* new_initarr = (int*) malloc((count - 1) * sizeof(int));
        for (int i = 1; i < count; i++) {
            new_initarr[i - 1] = midarr[i];
        }
        initarr = new_initarr;
        printf("Intitial array:- ");
        print_arr(new_initarr,count-1);
        printf("\n");
        // Move top disk from midarr to finalarr
        finalarr[index] = midarr[0];
        printf("Final array:- ");
        print_arr(finalarr,index+1);
        printf("\n");
        towerofhanoi(initarr, midarr, finalarr, count - 1, index+1);
    }
}

void print_arr(int* ptr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int main() {
    int g[] = {7, 9, 10, 103, 5, 77, 24, 10};
    int num = 8, index=0;
    int* new_arr = &g[0];
    int* dest = (int*) malloc(num * sizeof(int));
    int* midg = (int*) malloc(num * sizeof(int));
    towerofhanoi(new_arr, midg, dest, num,index);
    printf("\n");
    print_arr(dest, num);
    return 0;
}
