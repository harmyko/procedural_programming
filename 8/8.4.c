#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

int splitData(int data[], int sizeOfData, int sizeOfDataFirstPart, int **split1, int **split2);

int main(){
    int data[] = {1, 2, 3, 67, 5, 4, 9};
    int sizeOfData = sizeof(data) / sizeof(int);
    int sizeOfFirstSplit = 3;

    int *split1 = NULL;
    int *split2 = NULL;
    if(splitData(data, sizeOfData, sizeOfFirstSplit, &split1, &split2) == 0){

        printf("First split: ");
        for(int i = 0; i < sizeOfFirstSplit; ++i){
            printf("%d ", split1[i]);
        }

        printf("\nSecond split: ");
        for(int i = 0; i < sizeOfData - sizeOfFirstSplit; ++i){
            printf("%d ", split2[i]);
        }
    }
    else{
        printf("\nError: Invalid Data!");
    }

    return 0;
}

int splitData(int data[], int sizeOfData, int sizeOfFirstSplit, int **split1, int **split2){
    // Confirming the data[] input; if the adress is invalid, the value is NULL
    if(data == NULL){
        return -1;
    }

    // Confirming the sizeOfData input
    if((sizeOfData < 0) || (sizeOfData > MAX_CAPACITY)){
        return -1;
    }

    // Confirming the sizeOfFirstSplit input
    if((sizeOfFirstSplit < 0) || (sizeOfFirstSplit > sizeOfData)){
        return -1;
    }

    // Confirming the split1 and split2 pointers
    if((*split1 != NULL) || (*split2 != NULL)){
        return -1;
    }

    *split1 = (int*)malloc(MAX_CAPACITY * sizeof(int));
    if(*split1 == NULL){
        return -1;
    }

    *split2 = (int*)malloc(MAX_CAPACITY * sizeof(int));
    if(*split2 == NULL){
        return -1;
    }

    for(int i = 0; i < sizeOfFirstSplit; ++i){
        (*split1)[i] = data[i];
    }

    for(int i = 0; i < sizeOfData - sizeOfFirstSplit; ++i){
        (*split2)[i] = data[i + sizeOfFirstSplit];
    }

    return 0;
}