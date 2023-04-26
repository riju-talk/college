#include<stdio.h>
#include<stdlib.h>

int find_perry(int *arr,int n){
    int perimeter=0;
    int max=2*arr[0]+2-1;
    int hight;
    int width;
    for(int i=0;i<n;i++){
        hight=arr[i];
        if(hight==0){
            continue;
        }
        for(int j=i;j<n;j++){
            width=(j-i+1);
            if(arr[j]<hight && arr[j]!=0){
                hight=arr[j];
            }
            if(arr[j]==0){
                break;
            }
            perimeter=2*width+2*hight-1;
            if(perimeter>max){
                max=perimeter;
            }
        }
    }
    return max;
}
int main(){
    int ar[4]={2,4,0,1};
    int h=find_perry(ar,4);
    printf("%d",h);
    return 0;
}