#include <stdio.h>
#include <assert.h>

int my_memcmp(const void *ptr1, const void *ptr2, int n);

int main(){
    char buffer1[] = "hello";
    char buffer2[] = "hello";
    // failed test: assert(my_memcmp(buffer1, buffer2, 3) > 0);
    assert(my_memcmp(buffer1, buffer2, 5) == 0);

    char buffer3[] = "abc";
    char buffer4[] = "abd";
    assert(my_memcmp(buffer3, buffer4, 3) < 0); 

    char buffer5[] = "abcd";
    char buffer6[] = "abc";
    assert(my_memcmp(buffer5, buffer6, 4) > 0);
    return 0;
}

int my_memcmp(const void *ptr1, const void *ptr2, int n){
    unsigned char *p1 = (unsigned char *)ptr1;
    unsigned char *p2 = (unsigned char *)ptr2;

    for (int i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (p1[i] - p2[i]);
        }
    }

    return 0;
}

