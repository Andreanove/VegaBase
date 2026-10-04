#include <stdio.h>
#include <string.h>

int main(void){
    char input[100];
    printf("VegaBase\nVersion 0.1\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(input[0] == '\0'){
        printf("Input Kosong");
    } else {
        printf("You Entered: [%s]", input);
    }
    return 0;
}