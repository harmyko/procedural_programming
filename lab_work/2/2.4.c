#include <stdio.h>
#include <limits.h>

#define MAX_CAPACITY 100

#define NEWLINE "\n"

#define PROGRAM_DESCRIPTION "This program will print two integer values closest to the average: one above, one below."
#define ENTER_ARRAY_SIZE "Enter the amount of integers you would like to enter >> "
#define ENTER_ARRAY_ELEMENT "Enter an integer >> "

#define ERROR_NUMBER_TOO_LONG "Entered number exceeds the maximum length of 9 digits!"
#define ERROR_NOT_INTEGER "Entered number is not an integer!"
#define ERROR_NOT_IN_RANGE "Entered number must belong to the following interval: "
#define ERROR_GENERAL "Invalid input!"
#define VALIDATION_SUCCESSFUL "Input has been successfully read!"

int getValidInput(int min, int max, char *message);
int isInRange(int number, int min, int max);
int isNumber(char character);
int isDecimal(char character);

int arraySorted(int n, int numbers[]);
void copyArray(int n, int array1[], int array2[]);
void enterArray(int n, int numbers[]);
void quicksort(int n, int numbers[]);
int swap(int *value1, int *value2);
int allElementsAreEqual(int n, int numbers[]);
double findAverage(int n, int numbers[]);
int findClosestBelowAverage(int n, int numbers[]);
int findClosestAboveAverage(int n, int numbers[]);

int main(){
    printf("%s%s", PROGRAM_DESCRIPTION, NEWLINE);
    int elementCount = getValidInput(1, MAX_CAPACITY, ENTER_ARRAY_SIZE);
    int elementArray[MAX_CAPACITY];
    enterArray(elementCount, elementArray);

    if(allElementsAreEqual(elementCount, elementArray)){
        printf("There are no values over or below average; they are all equal to %d%s", elementArray[0], NEWLINE);
    }
    else{
        double average = findAverage(elementCount, elementArray);
        int closestBelowAverage = findClosestBelowAverage(elementCount, elementArray);
        int closestAboveAverage = findClosestAboveAverage(elementCount, elementArray);
        printf("The value which was the closest to the average but below average: %d%s", closestBelowAverage, NEWLINE);
        printf("The value which was the closest to the average but above average: %d%s", closestAboveAverage, NEWLINE);
    }

    return 0;
}

int arraySorted(int n, int numbers[]){
    int isSorted = 1;
    for(int i = 1; i < n; ++i){
        if(numbers[i] < numbers[i - 1]){
            isSorted = 0;
            i = n;
        }
    }
    return isSorted;
}

void copyArray(int n, int array1[], int array2[]){
    for(int i = 0; i < n; ++i){
        array2[i] = array1[i];
    }
}

int findClosestBelowAverage(int n, int numbers[]){
    int tempArray[MAX_CAPACITY];
    copyArray(n, numbers, tempArray);

    if(!arraySorted(n, tempArray)){
        quicksort(n, tempArray);
    }

    int answerFound = 0;
    double average = findAverage(n, tempArray);
    int closestBelowAverage;

    for(int i = n - 1; i >= 0; --i){
        if(tempArray[i] < average){
            closestBelowAverage = tempArray[i];
            i = -1;
            answerFound = 1;
        }
    }
    
    if(answerFound){
        return closestBelowAverage;
    }
    return numbers[0];
}

int findClosestAboveAverage(int n, int numbers[]){
    int tempArray[MAX_CAPACITY];
    copyArray(n, numbers, tempArray);

    if(!arraySorted(n, tempArray)){
        quicksort(n, tempArray);
    }

    int answerFound = 0;
    double average = findAverage(n, tempArray);
    int closestAboveAverage;

    for(int i = 0; i < n; ++i){
        if(tempArray[i] > average){
            closestAboveAverage = tempArray[i];
            i = n;
            answerFound = 1;
        }
    }
    if(answerFound){
        return closestAboveAverage;
    }
    return numbers[0];
}

int allElementsAreEqual(int n, int numbers[]){
    for(int i = 1; i < n; ++i){
        if(numbers[i] != numbers[0]){
            return 0;
        }
    }
    return 1;
}

void enterArray(int n, int numbers[]){
    for(int i = 0; i < n; ++i){
        numbers[i] = getValidInput(INT_MIN, INT_MAX, ENTER_ARRAY_ELEMENT);
    }
}

double findAverage(int n, int numbers[]){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += numbers[i];
    }
    return (double)sum / n;
}

void quicksort(int n, int array[]){
    int stack[n];
    int top = -1;

    stack[++top] = 0;        
    stack[++top] = n - 1;    

    while(top >= 0){
        int high = stack[top--];
        int low = stack[top--];

        int pivot = array[high];
        int i = low - 1;

        for(int j = low; j < high; j++){
            if(array[j] <= pivot){
                i++;
                swap(&array[j], &array[i]);
            }
        }

        swap(&array[i + 1], &array[high]);
        int pivotIndex = i + 1;

        if(pivotIndex - 1 > low){
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        if(pivotIndex + 1 < high){
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
}

int swap(int *value1, int *value2){
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int getValidInput(int min, int max, char *message){
    int input;
    char character;
    int validInput = 0;
    do{
        printf("%s", message);
        if((scanf("%9d%c", &input, &character) == 2) && (character == *NEWLINE)){
            if(isInRange(input, min, max)){
                printf("%s%s", VALIDATION_SUCCESSFUL, NEWLINE);
                validInput = 1;
            }
            else{
                printf("%s(%d,%d)%s", ERROR_NOT_IN_RANGE, min, max, NEWLINE);
            } 
        }
        else{
            if(isNumber(character)){
                printf("%s%s", ERROR_NUMBER_TOO_LONG, NEWLINE);
            }
            else if(isDecimal(character)){
                printf("%s%s", ERROR_NOT_INTEGER, NEWLINE);
            }
            else{
                printf("%s%s", ERROR_GENERAL, NEWLINE);
            }
            while(getchar() != *NEWLINE);
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