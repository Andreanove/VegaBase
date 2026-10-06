#include <stdio.h>
#include <string.h>

void check_input(char *input)
{
    char *command = strtok(input, " ");
    if (strcmp(command, "SET"))
    {
        printf("Unknown Command");
    }
    else
    {
        char *key = strtok(NULL, " ");
        char *value = strtok(NULL, " ");
        if (key == NULL || value == NULL)
        {
            printf("Invalid Format");
        }
        else
        {
            printf("Command: %s\n", command);
            printf("Key: %s\n", key);
            printf("Value: %s\n", value);
        }
    }
}

int main(void)
{
    printf("VegaBase\nVersion 0.1\n");
    char input[100];
    //asking input to users
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (input[0] == '\0')
    {
        printf("Input Empty");
    }
    else
    {
        check_input(input);
    }
    return 0;
}

