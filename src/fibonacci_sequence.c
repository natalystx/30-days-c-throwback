#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long fibonacci(int n, long long* memo){
    
    if(n <= 1){
        return n;
    }
   
    if(memo[n - 1] != 0){
        return memo[n - 1];
    } else{
      memo[n - 1] = fibonacci(n-1, memo) + fibonacci(n-2, memo);

      return memo[n - 1];
    }

}

int main(){

    printf("Input a number: ");
    int n;
    scanf("%d", &n);
    long long memo[n];
    memset(memo, 0, n * sizeof(long long)); 
    printf("\n");

    if(n > 92){
        printf("Fibonacci number at index %d is too large to be stored in a 64-bit integer\n", n);
        return 1;
    }

    long long result = fibonacci(n, memo);

    printf("Fibonacci number at index %d is %lld\n", n, result);

    return 0;
}