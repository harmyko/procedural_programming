#include <stdio.h>

int isInRange(int number, int low, int high);

int main(){
    printf("%d", isInRange(14, 10, 14));
    return 0;
}

int isInRange(int number, int low, int high){
    if((number >= low) && (number <= high)){
        return 1;
    }
    return 0;
}