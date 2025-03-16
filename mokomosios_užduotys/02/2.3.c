#include <stdio.h>

int main(){
    int skaicius;
    scanf("%d", &skaicius);
    printf("%d", (skaicius % 2 == 0) ? "lyginis" : "nelyginis");
    return 0;
}