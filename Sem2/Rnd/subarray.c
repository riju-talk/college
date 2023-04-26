#include<stdio.h>
typedef struct{
    int num;
    int freq;
}book;
int main(){
    int n=3;
    int k=1;
    int arr[5]={2,2,4};
    int count[5];
    book map[5];
    int left=0;
    int bookindex=0;
    while(left<n){
        for (int i = 0; i < n; i++) {
        map[i].num = -1;
        map[i].freq = 0;
    }
    int right=left;
    bookindex=0;
    while(right<n){
        int i;
        for(i=0;i<n;i++){
            if(arr[right]==map[i].num){
                map[i].freq++;
                break;
            }
        }
        if(i==n){
        map[bookindex].num=arr[right];
        map[bookindex].freq++;
        bookindex++;
        }
        for(int i=0;i<bookindex;i++){
            printf("(%d,%d)",map[i].num,map[i].freq);
        }
        printf("\n");
        if(bookindex>k){
            left++;
            break;
        }
        int temp;
        for(int i=0;i<k;i++){
            temp+=map[i].freq;
        }
        count[left]=temp;
        right++;
    }
    if(right==n){
        break;
    }
    }
    int net=0;
    for(int i=0;i<left;i++){
        net+=arr[i];
    }
    printf("%d",net);
    return 0;
}