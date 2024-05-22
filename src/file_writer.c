#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE *fptr;
    fptr = fopen("files/text.txt", "w");
    char myString[100];
    
    printf("Enter a string: ");
    fgets(myString, 100, stdin);
    
    fprintf(fptr, "%s", myString);
    
    fclose(fptr);
    return 0;
}