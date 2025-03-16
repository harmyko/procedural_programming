#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void saveToFile(const char *filename, int *arr, int size){
    FILE* file = fopen(filename, "wb");

    if(file == NULL){
        printf("Could not open the following file: %s\n", filename);
        return;
    }
    
    fwrite(&size, sizeof(int), 1, file);
    fwrite(arr, sizeof(int), size, file);

    fclose(file);
}

int *loadFromFile(const char *filename, int *size){
    FILE* file = fopen(filename, "rb");

    if(file == NULL){
        printf("Could not open the following file: %s\n", filename);
        return NULL;
    }
    
    fread(size, sizeof(int), 1, file);

    int *arr = (int *)malloc(*size * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed!\n");
        fclose(file);
        return NULL;
    }

    int elementsRead = fread(arr, sizeof(int), *size, file);
    if(elementsRead != *size){
        printf("Could not read data from the following file: %s\n", filename);
        fclose(file);
        free(arr);
        return NULL;
    }

    fclose(file);
    return arr;
}