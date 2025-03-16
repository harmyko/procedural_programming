#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGRAM_DESCRIPTION "This program reverses each word from the provided data file and writes results to desired locaiton."
#define EXPECTED_ARGUMENTS "This program is expecting either one or two arguments!"
#define ENTER_FILENAMES "Enter data and result file names >> "
#define ENTER_DATA_FILENAME "Enter data file name >> "
#define RESULT_DESTINATION "Leave result file name empty, if you would like the results to be printed to terminal."
#define RESULTS_TO_TERMINAL "The results will be printed to terminal."
#define VALID_RESULT_FILE "Result file has been opened successfully!"
#define COULD_NOT_OPEN_RESULT_FILE "Could not open the result file!"
#define VALID_DATA_FILE "Data file has been opened successfully!"
#define INVALID_DATA_FILE "Data file could not be opened!"
#define MEMORY_ALLOCATION_ERROR "Memory allocation failed!"
#define BUFFER_OUT_OF_SPACE "An error occurred when writing data to buffer!"
#define SUCCESS "Each word of the provided data file has successfully been reversed and written to the desired location."
#define THE_END "Program closing..."
#define NEWLINE "\n"

#define MAX_SIZE 100
#define BUFFER_SIZE 1024
#define MAX_LINE_LENGTH 256

void reverseWords(char line[]);
void appendToBuffer(char buffer[], const char line[], int *currentPos);

int main(int argc, char *argv[])
{
    printf("%s%s", PROGRAM_DESCRIPTION, NEWLINE);

    FILE *data, *result;

    char *dataName = (char *)calloc(MAX_SIZE, sizeof(char));
    char *resultName = (char *)calloc(MAX_SIZE, sizeof(char));
    char *dataBuffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    char *resultBuffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    char *line = (char *)calloc(MAX_LINE_LENGTH, sizeof(char));

    if (!dataName || !resultName || !dataBuffer || !resultBuffer || !line)
    {
        printf("%s%s%s", MEMORY_ALLOCATION_ERROR, NEWLINE, THE_END);

        free(dataName);
        free(resultName);
        free(dataBuffer);
        free(resultBuffer);
        free(line);

        return 0;
    }

    if ((argc != 2) && (argc != 3))
    {
        printf("%s%s", EXPECTED_ARGUMENTS, NEWLINE);

        printf("%s%s%s", RESULT_DESTINATION, NEWLINE, ENTER_FILENAMES);
        scanf("%s", dataName);

        fgets(resultName, MAX_SIZE, stdin);
        int newlineIndex = strlen(resultName) - 1;
        if (resultName[newlineIndex] != '\n')
        {
            while (getchar() != '\n')
                ;
        }
        resultName[newlineIndex] = 0;
    }
    else if (argc == 2)
    {
        strcpy(dataName, argv[1]);
    }
    else if (argc == 3)
    {
        strcpy(dataName, argv[1]);
        strcpy(resultName, argv[2]);
    }

    int noValidFile = 1;
    while (noValidFile)
    {
        data = fopen(dataName, "r");
        if (data != NULL)
        {
            printf("%s%s", VALID_DATA_FILE, NEWLINE);
            noValidFile = 0;
        }
        else if (argc > 1)
        {
            printf("%s%s%s", INVALID_DATA_FILE, NEWLINE, THE_END);
            free(dataName);
            free(resultName);
            free(dataBuffer);
            free(resultBuffer);
            free(line);
            return 1;
        }
        else
        {
            printf("%s%s%s", INVALID_DATA_FILE, NEWLINE, ENTER_DATA_FILENAME);
            scanf("%s", dataName);
        }
    }

    if (strlen(resultName) == 0)
    {
        result = stdout;
        printf("%s%s", RESULTS_TO_TERMINAL, NEWLINE);
    }
    else
    {
        result = fopen(resultName, "w");
        if (result == NULL)
        {
            result = stdout;
            printf("%s%s%s%s%s", COULD_NOT_OPEN_RESULT_FILE, NEWLINE, RESULTS_TO_TERMINAL, NEWLINE, NEWLINE);
        }
        else
        {
            printf("%s%s", VALID_RESULT_FILE, NEWLINE);
        }
    }

    int symbolsRead = 0;
    while (symbolsRead = fread(dataBuffer, sizeof(char), BUFFER_SIZE, data))
    {
        int dataBufferIndex = 0;
        int resultBufferIndex = 0;
        int symbolsChecked = 0;
        while (symbolsRead > symbolsChecked)
        {
            int lineIndex = 0;
            while ((dataBuffer[dataBufferIndex] != '\n') && (lineIndex < MAX_LINE_LENGTH - 1) && (symbolsRead > symbolsChecked))
            {
                ++symbolsChecked;
                line[lineIndex++] = dataBuffer[dataBufferIndex++];
            }
            ++dataBufferIndex;
            ++symbolsChecked;
            reverseWords(line);
            line[lineIndex] = '\n';
            appendToBuffer(resultBuffer, line, &resultBufferIndex);

            for (int i = 0; i <= lineIndex; ++i)
            {
                line[i] = 0;
            }
        }
        fwrite(resultBuffer, sizeof(char), resultBufferIndex, result);
    }

    printf("%s%s%s", NEWLINE, SUCCESS, NEWLINE);

    free(dataName);
    free(resultName);
    free(dataBuffer);
    free(resultBuffer);
    free(line);

    return 0;
}

void reverseWords(char line[])
{
    int lineLength = strlen(line);
    char word[MAX_LINE_LENGTH] = "";
    int wordLength = 0;

    for (int i = 0; i < lineLength; ++i)
    {
        if ((line[i] == ' ') || (i == lineLength - 1))
        {
            int indexOfLastWordSymbolInLine = i - 1;
            if ((line[i] != ' ') && (line[i] != '\n'))
            {
                word[wordLength++] = line[i];
                ++indexOfLastWordSymbolInLine;
            }

            for (int j = wordLength - 1; j >= 0; --j)
            {
                line[indexOfLastWordSymbolInLine - j] = word[j];
            }
            wordLength = 0;
        }
        else
        {
            word[wordLength++] = line[i];
        }
    }
}

void appendToBuffer(char buffer[], const char line[], int *currentPos)
{
    int lineLength = strlen(line);

    if (*currentPos + lineLength + 1 >= BUFFER_SIZE)
    {
        printf("%s%s", BUFFER_OUT_OF_SPACE, NEWLINE);
        return;
    }

    strcpy(buffer + *currentPos, line);
    *currentPos += lineLength;
}