#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100
#define INVALID_INPUT_LIMIT 3
#define DATE_FORMAT_LENGTH 12 // XXXX-MM-YY'\n\0'
const char fileName[] = "week.txt";

int getWeekday(int year, int month, int day){ // Zeller's Congruence formulė
    int weekday = 0;
    if(month < 3){
        month += 12;
        year--;
    }
    
    int k = year % 100; // Year of the century
    int j = year / 100; // Zero-based century

    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    f = f % 7;
    
    switch(f){
        case 0:
            weekday = 6;
            break;
        case 1:
            weekday = 7;
            break;
        case 2:
            weekday = 1;
            break;
        case 3:
            weekday = 2;
            break;
        case 4: 
            weekday = 3;
            break;
        case 5:
            weekday = 4;
            break;
        case 6:
            weekday = 5;
            break;
    }
    return weekday;
}

int main(){
    FILE *file = fopen(fileName, "r");

    int invalidInputCounter = 0;
    int *ptrInvalids = &invalidInputCounter;

    int year, month, day;
    char date[MAX_CAPACITY], weekdayName[MAX_CAPACITY];
    for(int i = 0; i < MAX_CAPACITY; ++i){
        date[i] = 0;
    }

    printf("Si programa atspauzdins, kokia savaites diena yra jusu ivesta data.\n");

    if(file == NULL){
        printf("Kad si programa veiktu, reikia sukurti programos kataloge faila pavadinimu \"week.txt\"!\n");
        return 1;
    }
    
    printf("Iveskite data formatu YYYY-MM-DD >> ");

    int noValidInput = 1;
    while(noValidInput){
        fgets(date, MAX_CAPACITY, stdin);
        int errors = 0;
        for(int i = 0; i < DATE_FORMAT_LENGTH; ++i){
            if((i < 4) || (i == 5) || (i == 6) || (i == 8) || (i == 9)){
                if((date[i] < '0') && (date[i] > '9')){
                    printf("Data buvo ivesta ne nurodytu formatu!\n");
                    ++errors;
                    i = DATE_FORMAT_LENGTH;
                }
            }
            else if(i == 10){
                if(date[i] != '\n'){
                    printf("Data buvo ivesta ne nurodytu formatu!\n");
                    ++errors;
                    i = DATE_FORMAT_LENGTH;
                }
            }
            else if(i == 11){
                if(date[i] != '\0'){
                    printf("Data buvo ivesta ne nurodytu formatu!\n");
                    ++errors;
                    while(getchar() != '\n');
                }
            }
            else{
                if(date[i] != '-'){
                    printf("Data buvo ivesta ne nurodytu formatu!\n");
                    ++errors;
                    i = DATE_FORMAT_LENGTH;
                }
            }
        }
        if(errors == 0){
            date[strcspn(date, "\n")] = 0;
            sscanf(date ,"%d-%d-%d", &year, &month, &day);

            if(year < 1){
                printf("Metai buvo pradeti skaiciuoti nuo 1!\n");
                ++errors;
            }

            if((month < 1) || (month > 12)){
                printf("Kalendoriuje yra tik 12 menesiu! Nuo 1 iki 12 imtinai!\n");
                ++errors;
            }

            // tikriname dienu skaicius...
            if(day < 1){
                printf("Kiekvieno menesio dienos yra pradedamos skaiciuoti nuo pirmos!\n");
                ++errors;
            }
            if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)){
                if(day > 31){
                    printf("%d-asis menesis turi tik 31 diena!\n", month);
                    ++errors;
                }
            }
            else if((month == 4) || (month == 6) || (month == 9) || (month == 11)){
                if(day > 30){
                    printf("%d-asis menesis turi tik 30 dienu!\n", month);
                    ++errors;
                }
            }
            else if((month == 2) && (year % 4 == 0)){
                if(day > 29){
                    printf("%d-asis menuo keliamaisiais metais (%d) turi tik 29 dienas!\n", month, year);
                    ++errors;
                }
            }
            else if((month == 2) && (year % 4 != 0)){
                if(day > 28){
                    printf("%d-asis menuo ne keliamaisiais metais (%d) turi tik 28 dienas!\n", month, year);
                    ++errors;
                }
            }
        }
        if(errors == 0){
            printf("Data buvo sekmingai nuskaityta!\n");
            noValidInput = 0;
        }
        else{
            if(++(*ptrInvalids) == INVALID_INPUT_LIMIT){
                printf("\nVirsijote neteisingu ivesciu limita! Programa baigia darba...");
                return -1;
            }
            printf("Bandykite dar karta >> ");
        }
    }

    int weekday = getWeekday(year, month, day);
    for(int i = 0; i < weekday; ++i){
        fgets(weekdayName, MAX_CAPACITY, file);
    }

    printf("Datos %s savaites diena yra: %s.", date, weekdayName);
    fclose(file);
    
    return 0;
}