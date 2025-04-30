#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_validation.h"

const char errTooLong[] = "Entered number exceeds the maximum length of 9 digits!";
const char errNotInt[] = "Entered number is not an integer!";
const char errNotInRange[] = "Entered number must belong to the following interval: ";
const char errGeneral[] = "Invalid input!";
const char success[] = "Input has been successfully read!";

int isTxtFile(char *fileName){
    int length = strlen(fileName);

    if(length < 4){
        return 0;
    }

    char *extension = &fileName[length - 1 - 3];
    if(strcmp(extension, ".txt") != 0){
        return 0;
    }

    return 1;
}

int getValidInput(int min, int max, char *message){
    int input;
    char character;
    int validInput = 0;

    do{
        printf("\n%s", message);
        if((scanf("%9d%c", &input, &character) == 2) && (character == '\n')){
            if(isInRange(input, min, max)){
                validInput = 1;
            }
            else{
                printf("%s(%d,%d)\n", errNotInRange, min, max);
            } 
        }
        else{
            if(isNumber(character)){
                printf("%s\n", errTooLong);
            }
            else if(isDecimal(character)){
                printf("%s\n", errNotInt);
            }
            else{
                printf("%s\n", errGeneral);
            }
            while(getchar() != '\n');
        }
    } while(!validInput);

    return input;
}

int isInRange(int number, int min, int max){
    if((number < min) || (number > max)){
        return 0;
    }
    return 1;
}

int isNumber(char character){
    if((character >= '0') && (character <= '9')){
        return 1;
    }
    return 0;
}

int isDecimal(char character){
    if(character == '.'){
        return 1;
    }
    return 0;
}