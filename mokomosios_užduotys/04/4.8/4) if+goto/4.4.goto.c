#include <stdio.h>
#include <math.h>

int highestNumber(int a, int b, int c){
    int inputMax;
    if(a >= b && a >= c)
        inputMax = a;
    else if(b >= a && b >= c)
        inputMax = b;
    else if(c >= a && c >= b)
        inputMax = c;
    return inputMax;
}

int dbd(int a, int b, int c){
    int dbd = 1;
    int i = 2;
    loop1:
        if((a % i == 0) && (b % i == 0) && (c % i == 0))
            dbd = i;
        ++i;
    
    if(i < highestNumber(a, b, c))
        goto loop1;
    
    return dbd;
}

int highestNumber2(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

int dbd2(int a, int b){
    int dbd = 1;
    int i = 2;
    loop2:
        if((a % i == 0) && (b % i == 0))
            dbd = i;
        ++i;

    if(i < highestNumber2(a, b))
        goto loop2;
        
    return dbd;
}

int mbk(int a, int b, int c){
    int mbk_ab = (a * b) / dbd2(a, b);
    int mbk = (mbk_ab * c) / dbd2(mbk_ab, c);
    return mbk;
}

int main() {
    printf("Si programa atras ivestu skaiciu DBD ir MBK\n");
    printf("iveskite tris naturaliuosius skaicius:\n");

    int a, b, c, inputValid;
    inputValid = scanf("%d%d%d", &a, &b, &c);

    if(inputValid == 3 && a > 0 && b > 0 && c > 0)
        printf("Duomenys buvo ivesti teisingai\n");
    else{
        printf("Ivesdami duomenis padarete klaida, prasau paleiskite programa is naujo ir sekite nurodymus\n");
        return 0;
    }

    printf("Didziausias bendrasis daliklis: %d\n", dbd(a, b, c));
    printf("Maziausias bendrasis kartotinis: %d\n", mbk(a, b, c));

    return 0;
}