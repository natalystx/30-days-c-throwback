#include <stdio.h>
#include <stdlib.h>

void multiply_matrix(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {

    if(rows != cols){
        printf("The number of columns in the first matrix should be equal to the number of rows in the second matrix\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}


void transpose_matrix(int rows, int cols, int matrix[rows][cols]) {

    int temp[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
 
}

void print_matrix(int rows, int cols, int matrix[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
   
    int rows = sizeof(b) / sizeof(b[0]);
    int cols = sizeof(a[0]) / sizeof(a[0][0]);


    int result[rows][cols];
    multiply_matrix(rows, cols, a, b, result);

    print_matrix(rows, cols, result);
    transpose_matrix(rows, cols, result);
    
    print_matrix(rows, cols, result);

    return 0;
}