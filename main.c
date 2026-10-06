#include <stdio.h>
#include <string.h>

struct ParsedCommand{
    char *command;
    char *key;
    char *value;
};

void asking_input(char *input, int sizeInput){
    fgets(input, sizeInput, stdin);
}

void parsing_input(char *input)
{
    input[strcspn(input, "\n")] = '\0';
    if (input[0] == '\0')
    {
        printf("Input Empty");
    }
    else
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
                struct ParsedCommand ValidCommand;
                ValidCommand.command = command;
                ValidCommand.key = key;
                ValidCommand.value = value;

                printf("%s ", ValidCommand.command);
                printf("%s ", ValidCommand.key);
                printf("%s ", ValidCommand.value);
            }
        }
    }
}

int main(void)
{
    char input[100];
    printf("VegaBase\nVersion 0.1\n");
    asking_input(input, sizeof(input));
    parsing_input(input);
    FILE *database = fopen("data.vdb", "a");
    if (database != NULL)
    {
        fprintf(database, "Hello VegaBase\n");
        fclose(database);
    } else {
        printf("Failed to Open Database");
    }
    return 0;
}

