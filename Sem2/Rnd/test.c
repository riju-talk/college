#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int bruh(int arr[], int cmp[], int index, int lencmp){
    if(lencmp <= index){
        return 0;
    }
    else{
        if(arr[index] == cmp[index]){
            return bruh(arr, cmp,int atMostK(int arr[], int n, int k)
{
 
    // To store the result
    int count = 0;
 
    // Left boundary of window
    int left = 0;
 
    // Right boundary of window
    int right = 0;
 
    // Map to keep track of number of distinct
    // elements in the current window
    unordered_map<int,int> map;
    // Loop to calculate the count
    while (right < n) {
 
        // Calculating the frequency of each
        // element in the current window
        if (map.find(arr[right])==map.end())
            map[arr[right]]=0;
        map[arr[right]]++;
 
        // Shrinking the window from left if the
        // count of distinct elements exceeds K
        while (map.size() > k) {
            map[arr[left]]= map[arr[left]] - 1;
            if (map[arr[left]] == 0)
                map.erase(arr[left]);
            left++;
        }
 
        // Adding the count of subarrays with at most
        // K distinct elements in the current window
        count += right - left + 1;
        right++;
    }
    return count;
}
  index + 1, lencmp);
        }
        else{
            int j = index;
            while(j<lencmp){
                if(arr[j]!=cmp[j]){
                    swap(&arr[index], &arr[j]);
                    j++;
                }
                else{
                    break;
                }
            }
            return 1 + bruh(arr, cmp, index + 1, lencmp);
        }
    }
}

int main() 
{
    int arr[]={5,1,10,7,2};
    int cmp[]={1,2,5,7,10};
    int *fish=0;
    int k=bruh(arr,cmp,0,5);
    printf("%d",k);
    return 0;
}
