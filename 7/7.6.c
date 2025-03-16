#include <stdio.h>

#define INCORRECT_INPUT_MESSAGE "Jusu ivesti duomenys neatitinka reikalavimu!\n"
#define NOT_IN_RANGE_MESSAGE "Jusu ivestas skaicius neturi pasirinkimo atitikmens!\n"

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);
int isInRange(int number, int low, int high);
int validateInput(char *msg, int low, int high);


int main() {
    // Define the menu options
    char *options[] = {
        "Pirmas pasirinkimas",    // First option
        "Antras pasirinkimas",    // Second option
        "Trecias pasirinkimas"    // Third option
    };

    // Call showMenu and get the user's choice
    int choice = showMenu("Pasirinkite parinkti:", options, 3, "Iveskite pasirinkima: ");
    
    // Display the user's choice
    printf("Jusu pasirinkimas: %d - %s\n", choice, options[choice - 1]);

    return 0;
}
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    printf("%s\n", menuTitle);
    for(int i = 0; i < menuSize; ++i){
        printf("%d) %s\n", i + 1,  menuOptions[i]);
    }
    int chosenOption = validateInput(inputMsg, 1, menuSize);
    return chosenOption;
}

int validateInput(char *msg, int low, int high){
    int validInput = 0;
    int number = 0;
    while(!validInput){
        printf("%s", msg);
        char character = 0;
        if((scanf("%9d%c", &number, &character) == 2) && (character == '\n')){
            if(isInRange(number, low, high)){
                validInput = 1;
            }
            else{
                printf("%s", NOT_IN_RANGE_MESSAGE);
            }
        }
        else{
            printf("%s", INCORRECT_INPUT_MESSAGE);
            while(getchar() != '\n');
        }
    }
    return number;
}

int isInRange(int number, int low, int high){
    if((number >= low) && (number <= high)){
        return 1;
    }
    return 0;
}