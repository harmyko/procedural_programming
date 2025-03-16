#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 1000

int main(){
    srand(time(0));
    int a, b;
    int c;
    printf("Si programa israsys jusu pasirinkta kieki (iki 1000) atsitiktinu reiksmiu priklausanciu jusu pasirinktam intervalu\n");

    int noValidInput = 1;
    while(noValidInput){
        printf("Iveskite intervalo pradzios reiksme: ");
        int inputValid = scanf("%d", &a);
        if(inputValid == 1){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    noValidInput = 1;
    while(noValidInput){
        printf("Iveskite intervalo pabaigos reiksme: ");
        int inputValid = scanf("%d", &b);
        if((inputValid == 1) && (b >= a)){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    noValidInput = 1;
    while(noValidInput){
        printf("Iveskite, kiek sugeneruoti reiksmiu: ");
        int inputValid = scanf("%d", &c);
        if(c > MAX_CAPACITY)
            printf("Si programa gali sugeneruoti max %d reiksmiu!\n", MAX_CAPACITY);
        
        if((inputValid == 1) && (c >= 0) && (c <= MAX_CAPACITY)){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    int array[MAX_CAPACITY];
    
    for(int i = 0; i < c; ++i){
        array[i] = a + rand() % ((b + 1) - a);
        printf("%d\n", array[i]);
    }

    return 0;
}