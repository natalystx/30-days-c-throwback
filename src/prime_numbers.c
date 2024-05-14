#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int n = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 0; i <n; i++){

        if(i == 0 || i == 1){
            continue;
        }
        
        bool isPrime = true;

        int limit = sqrt(i);

        for(int j = 2; j <= limit; j++){
            if(i % j == 0){              
               isPrime = false;
               break;
            }
        }


        if (isPrime == true){
            printf("%d is a prime number\n", i);
        }

          
    }

    
    return 0;
}