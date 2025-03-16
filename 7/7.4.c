#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high);

int main(){
    int data[10];
    generateArray(data, 10, 5, 25);
    return 0;
}

void generateArray(int data[], int size, int low, int high){
    srand(time(0));
    for(int i = 0; i < size; ++i){
       data[i] = low + rand() % ((high + 1) - low);
       printf("%d\n", data[i]);
    }
    return;
}