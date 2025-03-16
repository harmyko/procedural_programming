#include <stdio.h>

#define MAX_CAPACITY 1000

int main(){
    int number[MAX_CAPACITY], primeNumber[MAX_CAPACITY], countNumber = 0, countPrimeNumber = 0;

    printf("Si programa atspauzdins kiekviena ivesta pirmini skaiciu po viena karta.\n");
    printf("Noredami baigti skaiciu ivedima, iveskite neteigiama skaiciu.\n");

    for(int i = 0; i < MAX_CAPACITY; ++i){
        int noValidInput = 1;
        while(noValidInput){
            printf("Iveskite %d-aji skaiciu: ", i + 1);
            int inputValid = scanf("%d", &number[i]);
            if(inputValid == 1){
                printf("Duomenys buvo nuskaityti sekmingai!\n");
                noValidInput = 0;
            }
            else{
                printf("Duomenys buvo ivesti klaidingai!\n");
                int temp;
                while((temp = getchar()) != '\n');
            }
        }
        if(number[i] <= 0){
            countNumber = i;
            i = MAX_CAPACITY;
        }
    }
    
    // kiekviena atveji, kai yra pirminis skaicius, italpiname i nauja masyva
    for(int i = 0; i < countNumber; ++i){
        primeNumber[countPrimeNumber] = number[i];
        ++countPrimeNumber;
        int t = number[i];
        while(--t > 1){
            if(number[i] % t == 0 && number[i] != 0){
                primeNumber[countPrimeNumber] = 0;
                --countPrimeNumber;
                t = 0;
            }
        } 
    }

    // panaikiname is pirminiu skaiciu masyvo dublikatus
    int size = countPrimeNumber;
    for(int i = 0; i < size - 1; ++i){
        for(int j = i + 1; j < size; ++j){
            if(primeNumber[i] == primeNumber[j]){
                primeNumber[i] = 0;
                j = size;
                --countPrimeNumber;
            }
        }
    }

    // suglaudziame pirminiu skaiciu masyvo elementus viena prie kito, kad nebutu tarpu tarp elementu
    for(int i = 0; i < size + 1; ++i){
        for(int j = i + 1; j < size; j++){
            if(primeNumber[i] == 0){
                primeNumber[i] = primeNumber[j];
                primeNumber[j] = 0;
            }
            if(primeNumber[i] != 0)
                j = size;
        }
    }

    // atspauzdiname visus unikalius pirminius skaicius
    printf("Is ivestu skaiciu, sie yra pirminiai: \n");
    for(int i = 0; i < countPrimeNumber; ++i){
        printf("%d\n", primeNumber[i]);
    }

    if(countPrimeNumber == 0)
        printf("Jus neivedete nei vieno pirminio skaiciaus.");

    return 0;
}