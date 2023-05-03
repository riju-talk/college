#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    char *f,*h;
    f=(char*)malloc(20*sizeof(char));
    h=(char*)malloc(20*sizeof(char));
    scanf("%s %s",f,h);
    if(strcmp(f,"Rijusmit")==0){
        printf("helooooo");
    }
    else if(strcmp(h,"Biswas")==0){
        printf("YEahhhhhh!!!!");
    }
    return 0;
}