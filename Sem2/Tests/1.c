#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
    for (int i = 0; i < len; i++) {
        if (b[i] < a[i]) {
            return 1;
        }
        else if (b[i] > a[i]) {
            return 0;
        }
    }
    return strlen(a) > strlen(b) ? 1 : 0;
}
int lexicographic_sort_reverse(const char* a, const char* b) {
    int len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
    for (int i = 0; i < len; i++) {
        if (b[i] < a[i]) {
            return 0;
        }
        else if (b[i] > a[i]) {
            return 1;
        }
    }
    return strlen(a) > strlen(b) ? 0 : 1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int counta=0,countb=0;
    for(int i=0;i<strlen(a);i++){
        for(int j=0;j<strlen(a);j++){
            if(a[i]==a[j] &&i !=j ){
                counta++;
            }
        }
    }
    for(int i=0;i<strlen(b);i++){
        for(int j=0;j<strlen(b);j++){
            if(b[i]==b[j] &&i !=j ){
                countb++;
            }
        }
    }
    if(counta<countb){
        return 1;
    }
    else if(counta>countb){
        return 0;
    }
    else{
    return lexicographic_sort(a,b);   
}
}

int sort_by_length(const char* a, const char* b) {
    
    if(strlen(a)>strlen(b)){
        return 1;
    }
    else if (strlen(b)>strlen(a)){
        return 0;
    }
    else if (strlen(b)==strlen(a)){
        return strcmp(a,b);   
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(cmp_func(arr[j],arr[j+1])){
                char* temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}