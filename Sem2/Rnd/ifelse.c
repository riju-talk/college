#include<stdio.h>
#include<conio.h>

int colsum(int a[100][100],int rows,int colum){
    int sum=0;
    for(int i=0;i<rows;i++){
        sum+=a[i][colum];
    }
    return sum;
}


int main(){
    int a[100][100]={{0,0,1,1,0},{1,1,1,0,1},{0,1,1,1,0},{1,0,1,1,0}};
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(int k=0;k<4;k++){
        int temp=a[k][2];
        a[k][2]=a[k][0];
        a[k][0]=temp;
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}