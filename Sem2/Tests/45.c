#include<stdio.h>
#include<stdlib.h>

char** split(char* text,char delim){
    int len=strlen(text);
    int j=0,count=0;
    char** set_of_sub=(char**)malloc(0);
    int fact=0;
    for(int j=0;j<len;j++){
            if(text[j]==delim){
                count++;
            }
        }
    for(int i=0;i<len-2;){
        char* subs;
        int n;
        if(text[i]==delim){
            subs=(char*)malloc((n+1)*sizeof(char));
            for(int k=0;k<n;k++){
                subs[k]=text[k+fact];
            }
            i++;
            set_of_sub=(char**)realloc(set_of_sub,sizeof(set_of_sub)+1);
            fact=i;
        }
        else{
            n++;
            i++;
        }
    }
    return set_of_sub;
}

int main(){

    return 0;
}