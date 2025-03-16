#include <stdio.h>
#include <assert.h>

int my_strlen(const char str[]);

int main(){

    // assert(my_strlen("this a failed test") == 3);
    assert(my_strlen("1234") == 4);
    assert(my_strlen("") == 0);

    return 0;
}

int my_strlen(const char str[]){
    int length = 0;
    while(*str++ != '\0'){
        ++length;
    }
    return length;
}

