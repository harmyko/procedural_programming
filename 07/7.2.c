#include <stdio.h>

int getFactorialWithRecursion(int number);
int getFactorialWithoutRecursion(int number);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", getFactorialWithoutRecursion(n));
    return 0;
}

int getFactorialWithRecursion(int number){
    if(number > 0){
        return number * getFactorialWithRecursion(number - 1);
    }
    else{
        return 1;
    }
}

int getFactorialWithoutRecursion(int number){
    int factorial = 1;
    while(number){
        factorial *= number--;
    }
    return factorial;
}