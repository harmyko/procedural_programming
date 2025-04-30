// Pirmoji procedūrinio programavimo pagrindų namų darbų užduotis
// 15 užduotis iš https://emokymai.vu.lt/pluginfile.php/44448/mod_resource/content/2/Uzd_1.pdf
// Kodo autorius Ugnius Teišerskis

#include <stdio.h>

int confirmInput(){
    int input;
    char character;
    int validInput = 0;
    while(!validInput){
        if((scanf("%9d%c", &input, &character) == 2) && (character == '\n')){
            printf("Skaicius buvo nuskaitytas sekmingai!\n");
            validInput = 1; 
        }
        else{
            if((character >= '0') && (character <= '9')){
                printf("Jus ivedete skaiciu, kurio ilgis yra didesnis uz 9, Si programa negali aprodoti tokiu dideliu skaiciu!..\n");
                printf("Bandykite dar karta >> ");
            }
            else if(character == '.'){
                printf("Ivedete ne sveika skaiciu!\nBandykite dar karta >> ");
            }
            else if(character == ' '){
                printf("Ivede skaiciu iskart paspauskite \"enter\" mygtuka!\nBandykite dar karta >> ");
            }
            else{
                printf("Ivesdami skaiciu padarete klaida!\nBandykite dar karta >> ");
            }
            while(getchar() != '\n');
        }
    }
    return input;
}

int main(){
    int g, countNumbers = 0, countPositive = 0, sumNegative = 0, mulNegative = 1, number;
    printf("Si programa isves visu sveikos skaiciu sekos nariu skaiciu, teigiamu nariu skaiciu ir neigiamu skaiciu suma bei sandauga.\n");
    printf("Sveikasis skaicius G zymi sekos pabaiga.\n");
    printf("Visu pirma, iveskite sveikaji skaiciu G >> ");
    g = confirmInput();
    
    do{
        printf("Iveskite sekos nari >> ");
        number = confirmInput();

        ++countNumbers;

        if(number > 0)
            ++countPositive;
        else if(number < 0){
            sumNegative += number;
            mulNegative *= number;
        }
    } while(number != g);

    printf("Visu sekos nariu skaicius: %d\n", countNumbers);
    printf("Teigiamu nariu skaicius: %d\n", countPositive);

    if(sumNegative == 0)
        printf("Sioje sekoje nera neigiamu nariu");
    else{
        printf("Neigiamu nariu suma: %d\n", sumNegative);
        printf("Neigiamu nariu sandauga: %d", mulNegative);
    }

    return 0;
}