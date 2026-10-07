#include <stdio.h>
#include <string.h>

struct ParsedCommand{
    char *command;
    char *key;
    char *value;
    int valid;
};

void asking_input(char *input, int sizeInput){
    fgets(input, sizeInput, stdin);
}

struct ParsedCommand parsing_input(char *input)
{
    struct ParsedCommand ValidCommand;
    input[strcspn(input, "\n")] = '\0';
    if (input[0] == '\0')
    {
        printf("Input Empty");
        ValidCommand.valid = 0;
        return ValidCommand;
    }
    else
    {
        char *command = strtok(input, " ");
        if (strcmp(command, "SET"))
        {
            ValidCommand.command = command;
            ValidCommand.valid = 0;
            printf("Unknown Command: %s\n", command);
            return ValidCommand;
        }
        else
        {
            char *key = strtok(NULL, " ");
            char *value = strtok(NULL, " ");
            if (key == NULL || value == NULL)
            {
                printf("Invalid Format");
                ValidCommand.command = command;
                ValidCommand.key = key;
                ValidCommand.value = value;
                ValidCommand.valid = 0;

                printf("Command: %s\n", ValidCommand.command);
                printf("Key: %s\n", ValidCommand.key);
                printf("Value: %s\n", ValidCommand.value);
                return ValidCommand;
            }
            else
            {
                ValidCommand.command = command;
                ValidCommand.key = key;
                ValidCommand.value = value;
                ValidCommand.valid = 1;

                printf("%s ", ValidCommand.command);
                printf("%s ", ValidCommand.key);
                printf("%s ", ValidCommand.value);

                return ValidCommand;
            }
        }
    }
}

void save_data(struct ParsedCommand ValidCommand){
    if(ValidCommand.valid == 1){
        FILE *database = fopen("data.vdb", "a");
        if (database != NULL)
        {
            fprintf(database, "%s %s %s\n", ValidCommand.command, ValidCommand.key, ValidCommand.value);
            fclose(database);
        } else {
            printf("Failed to Open Database");
        }
    }
}

int main(void)
{
    char input[100];
    printf("VegaBase\nVersion 0.1\n");
    asking_input(input, sizeof(input));
    struct ParsedCommand ValidCommand = parsing_input(input);
    save_data(ValidCommand);
    return 0;
}

