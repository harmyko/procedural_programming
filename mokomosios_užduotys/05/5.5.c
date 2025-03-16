#include <stdio.h>

#define MAX_CAPACITY 100
const char successMessage[] = "Duomenys buvo nuskaityti sekmingai!\n";
const char errorMessage[] = "Ivesti duomenys neatitinka reikalavmu! Bandykite dar karta...\n";

int countDigits(int x){
    int digits = 0;
    do{
        ++digits;
        x /= 10;
    } while(x);
    return digits;
}

int canMakeNumberFromX(int x, int num){
    int xDigitCount = countDigits(x);
    int xDigit[MAX_CAPACITY] = {10};

    for(int i = 0; i < xDigitCount; ++i){
        xDigit[i] = x % 10;
        x /= 10;
    }

    int numDigitCount = countDigits(num);
    int hasDigit = 0;

    do{
        int digit = num % 10;
        num /= 10;
        for(int i = 0; i < xDigitCount; ++i){
            if(digit == xDigit[i]){
                ++hasDigit;
                xDigit[i] = 10;
                i = xDigitCount;
            }
        }
    } while(num);

    if(numDigitCount == hasDigit)
        return 1;
    else 
        return 0;
}

int main(){
    int x, array[MAX_CAPACITY];

    printf("Si programa pasakys, ar is ivesto skaiciaus x skaitmenu galima gauti kiekviena masyvo elementa.\n");
    int noValidInput = 1;
    while(noValidInput){
        printf("Iveskite skaiciu x: ");
        int validInput = scanf("%d", &x);
        if(validInput == 1){
            printf("%s", successMessage);
            noValidInput = 0;
        }
        else{
            printf("%s", errorMessage);
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    printf("Dabar iveskite masyvo elementus. Ivede visus norimus elementus, iveskite bet koki simboli, kuris yra ne skaicius.\n");
    int countElements = 0;
    for(int i = 0; i < MAX_CAPACITY; ++i){
        printf("Iveskite #%d sekos elementa: ", i + 1);
        int validInput = scanf("%d", &array[i]);
        if(validInput == 1){
            printf("%s", successMessage);
            ++countElements;
        }
        else{
            printf("Masyvo elementu ivestis buvo uzbaigta!\n");
            i = MAX_CAPACITY;
        }
    }

    int countSolutions = 0;
    for(int i = 0; i < countElements; ++i){
        if(canMakeNumberFromX(x, array[i]))
            ++countSolutions;
    }

    printf("%d", countSolutions);

    if(countSolutions == countElements){
        printf("Is skaiciaus %d skaitmenu galima sudaryti visus masyvo elementus.", x);
    }

    if(countSolutions < countElements)
        printf("Neimanoma sudaryti visu masyvo elemento is %d skaitmenu.", x);

    return 0;
}