#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "file.h"

void fillArray(int *arr, int size);
void printArray(int *arr, int size);

int main(){
    int size_m1 = 10;
    int size_m2 = 10;
    int size_m3 = 10;
    const char filename1[] = "failas.bin";
    const char filename2[] = "yeah.bin";

    int *m1 = (int *)malloc(size_m1 * sizeof(int));
    int *m2 = (int *)malloc(size_m2 * sizeof(int));
    int *m3 = (int *)malloc(size_m3 * sizeof(int));
    
    saveToFile(filename1, m1, size_m1);
    saveToFile(filename1, m3, size_m3);

    size_m1 += size_m3;
    m1 = loadFromFile(filename1, &size_m1);
    saveToFile(filename2, m2, size_m2);
    m3 = loadFromFile(filename2, &size_m2);
    m2 = loadFromFile(filename1, &size_m2);


    if((readCount == 3) && (writeCount == 3)){
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