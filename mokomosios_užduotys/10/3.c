#include <stdio.h>
#include <assert.h>

int my_strncmp(const char str1[], const char str2[], int n);

int main(){
    // failed test: assert(my_strncmp("hey", "hey", 4) == 1);
    assert(my_strncmp("a", "b", 1) == 1);
    assert(my_strncmp("", "a", 0) == 0);
    assert(my_strncmp("samE", "same", 3) == 0);
    assert(my_strncmp("abc", "abc", 3) == 0);

    return 0;
}


int my_strncmp(const char str1[], const char str2[], int n){
    int notEqual = 0;

    while(n--){
        if(*str1 != *str2){
            notEqual = 1;
            break;
        }
        else if((*str1 == *str2) && (*str1 == 0)){
            break;
        }

        *str1++;
        *str2++;
    }

    return notEqual;
}
