#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int binary_search(int *arr, int t, int start, int end){
    
    // calculate middle position
    int mid = (start + end) / 2;
    if(arr[mid] == t){
        return mid;
    }
    
    // if start is greater than end, then the element is not found
    if(start > end){
        return -1;
    }

    // if the middle element is greater than the target, then search the left side
    if(arr[mid] > t){
        return binary_search(arr, t, start, mid-1);
    }
    // if the middle element is less than the target, then search the right side
    if(arr[mid] < t){
         return binary_search(arr, t, mid + 1, end);
    }

    // if the element is not found
    return -1;
    
}


int main(){

    int arr[8] = {0,1,2,5,7,8,10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int found = binary_search(arr, 12, 0, len);

    printf("Found index %d", found);


    return 0;
}