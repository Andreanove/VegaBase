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
        char *command = strtok(input, " ");
        char *key = strtok(NULL, " ");
        char *value = strtok(NULL, " ");
        if(command == NULL || key == NULL || value == NULL){
            printf("Format salah\n");
        } else {
            printf("Command: %s\n", command);
            printf("Key: %s\n", key);
            printf("Value: %s\n", value);
        }
    }
    return 0;
}