#include <stdio.h>

#define MAX_CAPACITY 100
const char successMessage[] = "Duomenys buvo nuskaityti sekmingai!\n";
const char errorMessage[] = "Ivesti duomenys neatitinka reikalavmu! Bandykite dar karta...\n";

int main(){
    int x, array[MAX_CAPACITY];
    int countElements = 0;

    printf("Si programa ivesto skaiciu masyvo elementus paskirstys i 2 masyvus, kuriu elementu suma bus kaip imanoma panasesne\n");
    printf("Iveskite masyvo elementus. Ivede visus norimus elementus, iveskite bet koki simboli, kuris yra ne skaicius.\n");

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

    // sukuriame masyvus, i kuriuos bandysime sumesti pradinio masyvo elementus taip, jog ju suma butu kuo panasesne
    int array1[MAX_CAPACITY] = {0};
    int array2[MAX_CAPACITY] = {0};

    // dvi atitinkamai didziausias pradinio masyvo elementu reiksmes atitinkamai priskiriame siems masyvams
    // pradedame skaiciuoti ju sumas 
    int countElements1 = 0, countElements2 = 0;

    array1[countElements1] = array[--countElements];
    int sum1 = array1[countElements1++];

    array2[countElements2] = array[--countElements];
    int sum2 = array2[countElements2++];

    // toliau priskirinesime masyvams elementus mazejimo tvarka, taciau elementa priskirsime tam masyvui,
    // kurio elementu reiksmiu suma yra mazesne
    for(int i = countElements; i > 0; --i){
        if(sum1 <= sum2){
            array1[countElements1] = array[i - 1];
            sum1 += array1[countElements1++];
        }
        else if(sum1 > sum2){
            array2[countElements2] = array[i - 1];
            sum2 += array2[countElements2++];
        }
    }

    // atspauzdiname gautas masyvu elementu sumas ir pacius elementus

    printf("\nPirmojo masyvo elementu suma: %d\nAntrojo masyvo elementu suma: %d\n", sum1, sum2);
    printf("Pirmaji masyva sudaro %d elementai: ", countElements1);
    for(int i = 0; i < countElements1; ++i){
        printf("%d ", array1[i]);
    }

    printf("\nAntraji masyva sudaro %d elementai: ", countElements2);
    for(int i = 0; i < countElements2; ++i){
        printf("%d ", array2[i]);
    }

    return 0;
}