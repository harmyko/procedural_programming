#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "file.h"

void fillArray(int *arr, int size);
void printArray(int *arr, int size);

int main(){
    int size_m1 = 10;
    int *m1 = (int *)malloc(sizeof(int) * size_m1);
    fillArray(m1, size_m1);
    printArray(m1, size_m1);
    saveToFile("failas.bin", m1, size_m1);
    int size_m2 = 0;
    int *m2 = loadFromFile("failas.bin", &size_m2);
    printArray(m2, size_m2);

    int areEqual = 1;
    if(size_m1 == size_m2){
        for(int i = 0; i < size_m1; ++i){
            if(m1[i] != m2[i]){
                areEqual = 0;
                break;
            }
        }
    }
    else{
        areEqual = 0;
    }

    if(areEqual = 1){
        printf("all good");
    }
    else{
        printf("something's wrong");
    }

    return 0;
}

void fillArray(int *arr, int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        arr[i] = rand();
    }
}

void printArray(int *arr, int size){
    printf("Array elements:\n");
    for(int i = 0; i < size; ++i){
        printf("%d. %d\n", i + 1, arr[i]);
    }
}