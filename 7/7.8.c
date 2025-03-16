#include <stdio.h>

#define MAX_ARRAY_CAPACITY 100

void quickSortRecursion(int *array, int min, int max);
void quickSortNoRecursion(int *array, int min, int max);
void swap(int *a, int *b);

int main(){

    // Testing the QuickSort with recursion function
    int array1[] = {8, 1, 5, 7, 8, 3, 4, 2, 5, 3, 7, 0, 5};
    int size1 = sizeof(array1) / sizeof(int);
    quickSortRecursion(array1, 0, size1 - 1);
    printf("\nArray sorted using QuickSort with recursion:\n");
    for(int i = 0; i < size1; ++i){
        printf("%d ", array1[i]);
    }

    // Testing the QuickSort without recursion function
    int array2[] = {8, 1, 5, 7, 8, 3, 4, 2, 5, 3, 7, 0, 5};
    int size2 = sizeof(array2) / sizeof(int);
    quickSortNoRecursion(array2, 0, size2 - 1);
    printf("\n\nArray sorted using QuickSort without recursion:\n");
    for(int i = 0; i < size2; ++i){
        printf("%d ", array2[i]);
    }

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortRecursion(int *array, int min, int max){
    if(min < max){
        int p = array[min];
        int i = min;
        int j = max;

        while(i < j){
            while((array[i] <= p) && (i <= max - 1)){
                ++i;
            }

            while((array[j] > p) && (j >= min + 1)) {
            --j;
            }

            if(i < j){
                swap(&array[i], &array[j]);
            }
        }

        swap(&array[min], &array[j]);
        int partitionIndex = j;

        quickSortRecursion(array, min, partitionIndex - 1);
        quickSortRecursion(array, partitionIndex + 1, max);
    }
}

void quickSortNoRecursion(int *array, int min, int max){

    // in lecture #7 the usage of variable length arrays were discussed
    // in this function I wanted to try using them for the first time
    // however it's necessary that the variable value is not too high, since it can cause the program to crash
    if((max - min + 1) > MAX_ARRAY_CAPACITY){
        printf("The array has too many elements!"
        "This program can only handle arrays with up to %d elements.", MAX_ARRAY_CAPACITY);
        return;
    }

    int stack[max - min + 1];
    int top = -1;

    stack[++top] = min;
    stack[++top] = max;

    while (top >= 0) {
        max = stack[top--];
        min = stack[top--];

        int p = array[min];
        int i = min;
        int j = max;

        while (i < j) {
            while ((array[i] <= p) && (i < max)) {
                ++i;
            }
            while ((array[j] > p) && (j > min)) {
                --j;
            }
            if (i < j) {
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[min], &array[j]);
        int partitionIndex = j;

        if (partitionIndex - 1 > min) {
            stack[++top] = min;
            stack[++top] = partitionIndex - 1;
        }

        if (partitionIndex + 1 < max) {
            stack[++top] = partitionIndex + 1;
            stack[++top] = max;
        }
    }
}