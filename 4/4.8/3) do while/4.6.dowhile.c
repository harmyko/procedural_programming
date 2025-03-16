#include <stdio.h>
#include <math.h>

int countDigits(double number){
    int digits = 0; // the entered number will have at least 1 digit

    // counting the amount of digits before the decimal point
    int numberDecimal = (int)number;

    if(numberDecimal == 0)
    digits++;

    do{
        ++digits;
        numberDecimal /= 10;
    } while(numberDecimal > 0);

    // counting the amount of digits after the decimal point
    // this program will give incorrect answers if the entered number has more than 10 digits after the decimal point
    int startCount = 0;
    int precision = 10; // only 10 digits after the decimal will be checked

    double fractionalPart = number - (int)number;

    int i = precision;
    do{
        int fractionDigit = ((int)(fractionalPart * pow(10, i))) % 10; // the i-th digit is stored as an int

        if((startCount == 0) && (fractionDigit != 0))
            startCount = 1; // only start counting when a digit that's not 0 is detected

        if(startCount == 1)
            ++digits;
            
        --i;
    } while(i > 0);
    printf("%d skaitmenys\n", digits);
    return digits;
}

int main(){
    printf("Iveskite sveiku teigiamuju skaiciu seka, pazymekite jos pabaiga neteigiamu skaiciumi ir si programa atras daugiausiai skaitmenu turinti skaiciu\n");
    double number;
    int counter; // counts the amount of positive entries
    double numberWithMaxDigits; // stores the value of the number with most digits
    int maxDigits = 0; // keeps track of the amount of digits of the number with most digits

    scanf("%lf", &number);
    do{
        counter++;
        int numberDigits = countDigits(number);
        if(numberDigits > maxDigits){
            maxDigits = numberDigits;
            numberWithMaxDigits = number;
        }
        scanf("%lf", &number);
    } while(number > 0);

    printf("%d skaiciai buvo sekmingai ivesti\n", counter);
    printf("Skaicius su daugiausiai skaitmenu yra: %.10f", numberWithMaxDigits);

    return 0;
}