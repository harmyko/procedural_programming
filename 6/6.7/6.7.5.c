#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100
#define INVALID_INPUT_LIMIT 3
#define FILE_NAME "emails.txt"

int main(){
    FILE *file = fopen(FILE_NAME, "a");

    int invalidInputCounter = 0;
    int *ptrInvalids = &invalidInputCounter;

    printf("Si programa nuskaitys jusu irasyta eilute ir pasakys, ar joje buvo ivestas korektiskas elektroninio pasto adresas.\n");
    printf("Visi korektiskai ivesti elektroninio pasto adresai bus kaupiami \"emails.txt\" faile.\n");
    printf("Pagal uzduoties salyga, korektiska elektroninio pasto ivestis atrodo taip:\n");
    printf("1) pirmiausia yra ivestas bent vienas bet koks, isskyrus '@', simbolis;\n");
    printf("2) po ivestu simboliu sekos yra ivestas '@' simbolis;\n");
    printf("3) po sio simbolio yra ivestas bent vienas bet koks simbolis, isskyrus '@' ir '.';\n");
    printf("4) po siu simboliu ivestas bent vienas tasko '.' simbolis;\n");
    printf("5) po paskutinio tasko, yra ivestas bent vienas bet koks, isskyrus '.' ar '@', simbolis\n\n");
    
    char email[MAX_CAPACITY];
    int length;

    // gauname korektiska elektroninio pasto ivesti
    int noValidInput = 1;
    while(noValidInput){
        printf("Iveskite elektroninio pasto adresa >> ");
        fgets(email, MAX_CAPACITY, stdin);
        length = strlen(email);
        if((length == MAX_CAPACITY) && (email[MAX_CAPACITY - 1] != '\n')){
            printf("Jusu ivestas elektroninio pasto adresas virsijo ilgio limita (%d simbolilu)!\n", MAX_CAPACITY);
            ++(*ptrInvalids);
            while(getchar() != '\n');
        }
        else{
            int countAtSigns = 0;
            for(int i = 0; i < length; ++i){ // jei daugiau nei 1 '@' simbolis - ivestis nekorektiska
                if(email[i] == '@'){
                    ++countAtSigns;
                }
            }
            int atSignPos = strcspn(email, "@");
            if((atSignPos > 0) && (countAtSigns == 1)){ 
                if((email[atSignPos + 1] != '.') && (email[atSignPos + 1] != '@')){ 
                    int lastDotPos = 0;
                    for(int i = length - 2; i > atSignPos; --i){
                        if(email[i] == '.'){
                            lastDotPos = i;
                            i = atSignPos;
                        }
                    }
                    if((lastDotPos != 0)){
                        if((email[lastDotPos - 1] != '.') && (email[lastDotPos - 1] != '@'))
                        printf("Elektroninio pasto adresas buvo sekmingai nuskaitytas!\n");
                        noValidInput = 0;
                    } 
                }
            }
        }
        if(noValidInput == 1){
            ++(*ptrInvalids);
            printf("Buvo ivestas nekorektiskas elektroninio pasto adresas! Bandykite dar karta...\n");
        }
        if(*ptrInvalids == INVALID_INPUT_LIMIT){
            printf("\nVirsijote neteisingu ivesciu limita! Programa baigia darba...");
            return -1;
        }
    }

    // gauname tik korektisko elektroninio pasto adreso domena
    char domain[MAX_CAPACITY];
    for(int i = 0; i < MAX_CAPACITY; ++i){
        domain[i] = 0;
    }
    
    int domainLength = -1;
    for(int i = strcspn(email, "@"); i < length; ++i){
        domain[++domainLength] = email[i];
    }

    if(file == NULL){
        printf("Nepavyko atidaryti failo \"&s\"!\n", FILE_NAME);
        return 1;
    }

    fputs(email, file);
    printf("Elektroninio pasto adresas buvo irasytas i faila \"%s\"!\n", FILE_NAME);
    fclose(file);
    printf("Ivesto elektroninio pasto domenas yra: %s", domain);

    return 0;
}