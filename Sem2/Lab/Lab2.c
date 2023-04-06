#include<stdio.h>

int colsum(int arr[100][100],int rows,int columm){
    int sum=0;
    for(int i=0;i<rows;i++){
        sum+=arr[i][columm];
    }
    return sum;
}
int partition(int arr[100][100], int l, int h, int rows)
{
    int coll = colsum(arr,rows,l);
    int i = l + 1, j = h;
    do{
        int coli=colsum(arr,rows,i);
        int colj=colsum(arr,rows,j);
        while (coli<coll && coli!=coll && i<h &&i>l)
        {
            i++;
            coli=colsum(arr,rows,i);
        }
        while (colj>=coll && j>l || (coll==coll && j>l))
        {
            j--;
            colj=colsum(arr,rows,j);
        }
        if (j > i)
        {
            for(int k=0;k<rows;k++){
                int temp;
                temp=arr[k][i];
                arr[k][i]=arr[k][j];
                arr[k][j]=temp;
            }
        }
    }while (j > i);
    for(int k=0;k<rows;k++){
        int temp;
            temp=arr[k][l];
            arr[k][l]=arr[k][j];
            arr[k][j]=temp;
    }
    return j;
}
void sort(int arr[100][100], int l, int rows, int h)
{
    if (l >= h)
    {
        return;
    }
    else
    {
        int part;
        part = partition(arr, l, h, rows);
        sort(arr, l, rows ,part - 1);
        sort(arr, part + 1, rows,h);
    } 
}
int main(){
    // only for input
    int arr[100][100];
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&arr[i][j]);
        }
    } 

    // sorting takes place here
    
    sort(arr,0,a,b-1);

    //only for output
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    } 
    return 0;
}