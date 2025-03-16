#include <stdio.h>
#include <math.h>

double a_reiskinys(double x, double y, double z){
    double ats = x + 4 * y + pow(z, 3);
    return ats;
}

double b_reiskinys(double x, double y, double z){
    double ats = (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3);
    return ats;
}

int main(){
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("a) %f\n", a_reiskinys(x, y, z));
    printf("b) %f\n", b_reiskinys(x, y, z));
    return 0;
}