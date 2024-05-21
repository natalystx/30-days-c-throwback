#include <stdio.h>
#include <stdlib.h>



int main(){
    
    FILE *fptr;
    fptr = fopen("files/text.txt", "r");
    char myString[100];
   
    while(fgets(myString, 100, fptr)) {
    printf("%s", myString);
    }
    
    fclose(fptr);
    return 0;
}
