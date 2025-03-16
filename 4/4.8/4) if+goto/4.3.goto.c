#include <stdio.h>
#include <math.h>

int main() {
    printf("Si programa atras Fibonacio sekos skaiciu\n");
    printf("a - tai pirmasis jusu Fibonacio sekos skaicius\n");
    printf("b - tai antrasis jusu Fibonacio sekos skaicius\n");
    printf("c - tai sekos nario numeris, kurio reiksme si programa apskaiciuos\n");
    printf("iveskite tris neneigiamus skaicius a, b ir c:\n");

    int a, b, c, inputValid;
    inputValid = scanf("%d%d%d", &a, &b, &c);

    if(inputValid == 3)
        printf("Duomenys buvo ivesti teisingai, stai sprendiniai:\n");
    else{
        printf("Ivesdami duomenis padarete klaida, prasau paleiskite programa is naujo ir sekite nurodymus\n");
        return 0;
    }
    
    int f[c]; // siame masyve bus talpinamos visos Fibonacio sekos reiksmes
    f[0] = a;
    f[1] = b;
    
    int i = 2;
    loop:
        f[i] = f[i - 2] + f[i - 1];
        ++i;
    
    if(i < c)
        goto loop;

    printf("jeigu pirmasis sekos skaicius yra %d, o antrasis %d, tai %d-asis sekos skaicius yra: %d\n", f[0], f[1], c, f[c - 1]);

    return 0;
}