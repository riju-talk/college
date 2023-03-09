#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,x,y,d;
        d=0;
        scanf("%d %d %d",&n,&x,&y);
        char* str;
        str=(char*)malloc(n+1); // add 1 to n for null terminator
        for (int j=0;j<n+1;j++){
            scanf("%c",&str[j]);
        }
        str[n+1]='\0';

        for (int k=0;k<n;k++){
            if(str[k]=='1'){
                d++;
            }
        }
        if(d==n||d==0){
            printf("0\n");
            continue;
        }
        else{
            if(x>y){
                printf("%d\n",y);
            }
            else{
                printf("%d\n",x);
            }
        }
    }
    return 0;
}
