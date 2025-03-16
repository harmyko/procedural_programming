#include <stdio.h>

#define MENU_MESSAGE "What kind of message you are in the mood for?!"
#define INPUT_MESSAGE "Enter the number of your choice >> "
#define INCORRECT_INPUT_MESSAGE "Error: incorrect input!\n"
#define NOT_IN_RANGE_MESSAGE "Error: your number unfortunately doesn't have a corresponding message yet!\n"

void showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*functions[])());
int isInRange(int number, int low, int high);
int validateInput(char *msg, int low, int high);
void printInspiringQuote();
void printPhilosophicalQuote();
void printHilariousJoke();


int main() {
    char *options[] = {
        "Print an inspiring quote",
        "Print a philosophical quote",    
        "Print a hilarious joke"    
    };

    void(*functions[])() = {
        printInspiringQuote,
        printPhilosophicalQuote,
        printHilariousJoke
    };

    showMenu(MENU_MESSAGE, options, 3, INPUT_MESSAGE, functions);

    return 0;
}
void showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*functions[])()){
    printf("%s\n", menuTitle);
    for(int i = 0; i < menuSize; ++i){
        printf("%d) %s\n", i + 1,  menuOptions[i]);
    }
    int chosenOption = validateInput(inputMsg, 1, menuSize);
    functions[chosenOption - 1]();
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

void printInspiringQuote(){
    printf("\"I have not failed. I've just found 10,000 ways that won't work.\" - Thomas Edison");
}

void printPhilosophicalQuote(){
    printf("\"The meaning of life is that it stops.\" - Franz Kafka");
}

void printHilariousJoke(){
    printf("\"As nigeris.\" - Anonymous");
}