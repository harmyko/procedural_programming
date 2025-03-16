#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100
const char outputFileName[MAX_CAPACITY] = "out.txt";

int notDotTxtFile(char fileName[]){
    fileName[strcspn(fileName, "\n")] = 0;
    int correctChars = 0;
    int length = strlen(fileName);
    if(strcmp(&fileName[length - 4], ".txt")){
        return 1;
    }
    else{
        return 0;
    }
}

int getMiddleNumber(int a, int b, int c){
    int mid = -927;
    if((a >= b) && (b >= c)){
        mid = b;
    }
    else if((a >= c) && (c >= b)){
        mid = c;
    }
    else if((b >= a) && (a >= c)){
        mid = a;
    }
    return mid;
}

int main(){
    FILE *file;
    char fileName[MAX_CAPACITY];
    char checkForSpaces[MAX_CAPACITY];

    int a, b, c; // tai trys skaiciai, kuriuos nuskaitysime is failo
    // char inputFileName[MAX_CAPACITY];
    printf("Si programa nuskaitys ivestus sveikus skaicius ir i faila irasys vidurini (pagal reiksme) skaiciu is ju.\n");
    printf("Iveskite tris sveikuosius skaicius, juos atskirdami kabliataskiais (be tarpu) >> ");

    int noValidInput = 1;
    while(noValidInput){
    //    while(noValidInput){
    //        printf("Iveskite .txt failo pavadinima, is kurio norite nuskaityti duomenis >> ");
    //        fgets(inputFileName, sizeof(inputFileName), stdin);
    //
    //        // tikriname, ar korektisku formatu ivestas failo pavadinimas
    //        if((strlen(inputFileName) == MAX_CAPACITY) && (inputFileName[MAX_CAPACITY] != '\n')){
    //            printf("Ivesto failo pavadinimas virsija didziausia leidziama simboliu kieki (%d)! Bandykite dar karta...", MAX_CAPACITY);
    //        }
    //        else if(notDotTxtFile(inputFileName)){
    //            printf("Ivesto tekstinio failo pavadinimas nesibaigia .txt! Bandykite dar karta!\n");
    //        }
    //        else{
    //            // tikriname, ar yra toks failas
    //            inputFileName[strcspn(inputFileName, '\n')] = 0;
    //            file = fopen(inputFileName, "r");
    //            if(file == NULL){
    //                printf("Failas, pavadinimu \"%s\", neegzistuoja! Bandykite dar karta...\n");
    //            }
    //            else{
    //           printf("Failo pavadinimas \"%s\" buvo nuskaitytas sekmingai!\n", inputFileName);
    //            noValidInput = 0;
    //            }
    //        }
    //   }
    //   noValidInput = 1;

        // tikriname, duomenys buvo ivesti nurodyta tvarka
        fgets(checkForSpaces, MAX_CAPACITY, stdin);
        if (strchr(checkForSpaces, ' ') != NULL) {
            printf("Jus ivedete tarpeliu!!! negalima!\nBandykite dar karta >>> ");
        }
        else{
            int validInputs = sscanf(checkForSpaces, "%9d;%9d;%9d", &a, &b, &c);
            if(validInputs == 3){
                printf("Duomenys buvo nuskaityti sekmingai!\n");
                noValidInput = 0;
            }
            else{
                printf("Nepavyko nuskaityti duomenu!\n");
                printf("Bandykite dar karta >>> ");
            }
        }
    }

    int noValidName = 1;
    while(noValidName){
        printf("Iveskite .txt failo, i kuri norite issaugoti duomenis, pavadinima >> ");
        fgets(fileName, MAX_CAPACITY, stdin);

        if((strlen(fileName) == MAX_CAPACITY) && (fileName[MAX_CAPACITY] != '\n')){
            printf("Ivesto failo pavadinimas virsija didziausia leidziama simboliu kieki (%d)! Bandykite dar karta...", MAX_CAPACITY);
        }
        else if(notDotTxtFile(fileName)){
            printf("Ivesto tekstinio failo pavadinimas nesibaigia .txt! Bandykite dar karta!\n");
        }
        else{
            // tikriname, ar yra toks failas
            fileName[strcspn(fileName, "\n")] = 0;
            file = fopen(fileName, "w");
            if(file == NULL){
                printf("Failas, pavadinimu \"%s\", nebuvo atidarytas! Bandykite dar karta...\n");
            }
            else{
            printf("Failas pavadinimu \"%s\" buvo atidarytas sekmingai!\n", fileName);
            noValidName = 0;
            }
        }
    }

    int answer = getMiddleNumber(a, b, c);

    fprintf(file, "Skaicius, su vidutine reiksme, yra: %d", answer);
    printf("Atsakymas buvo sekmingai irasytas i %s!", fileName);

    fclose(file);
    return 0;
}


