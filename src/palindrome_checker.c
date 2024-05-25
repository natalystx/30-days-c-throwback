#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_palindrome(char* str){
    int length = strlen(str);
    int i = 0;
    int j = length - 1;

    while(i < j){
        if(tolower(str[i]) != tolower(str[j])){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(){

    printf("Input a string: ");
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;

    if(is_palindrome(str)){
        printf("%s is a palindrome\n", str);
    } else{
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}