#include <stdio.h>
#include <assert.h>

int my_strcmp(const char str1[], const char str2[]);

int main(){
    // failed test: assert(my_strcmp("hey", "Hey") == 0);
    assert(my_strcmp("", " ") == 1);
    assert(my_strcmp("same", "same") == 0);
    return 0;
}


int my_strcmp(const char str1[], const char str2[]){
    int notEqual = 0;

    while(*str1){
        if(*str1 != *str2){
            notEqual = 1;
            break;
        }
        *str1++;
        *str2++;
    }

    if(*str1 != *str2){
        notEqual = 1;
    }

    return notEqual;
}
