#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int length){
    for (int i = 0; i < length; i++){
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if(arr[min_index] > arr[j] ){
                min_index = j;                
            }
        }

        swap(&arr[min_index],&arr[i]);
            
    }    
}


void insertion_sort(int *arr, int length){
     for (int i = 1; i < length; i++){
       int key = arr[i];
       int j = i -1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;        
     }
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays
    int L[n1], R[n2];

    // copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // merge the temp arrays back into arr[left..right]
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        // same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int partition(int array[], int low, int high) {
    int pivot = array[high];  
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (array[j] < pivot) {
            i++;  // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, array[p] is now
           at right place */
        int pi = partition(array, low, high);

        // Separately sort elements before
        // partition and after partition
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void display_array(int *arr, int length){     
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    
}


int main() {
    int arr[10] = {98,2,41,1,3,4,6,2,1,90};
    int length = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, length - 1);
    display_array(arr,length);


    return 0;
}
