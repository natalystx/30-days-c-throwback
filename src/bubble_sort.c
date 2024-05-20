#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int data[], int length){
    for (int i = 0; i < length - 1; i++) {        
        bool swapped = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp  = data[j];
                data[j] =  data[j + 1];
                data[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}

void print_arr(int data[], int length){
    for (int i = 0; i < length; i++) {   
        printf("%d\n", data[i]);     
    }
}

int main(){
    int data[10] = {10,122,43,2,5,1,55,3,6,2};
    int length = sizeof(data) / sizeof(data[0]);
    bubble_sort(data, length);
    print_arr(data, length);
    return 0;
}