#include <stdio.h>
#include <string.h>

#define INPUT_FILE_NAME "input.txt"
#define DICTIONARY_FILE_NAME "dictionary.txt"
#define INCORRECT_WORD_FILE_NAME "incorrect words.txt"
#define MAX_CAPACITY 100

int getValidInput(int minValue, int maxValue, int length);
int getWord(FILE *inputFile, char *inputWord, int *wordLine, int *wordPosInLine);

int main(){
    FILE *inputFile = fopen(INPUT_FILE_NAME, "r");
    FILE *dictionaryFile = fopen(DICTIONARY_FILE_NAME, "a+");
    FILE *incorrectFile = fopen(INCORRECT_WORD_FILE_NAME, "a+");

    int wordsReadInTotal = 0;
    int wordsAddedToDictionary = 0;
    int wordsAddedToIncorrect = 0;

    if(inputFile == NULL){
        printf("An error occured while opening \"%s\"!", INPUT_FILE_NAME);
        return -1;
    }

    if(dictionaryFile == NULL){
        printf("An error occured while opening \"%s\"!", DICTIONARY_FILE_NAME);
        return -1;
    }

    if(incorrectFile == NULL){
        printf("An error occured while opening \"%s\"!", INCORRECT_WORD_FILE_NAME);
        return -1;
    }

    printf("This program will check whether the wrods in file \"%s\" are in the dictionary.\n", INPUT_FILE_NAME);
    printf("If a word is not found in \"%s\", the user will have to decide if the word should be added to the dictionary ", DICTIONARY_FILE_NAME);
    printf("If the word is incorrect - it, together with its position, will be stored in \"%s\".\n\n", INCORRECT_WORD_FILE_NAME);

    char inputWord[MAX_CAPACITY];
    char dictionaryWord[MAX_CAPACITY];
    for(int i = 0; i < MAX_CAPACITY; ++i){
        inputWord[i] = 0;
        dictionaryWord[i] = 0;
    }

    int line = 1;
    int pos = 0;
    int *wordLine = &line;
    int *wordPosInLine = &pos;
    
    int wordsFromFunction; // Counts the amount of words the getWord() function went through
    // It will only be useful if the function skipped words due to them being too long ( (MAX_CAPACITY - 1) characters)

    while(wordsFromFunction = getWord(inputFile, inputWord, wordLine, wordPosInLine)){
        int match = 0;
        wordsReadInTotal += wordsFromFunction;

        while(fscanf(dictionaryFile, "%s", dictionaryWord) != EOF){
            if(!strcmp(inputWord, dictionaryWord)){
                ++match;
                break;
            }
        }
        if(match != 1){
            printf("The word \"%s\" was not found in the dictionary!\n", inputWord);
            printf("Choose what action you would like to do with the word by entering the corresponding number:\n");
            printf("1) Save word to the dictionary file \"%s\";\n", DICTIONARY_FILE_NAME);
            printf("2) Save word to the incorrect word list file \"%s\".\n", INCORRECT_WORD_FILE_NAME);
            printf("Next step >> ");
            
            int action = getValidInput(1, 2, 1);
            printf("\n");

            if(action == 1){
                fprintf(dictionaryFile, "%s\n", inputWord);
                ++wordsAddedToDictionary;
            }
            if(action == 2){
                fprintf(incorrectFile, "Line: %d Word in line: %d --- %s\n", *wordLine, *wordPosInLine, inputWord);
                ++wordsAddedToIncorrect;
            }
        }
        fclose(dictionaryFile);
        dictionaryFile = fopen(DICTIONARY_FILE_NAME, "a+");
        for(int i = 0; i < MAX_CAPACITY; ++i){
            inputWord[i] = 0;
        }
    }
    printf("The program has successfully finished its work!\n"
           "- Words read in total: %d\n"
           "- Words added to dictionary: %d\n"
           "- Words added to incorrect words list: %d\n", wordsReadInTotal, wordsAddedToDictionary, wordsAddedToIncorrect);


    fclose(inputFile);
    fclose(incorrectFile);
    fclose(dictionaryFile);
    return 0;
}

int getValidInput(int minValue, int maxValue, int length){
    int input = 0;

    int noValidInput = 1;
    while(noValidInput){
        char inputString[MAX_CAPACITY];
        fgets(inputString, MAX_CAPACITY, stdin);

        if(strchr(inputString, '\n') != NULL){
            if((sscanf(inputString, "%1d", &input) == 1) && (inputString[length] == '\n')){
                if((input >= minValue) && (input <= maxValue)){
                    noValidInput = 0;
                }
                else{
                    printf("The entered number must be within the interval [%d; %d]!\nTry again >> ", minValue, maxValue);
                }
            }
            else{
                printf("You must click enter immediately after entering the number!\nTry again >> ");
            }
        }
        else{
            printf("The data you have entered does not match the requirements!\nTry again >> ");
            while(getchar() != '\n');
        }
    }
    return input;
}

int getWord(FILE *inputFile, char *inputWord, int *wordLine, int *wordPosInLine){
    for(int i = 0; i < MAX_CAPACITY; ++i){
        inputWord[i] = 0;
    }

    int index, words = 0;
    int skipWord = 1;
    while(skipWord){
        ++words;
        skipWord = 0;

        char ch = fgetc(inputFile);

        // The loop skips over all the characters that are not letters
        while(!((ch >= 'A') && (ch <= 'Z')) && !((ch >= 'a') && (ch <= 'z'))){
            if(ch == '\n'){
                ++(*wordLine);
                *wordPosInLine = 0;
            }
            else if(ch == EOF){
                return 0;
            }
            ch = fgetc(inputFile);
            }

        // The first letter of a word has been already read therefore it is stored at the beggining of the string
        index = 0;
        inputWord[index++] = ch; 
        ++(*wordPosInLine);

        ch = fgetc(inputFile);
        while(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))){
            inputWord[index++] = ch;

            // Making sure that the word can fit into the character array
            if(index == (MAX_CAPACITY - 1)){ 
                if((ch < 'A') || ((ch > 'Z') && (ch < 'a') || (ch > 'z'))){
                    if(ch == EOF){
                        // The end of file! The long word fits inside the character array perfectly all good no errors
                    }
                }
                else{
                    printf("The word #%d at line %d is too long! "
                           "This program can only do operations with words made up by up to %d characters in length!\n"
                           "Skipping to the next next word...\n\n", *wordLine, *wordPosInLine, MAX_CAPACITY - 1);
                    skipWord = 1;

                    // Skipping the rest of the long word
                    while(((ch = fgetc(inputFile)) != EOF) && ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')));
                    ++(*wordPosInLine);
                }
            }

            else{
                ch = fgetc(inputFile);
            }
        }
    }
    inputWord[index] = 0;
    return words;
}