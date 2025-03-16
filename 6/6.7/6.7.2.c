#include <stdio.h>

#define INVALID_INPUT_LIMIT 3
#define MAX_CAPACITY 100

int main(){
    FILE *file;
    char fileName[MAX_CAPACITY] = "in.txt";
    int decimal = 0;
    char fraction[MAX_CAPACITY];
    char comma = 0;

    int invalidInputCounter = 0;
    int *ptrInvalids = &invalidInputCounter;

    for(int i = 0; i < MAX_CAPACITY; ++i){
        fraction[i] = 0;
    }

    printf("Si programa apskaiciuos realaus skaiciaus, kuri irasysite i tekstini faila \"%s\", ilgi.\n", fileName);
    printf("Iveskite i tekstini faila \"in.txt\" realuji skaiciu, kuris atitinka siuos kriterijus:\n");
    printf("- yra ne mazesnis uz 10;\n- ne didesnis uz 1000;\n- su ne daugiau kaip 3 skaitmenimis trupmenineje dalyje;\n");
    printf("- sveikaja dali nuo trupmenines skiria kablelio ',' simblolis.\n\n");
    printf("Irase skaiciu i tekstini faila ir noredami testi programa, irasykite skaicu \"1\" i sia programa.\n");
    printf("Ar norite testi? - ");

    // vartotojui perskaicius programos aprasyma duodame laiko ivesti duomenis i faila, jei tai dar nebuvo padaryta
    int nextStep = 0;
    int noValidInput = 1;
    while(noValidInput){
        int validInput = scanf("%d", &nextStep);
        while(getchar() != '\n');
        if((validInput != 1) || (nextStep != 1)){
            ++(*ptrInvalids);
           printf("Jusu ivesti duomenys neatitinka nurodymu!\nIveskite skaiciu 1: ");
        }
        else{
            noValidInput = 0;
        }

        if(*ptrInvalids == INVALID_INPUT_LIMIT){
            printf("\nVirsijote neteisingu ivesciu limita! Programa baigia darba...");
            return -1;
        }
    }

    noValidInput = 1;
    while(noValidInput){

        // patikriname, ar egzistuoja toks failas
        int fileInvalid = 1;
        while(fileInvalid){
            file = fopen(fileName, "r");
            if(file == NULL){
                printf("Nepavyko atidaryti failo pavadinimu \"%s\"!\nNurodykite tekstinio failo pavadinima, is kurio programa nuskaitys duomenis: ", fileName);
                ++(*ptrInvalids);
                scanf("%s", &fileName);
                while(getchar() != '\n');
            }
            else{
                printf("Failas buvo sekmingai atidarytas!\n");
                fileInvalid = 0;
            }
            if(*ptrInvalids == INVALID_INPUT_LIMIT){
            printf("\nVirsijote neteisingu ivesciu limita! Programa baigia darba...");
            return -1;
        }
        }


        int inputs = fscanf(file ,"%d%c%s", &decimal, &comma, fraction);

        // tikriname, ar nuskaityti duomenis atitinka visus reikalavimus
        int errors = 0;
        if(inputs == 3){
            if((decimal < 10) || (decimal > 1000)){
                printf("Skaicius turi priklausyti intervalui [10; 1000]!\n");
                ++errors;
            }
            if((comma != ',')){
                printf("Sveika ir trupmenine dali turi skirti kablelio ',' simbolis!\n");
                ++errors;
            }
            for(int i = 0; i < 4; ++i){
                if((fraction[i] != '\0') && ((fraction[i] < '0') || (fraction[i] > '9'))){
                    printf("Visi duomenys po kablelio simbolio turi buti skaitmenys!\n");
                    ++errors;
                    i = 4;
                }
            }
            if((fraction[3] != '\0') && (fraction[2] != '\0') && (fraction[1] != '\0') && (fraction[0] != '\0')){
                printf("Po kablelio ivedete daugiau nei 3 skaitmenis!\n");
                ++errors;
            }
            if(decimal == 1000){
                for(int i = 0; i < 3; ++i){
                    if(fraction[i] > '0'){
                        printf("Skaicius virsyja rezius [10; 1000]!\n");
                        ++errors;
                        i = 3;
                    }
                }
            }
        }
        else if(inputs == 2){
            if(comma == ','){
                printf("Duomenys faile uzrasyti nesamoningai! Kablelis po sveikos dalies neturi jokios reiksmes, nes po jo nera jokiu skaitmenu!\n");
                ++errors;
            }
            else{
                printf("Ivede sveika skaiciu ivedete nereikalinga simboli!\n");
                ++errors;
            }
        }
        else if(inputs == 1){
            if((decimal < 10) || (decimal > 1000)){
                printf("Sveika skaiciaus dalis turi priklausyti intervalui [10; 1000]!\n");
                ++errors;
            }
        }
        else if(inputs == 0){
            printf("Pirmas ivestas skaitmuo i tekstini faila nebuvo skaicius!\n");
            ++errors;
        }
        if(errors == 0){
            printf("Duomenys buvo nuskaityti is failo sekmingai!\n");
            noValidInput = 0;
        }
        else{
            ++(*ptrInvalids);
            fclose(file);
            printf("Iveskite failo pavadinima (jame negali buti tarpeliu), is kurio norite nuskaityti duomenis: ");
            while(scanf("%s", fileName) != 1){
                ++(*ptrInvalids);
                printf("Ivedete ne korektiska failo pavadinima! Bandykite dar karta...\n");
            }
        }
        if(*ptrInvalids == INVALID_INPUT_LIMIT){
            printf("\nVirsijote neteisingu ivesciu limita! Programa baigia darba...");
            return -1;
        }
    }
    
    fclose(file);

    // dabar jau turime patikrintus, korektiskus duomenis savo kintamuosiuose; skaiciuojame skaitmenu kieki 
    int countDigits = 0;

    while(decimal){
        ++countDigits;
        decimal /= 10;
    }

    if(comma == ','){
        ++countDigits;
    }

    for(int i = 0; i < 3; ++i){
        if((fraction[i] >= '0') && (fraction[i] <= '9')){
            ++countDigits;
        }
        if(fraction[i] == '\0'){
            i = 3;
        }
    }

    printf("Skaicus, faile \"%s\", yra %d simboliu ilgio.", fileName, countDigits);

    return 0;
}