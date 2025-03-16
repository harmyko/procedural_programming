#include <stdio.h>

int main(){
    printf("Si programa atliks lygiai 10 veiksmu su masyvais\n");
    // a) apibrėžia masyvą, galinti sutalpinti 10 elementų, tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis
    int array[10] = {0};

    // b) atspausdina visą masyvą į ekraną
    printf("b) dalis:\n");
    for(int i = 0; i < 10; ++i)
        printf("%d-asis masyvo elementas: %d\n", i + 1, array[i]);

    // c) pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;

    // d) ištrina iš masyvo trečią elementą
    for(int i = 2; i < 9; ++i){
        array[i] = array[i + 1];
    }
    array[9] = 0;

    // e) įterpia į masyvą naują elementą su reikšme 4, taip, kad po įterpimo jis būtų septintas
    for(int i = 10; i > 5; --i){
        array[i] = array[i - 1];
    }
    array[6] = 4;

    // f) atspausdina visą masyvą į ekraną
    printf("f) dalis\n");
    for(int i = 0; i < 10; ++i)
        printf("%d-asis masyvo elementas: %d\n", i + 1, array[i]);

    // g) paprašo vartotojo įvesti du skaičius (x ir y), ir masyvo elementui su indeksu x nustato naują reikšmę, lygią y
    int noValidInput = 1, x, y;
    while(noValidInput){
        printf("Iveskite du skaicius (x ir y) ir masyvo elementui su indeksu x bus nustatyta nauja reiksme, lygi y: \n");
        int inputValid = scanf("%d%d", &x, &y);
        if((inputValid == 2) && (x < 10) && (x >= 0)){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }
    array[x] = y;

    // h) paprašo vartotojo įvesti vieną skaičių (x), ir ištrina iš masyvo elementą su indeksu x
    noValidInput = 1;
    while(noValidInput){
        printf("Iveskite skaiciu (x), ir is masyvo bus istrintas elementas su indeksu x\n");
        int inputValid = scanf("%d", &x);
        if((inputValid == 1) && (x < 10) && (x >= 0)){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    for(int i = x; i < 9; ++i){
        array[i] = array[i + 1];
    }
    array[9] = 0;

    // į) paprašo vartotoją įvesti du skaičius (x ir y), ir į masyvą įterpia naują elementą su reikšme y, taip, kad po įterpimo jo indeksas būtų x
    noValidInput = 1;
    while(noValidInput){
    printf("Iveskite du skaicius (x ir y) ir i masyva bus iterptas elementas su reiksme y, taip, kad po iterpimo jo indeksas butu x\n");
    int inputValid = scanf("%d%d", &x, &y);
    if((inputValid == 2) && (x < 10) && (x >= 0)){
        printf("Duomenys buvo nuskaityti sekmingai!\n");
        noValidInput = 0;
    }
    else{
        printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
        int temp;
        while((temp = getchar()) != '\n');
    }
    }

    for(int i = 9; i > x; --i){
        array[i] = array[i - 1];
    }
    array[x] = y;


    // j) atspausdina visą masyvą į ekraną
    printf("j) dalis\n");
    for(int i = 0; i < 10; ++i)
        printf("%d-asis masyvo elementas: %d\n", i + 1, array[i]);

    return 0;
}