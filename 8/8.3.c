#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(){
    int value1 = 5;
    int value2 = 7;
    int *a = &value1;
    int *b = &value2;

    printf("pre-swap: %d, %d\n", value1, value2);
    swap(a, b);
    printf("post-swap: %d, %d\n", value1, value2);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}