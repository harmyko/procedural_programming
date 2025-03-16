#include <stdio.h>

double sum(double number[], int n){
    double sum = 0;
    int i = 0;
    while(i < n){
        sum += number[i];
        ++i;
    }
    return sum;
}

double avg(double number[], int n){
    double avg = sum(number, n) / n;
    return avg;
}

double numMax(double number[], int n){
    double max = number[0];
    int i = 1;
    while(i < n){
        if(number[i] > max)
            max = number[i];
        ++i;
    }
    return max;
}

double numMin(double number[], int n){
    double min = number[0];
    int i = 1;
    while(i < n){
        if(number[i] < min)
            min = number[i];
        ++i;
    }
    return min;
}

int main() {
    printf("Si programa apskaiciuos jusu ivestu skaiciu suma, vidurki, max bei min reiksmes\n");
    printf("visu pirma, iveskite, kiek noretumete ivesti skaiciu:\n");
    int n, inputValid;
    inputValid = scanf("%d", &n);

    if(inputValid != 1 || n <= 0){
        printf("Prasau paleiskite programa is naujo ir iveskite naturalu skaiciu\n");
        return 0;
    }
    printf("Dabar iveskite %d realiuosius skaicius:\n", n);

    double number[n];
    int inputValid1 = 0;

    int i = 0;
    while(i < n){
        inputValid = scanf("%lf", &number[i]);
        if(inputValid)
            inputValid1++;
        ++i;
    }

    if(inputValid1 == n)
        printf("Duomenys buvo ivesti teisingai\n");
    else{
        printf("Ivesdami duomenis padarete klaida, prasau paleiskite programa is naujo ir sekite nurodymus\n");
        return 0;
    }
    
    printf("skaiciu suma: %lf\n", sum(number, n));
    printf("skaiciu vidurkis: %lf\n", avg(number, n));
    printf("maksimali reiksme: %lf\n", numMax(number, n));
    printf("minimali reiksme: %lf\n", numMin(number, n));

    return 0;
}