#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

void generateArray(int data[], int size, int low, int high);
int* createArray(int size, int low, int high);

int main(){
    int size = 3;
    int low = 5;
    int high = 20;
    int *ptrArray = createArray(size, low, high);
    for(int i = 0; i < size ; ++i){
        printf("%d\n", ptrArray[i]);
    }
    return 0;
}

int* createArray(int size, int low, int high){
    if(size > MAX_CAPACITY){
        return NULL;
    }

    int *array = (int*)malloc(size * sizeof(int));
    if(array == NULL){
        return NULL;
    }

    generateArray(array, size, low, high);

    return array;
}

void generateArray(int *data, int size, int low, int high){
    srand(time(0));
    for(int i = 0; i < size; ++i){
       data[i] = low + rand() % ((high + 1) - low);
    }
    return;
}