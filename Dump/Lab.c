#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *elts;
    int head;
    int tail;
    int size;
    int capacity;
}queue;

int isempty(queue* verts){
    if(0==verts->size){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(queue* verts){
    if(verts->capacity==verts->size){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(queue* verts,int data){
    if(isfull(verts)){
        return;
    }
    else{
        verts->elts[verts->head%verts->capacity]=data;
        verts->size++;
        verts->head++;
    }
}

int deque(queue* verts){
    if(!isempty(verts)){
        int temp=verts->elts[verts->tail];
        verts->tail++;
        verts->size--;
        return temp;
    }
    return -1;
}

queue* create(int capacity){
    queue* q;
    q=(queue*)malloc(sizeof(queue));
    q->elts=(int*)malloc(sizeof(int)*capacity);
    q->capacity=capacity;
    q->size=0;
    q->head=0;
    q->tail=0;
    return q;
}

void bfs(int** matrix,int** visited,int** time,queue* xq, queue* yq, int m,int n){
    enque(xq,0);
    enque(yq,0);
    int i;
    int j;
    int dy[4]={1,-1,0,0};
    int dx[4]={0,0,1,-1};
    time[0][0]=1;
    visited[0][0]=1;
    while(!isempty(xq) && !isempty(yq)){
        i=deque(xq);
        j=deque(yq);
        for(int k=0;k<4;k++){
            int ni=i+dy[k];
            int nj=j+dx[k];
            if(ni<0 || ni>=m || nj<0 || nj>=n){
                continue;
            }
            if((ni==0 || nj==0 || ni==m-1 || nj==n-1) && (visited[ni][nj]==0 && matrix[ni][nj]==0)){
                visited[ni][nj]=1;
                time[ni][nj]=1;
                enque(xq,ni);
                enque(yq,nj);
            }
            else if((ni==0 || nj==0 || ni==m-1 || nj==n-1) && (visited[ni][nj]==0 && matrix[ni][nj]==1)){
                visited[ni][nj]=1;
                time[ni][nj]=-1;
                enque(xq,ni);
                enque(yq,nj);
            }
            else if((ni>0 || nj>0 || ni<=m-1 || nj<=n-1) && (visited[ni][nj]==0 && matrix[ni][nj]==0)){
                visited[ni][nj]=1;
                time[ni][nj]=time[i][j]+1;
                enque(xq,ni);
                enque(yq,nj);
            }
            else if((ni>0 || nj>0 || ni<=m-1 || nj<=n-1) && (visited[ni][nj]==0 && matrix[ni][nj]==1)){
                visited[ni][nj]=1;
                time[ni][nj]=-1;
                enque(xq,ni);
                enque(yq,nj);
            }
        }
    }
}
int main(){
    int m,n,q;
    scanf("%d %d",&m,&n);
    int** matrix=(int**)malloc(sizeof(int*)*m);
    int** visited=(int**)malloc(sizeof(int*)*m);
    int** time=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        matrix[i]=(int*)malloc(sizeof(int)*n);
        visited[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            visited[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        time[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            time[i][j]=-1;
        }
    }
    queue *x_cord,*y_cord;
    x_cord=create(m*n);
    y_cord=create(m*n);
    bfs(matrix,visited,time,x_cord,y_cord,m,n);
    /*scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int prod;
        queue *x_cord,*y_cord;
        bfs(matrix,visited,time,x_cord,y_cord,m,n);*/
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",time[i][j]);
        }
        printf("\n");
    }
    return 0;
}