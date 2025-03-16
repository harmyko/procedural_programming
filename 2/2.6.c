#include <stdio.h>
#include <math.h>

int minimumas(int a, int b){
    return (a + b - abs(a - b)) / 2; // grazinamas minimumas
}

int maksimumas(int a, int b){
    return (a + b + abs(a - b)) / 2; // grazinamas maksimumas
}

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("Maksimumas: %d\n Minimumas: %d", maksimumas(x, maksimumas(y, z)), minimumas(x, minimumas(y, z)));
    return 0;
}