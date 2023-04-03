#include<stdio.h>

// merge sort algo...........................
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
// main sort function...............................................
void sort(int* A, int* B, int l, int h) {
    if (h - l < 2) {
        return;
    }
    int m = (l + h)/ 2;
    sort(A, B, l, m);
    sort(A, B, m, h);
    merge(A, B, l, m, m, h);
}
// Main function...................................
int main(){
    int a,arr[100];
    scanf("%d\n",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int skill_issue[100];
    int real_bhai[100];
    for(int i=0;i<a;i++){
        real_bhai[i]=arr[i];
    }
    sort(arr,skill_issue,0,a);
    int swaps=0;
    for(int i=0;i<a;i++){
        if(arr[i]==real_bhai[i]){//if the first element is in correct position
        //then continue
            continue;
        }
        else{
            //then try swapping with all elements of the array to bring 
            //it into the right position.
            for(int j=i+1;j<a;j++){
                int temp;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                //first swap then check.
                if(arr[i]==real_bhai[i]){
                    //if correct.
                    swaps++;//swap counter increments
                    break;
                }
                //if not corect swap it back.
                else{
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
            }
        }
    }
    //printing minimum number of swaps
    printf("%d",swaps);
    return 0;
}