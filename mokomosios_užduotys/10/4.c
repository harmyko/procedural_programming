#include <stdio.h>
#include <assert.h>

char *my_strchr(const char *ptr, char c){

    while(*ptr != 0){
        if(*ptr == c){
            return (char *)ptr;
        }

        ++ptr;
    }

    return NULL;
}

char *my_strchr(const char *ptr, char c);

int main(){
    char message[] = "Hello world!"; 
    // failed test: assert(my_strchr(message, 'o') == &message[2]);
    assert(my_strchr(message, 'l') == &message[2]);
    assert(my_strchr(message, 'p') == NULL);
    return 0;
}