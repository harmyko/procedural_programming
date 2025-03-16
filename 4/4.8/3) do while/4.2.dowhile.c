#include <stdio.h>
#include <math.h>

int main() {
    printf("Si programa atras visus sveikus skaicius intervale (a; b], kurie dalijasi is c su liekana 1\n");
    printf("iveskite sveikus skaicius a, b ir c:\n");

    int a, b, c, inputValid;
    inputValid = scanf("%d%d%d", &a, &b, &c);

    if(inputValid == 3)
        printf("Duomenys buvo ivesti teisingai, stai sprendiniai:\n");
    else{
        printf("Ivesdami duomenis padarete klaida, prasau paleiskite programa is naujo ir sekite nurodymus\n");
        return 0;
    }
    
    int counter = 0;

    int i = a + 1;
    do{
        if((i % c == 1) && (i > 0)){
            printf("%i\n", i);
            counter++;
        }
        ++i;
    } while(i <= b);

    if(counter == 0)
        printf("sprendiniu nera");

    return 0;
}