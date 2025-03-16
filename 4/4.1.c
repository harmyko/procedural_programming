#include <stdio.h>
#include <math.h>

int main() {
    printf("Si programa isspres jusu kvadratine lygti\n");
    printf("iveskite visus tris lygties koeficientus a, b ir c:\n");

    int a, b, c, inputValid;
    inputValid = scanf("%d%d%d", &a, &b, &c);

    if(inputValid == 3)
        printf("kvadratines lygties koeficientai buvo ivesti teisingai\n");
    else{
        printf("Ivesdami duomenis padarete klaida, prasau paleiskite programa is naujo ir sekite nurodymus\n");
        return 0;
    }
    
    int d = (b * b) - (4 * a * c);

    if(d < 0)
        printf("Lygtis sprendiniu neturi");
    if(d == 0){
        int x = (-b) / (2 * a);
        printf("Lygtis turi viena sprendini:\n x = %d", x);
    }
    if(d > 0){
        int x1 = ((-b) - sqrt(d)) / (2 * a); 
        int x2 = ((-b) + sqrt(d)) / (2 * a); 
        printf("Lygtis turi du sprendinius:\n x1 = %d\n x2 = %d", x1, x2);
    }

    return 0;
}