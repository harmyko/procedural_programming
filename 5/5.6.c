#include <stdio.h>

#define MAX_CAPACITY 100
const char successMessage[] = "Duomenys buvo nuskaityti sekmingai!\n";
const char errorMessage[] = "Ivesti duomenys neatitinka reikalavmu! Bandykite dar karta...\n";

int canWriteNumAsSum(int x, int array[], int countElements){
    int sum = 0;
    int canDo = 0;
    for(int i = countElements - 1; i >= 0; --i){
        if(x >= (array[i] + sum)){
            sum += array[i];
            if(sum == x){
                canDo = 1;
                i = -1; // atsakyma turim baigiam loopa
            }
        }
    }
    return canDo;
}

int main(){
    int x, array[MAX_CAPACITY];

    printf("Si programa pasakys, ar is ivesta skaiciu x galima gauti kazkokiu masyvo skaiciu suma.\n");
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

    // masyva surikiuojame didejimo tvarka
    for(int i = 0; i < countElements - 1; ++i){
        for(int j = i + 1; j < countElements; ++j){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    if(canWriteNumAsSum(x, array, countElements))
        printf("Skaicius %d gali buti uzrasytas kaip masyvo elementu suma.", x);
    else
        printf("Skaicius %d negali buti uzrasytas kaip masyvo elementu suma.", x);

    return 0;
}