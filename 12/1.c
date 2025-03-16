#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *arr, int size);
int isSorted(int *arr, int size);
void quicksort(int *arr, int min, int max);
void swap(int *a, int *b);
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);
void merge(int *arr, int left, int mid, int right);
void mergeSort(int *arr, int left, int right);

unsigned bubblesortOperations = 0;
unsigned quicksortOperations = 0;
unsigned insertionsortOperations = 0;
unsigned selectionsortOperations = 0;
unsigned mergesortOperations = 0;

int main(){
    int arr[10];
    int size = 10;
    fillArray(arr, size);
    else{
        int arr1[10], arr2[10], arr3[10], arr4[10];
        for(int i = 0; i < 10; ++i){
            arr1[i] = arr[i];
            arr2[i] = arr[i];
            arr3[i] = arr[i];
            arr4[i] = arr[i];
        }

        bubbleSort(arr, size);
        quicksort(arr1, 0, size - 1);
        insertionSort(arr2, size);
        selectionSort(arr3, size);
        mergeSort(arr4, 0, size - 1);

        if(isSorted(arr, size)){
            printf("bubbleSort all good\n");
            printf("Operation count: %u\n\n", bubblesortOperations);
        }
        else{
            printf("bubbleSort not good\n");
        }

        if(isSorted(arr1, size)){
            printf("quicksort all good\n");
            printf("Operation count: %u\n\n", quicksortOperations);
        }
        else{
            printf("quicksort not good\n");
        }
        
        if(isSorted(arr2, size)){
            printf("insertionSort all good\n");
            printf("Operation count: %u\n\n", insertionsortOperations);
        }
        else{
            printf("insertionSort not good\n");
        }
        
        if(isSorted(arr3, size)){
            printf("selectionSort all good\n");
            printf("Operation count: %u\n\n", selectionsortOperations);
        }
        else{
            printf("selectionSort not good\n");
        }
        
        if(isSorted(arr4, size)){
            printf("mergeSort all good\n");
            printf("Operation count: %u\n\n", mergesortOperations);
        }
        else{
            printf("mergeSort not good\n");
        }
        
    }

    return 0;
}

void fillArray(int *arr, int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        arr[i] = rand();
    }
}

int isSorted(int *arr, int size){
    for(int i = 1; i < size; ++i){
        if(arr[i] < arr[i - 1]){
            return 0;
        }
    }
    return 1;
}

void quicksort(int *array, int min, int max){
    if(min < max){
        int p = array[min];
        int i = min;
        int j = max;

        while(i < j){
            while((array[i] <= p) && (i <= max - 1)){
                ++i;
                ++quicksortOperations;
            }

            while((array[j] > p) && (j >= min + 1)) {
                --j;
                ++quicksortOperations;
            }

            if(i < j){
                swap(&array[i], &array[j]);
                ++quicksortOperations;
            }
        }

        swap(&array[min], &array[j]);
        ++quicksortOperations;
        int partitionIndex = j;

        quicksort(array, min, partitionIndex - 1);
        quicksort(array, partitionIndex + 1, max);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                ++bubblesortOperations;
            }
        }
    }
}

void insertionSort(int *arr, int size){
    int i, j;
    for(i = 1; i < size; i++){
        for(j = i; j > 0 && arr[j - 1] > arr[j]; j--){
            swap(&arr[j], &arr[j - 1]);
            ++insertionsortOperations;
        }
    }
}

void selectionSort(int *arr, int size){
    int i, j, minIndex;
    for(i = 0; i < size - 1; i++){
        minIndex = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
                ++selectionsortOperations;
            }
        }
        if(i != minIndex){
            swap(&arr[i], &arr[minIndex]);
            ++selectionsortOperations;
        }
    }
}

void merge(int *arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
        ++mergesortOperations;
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
        ++mergesortOperations;
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        ++mergesortOperations;
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
        ++mergesortOperations;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
        ++mergesortOperations;
    }
}

void mergeSort(int *arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
