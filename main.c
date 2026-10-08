#include <stdio.h>
#include <string.h>

struct ParsedCommand
{
    char *command;
    char *key;
    char *value;
    int valid;
};

void asking_input(char *input, int sizeInput)
{
    fgets(input, sizeInput, stdin);
    input[strcspn(input, "\n")] = '\0';
}

struct ParsedCommand parsing_input(char *input, struct ParsedCommand ValidCommand)
{
    char *command = strtok(input, " ");
    if (strcmp(command, "SET" ) != 0 && strcmp(command, "GET") != 0)
    {
        ValidCommand.valid = 0;
        printf("Unknown Command: %s\n", command);
    }
    else
    {
        char *key = strtok(NULL, " ");
        char *value = strtok(NULL, " ");
        if (key == NULL || value == NULL)
        {
            printf("Invalid Format\n");
            ValidCommand.valid = 0;
        }
        else
        {
            ValidCommand.valid = 1;
        }
        ValidCommand.command = command;
        ValidCommand.key = key;
        ValidCommand.value = value;

        printf("Command: %s %s %s\n", ValidCommand.command, ValidCommand.key, ValidCommand.value);
    }
    return ValidCommand;
}

void save_data(struct ParsedCommand ValidCommand)
{
    if (ValidCommand.valid == 1)
    {
        FILE *database = fopen("data.vdb", "a");
        if (database != NULL)
        {
            fprintf(database, "%s %s %s\n", ValidCommand.command, ValidCommand.key, ValidCommand.value);
            fclose(database);
        }
        else
        {
            printf("Failed to Open Database");
        }
    }
}


struct ParsedCommand validate_input(char *input, struct ParsedCommand ValidCommand){
    if (input[0] == '\0')
    {
        printf("Input Empty");
    } else {
        ValidCommand = parsing_input(input, ValidCommand);
    }
    return ValidCommand;
}

int main(void)
{
    char input[100];
    struct ParsedCommand ValidCommand;
    printf("VegaBase\nVersion 0.1\n");
    asking_input(input, sizeof(input));
    ValidCommand = validate_input(input, ValidCommand);
    return 0;
}
