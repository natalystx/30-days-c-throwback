#include <stdio.h>
#include <string.h>



int main(){
   
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    char reversed[len];

    for(int i = len-1; i >= 0; i--){
       reversed[len- 1 - i] = str[i];
    }

    printf("Reversed string: %s\n", reversed);
   
}

