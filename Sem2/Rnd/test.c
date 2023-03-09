#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char* res, *text;
    char** resultant;
    text=(char*)malloc(100);
    text="Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    int len=sizeof(text);
    for(int i=0;i<len;i++){
        int n=0;
        char* grasp;
        resultant=(char**)malloc(0);
        for(int j=0;j<len-1;j++){
            if(text[j]=='\\' && text[j+1]=='n'){
                grasp=(char*)malloc(sizeof(char)*n);
                resultant=(char**)malloc(0);
                break;
            }
            else{
                
                n++;
            }
        }
    }
    return 0;
}