#include <stdio.h>

const char programDescription[] = "Si programa apskaiciuos ivesto teigiamo sveiko skaiciaus faktoriala ir ji issaugos out.txt faile.\n";
const char inputDescription[] = "Iveskite sveika teigiama skaiciu: ";
const char success[] = "Jusu ivesti duomenys buvo sekmingai nuskaityti!\n";
const char retry[] = "Bandykite dar karta...\n";
const char nonNumeric[] = "Ivedete ne skaiciu! ";
const char notNewLine[] = "Ivede sveika skaiciu paspaudete ne \"Enter\" mygtuka! ";
const char notPositive[] = "Ivedete ne teigiama skaiciu!";

int getValidInput(){
    int noValidInput = 1;
    int number = 0;
    char character = 0;
    while(noValidInput){
        printf("%s", inputDescription);
        int validInput = scanf("%9d%c", &number, &character);
        if((validInput == 2) && (number > 0) && (character == '\n') && (number <= 20)){
            printf("%s", success);
            noValidInput = 0;
        }
        else if((validInput == 2) && (character != '\n')){
            if((character >= '0') && (character <= '9')){
                printf("Jusu skaicius virsija maksimalaus skaiciaus rezius! %s", retry);
                while(getchar() != '\n');
            }
            else{
                printf("%s %s", notNewLine, retry);
                while(getchar() != '\n');
            }
        }
        else if(number <= 0){
            printf("%s %s", notPositive, retry);
        }
        else if(number > 20){
            printf("Skaiciaus %d faktorialas yra per didelis skaicius, jog galetu buti apskaiciuotas sios programos\n", number);
            printf("Maksimalus galimas faktorialas sioje programoje yra skaiciaus 20\n");
            printf("%s", retry);
        }
        else{
            printf("%s %s", nonNumeric, retry);
            while(getchar() != '\n');
        }
    }
    return number;
}

unsigned long long getFactorial(int number){
    unsigned long long factorial = 1;
    while(number){
        factorial *= number--;
    }
    return factorial;
}

int main(){
    FILE *file;

    printf("%s", programDescription);
    
    int number = getValidInput();
    unsigned long long factorial = getFactorial(number);

    file = fopen("out.txt", "w");

    printf("Skaiciaus %d faktorialas yra: %llu\n", number, factorial);
    fprintf(file, "Skaiciaus %d faktorialas yra: %llu", number, factorial);
    printf("Sis rezultatas taip pat buvo irasytas i faila out.txt, kuri rasite programos kataloge.");

    fclose(file);
    return 0;
}