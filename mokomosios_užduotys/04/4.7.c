// char, short, int, long, signed, unsigned
// norint aptikti duomenu tipu rezius, sioje programoje vietoje to, kad to tipo kintamojo pridetume po 1, mes ji vis dauginsime is 2

#include <stdio.h>

signed minSigned(){
    signed x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        signed y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

signed maxSigned(){
    signed x = minSigned() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned minUnsigned(){
    unsigned x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 7;
}

unsigned maxUnsigned(){
    unsigned x = minUnsigned() - 1;
    return x;
}

char minChar(){
    char x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        char y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

char maxChar(){
    char x = minChar() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned char minUnsignedChar(){
    unsigned char x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned char y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned char maxUnsignedChar(){
    unsigned char x = minUnsignedChar() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

short minShort(){
    short x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        short y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

short maxShort(){
    short x = minShort() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned short minUnsignedShort(){
    unsigned short x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned short y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned short maxUnsignedShort(){
    unsigned short x = minUnsignedShort() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

short int minShortInt(){
    short int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        short int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

short int maxShortInt(){
    short int x = minShortInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned short int minUnsignedShortInt(){
    unsigned short int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned short int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned short int maxUnsignedShortInt(){
    unsigned short int x = minUnsignedShortInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

int minInt(){
    int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

int maxInt(){
    int x = minInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned int minUnsignedInt(){
    unsigned int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned int maxUnsignedInt(){
    unsigned int x = minUnsignedInt() - 1;
    return x;
}

long minLong(){
    long x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        long y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

long maxLong(){
    long x = minLong() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned long minUnsignedLong(){
    unsigned long x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned long y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned long maxUnsignedLong(){
    unsigned long x = minUnsignedLong() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

long int minLongInt(){
    long int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        long int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

long int maxLongInt(){
    long int x = minLongInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned long int minUnsignedLongInt(){
    unsigned long int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned long int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned long int maxUnsignedLongInt(){
    unsigned long int x = minUnsignedLongInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

long long minLongLong(){
    long long x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        long long y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

long long maxLongLong(){
    long long x = minLongLong() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned long long minUnsignedLongLong(){
    unsigned long long x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned long long y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned long long maxUnsignedLongLong(){
    unsigned long long x = minUnsignedLongLong() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

long long int minLongLongInt(){
    long long int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        long long int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

long long int maxLongLongInt(){
    long long int x = minLongLongInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

unsigned long long int minUnsignedLongLongInt(){
    unsigned long long int x = 1; // this number will be incremented by powers of 2 until it can no longer be displayed by this data type
    for(int i = 0; i < 100; ++i){
        unsigned long long int y = x; // this number is equal to x and will later be used for comparison purposes
        x *= 2;
        if(x < y)
            return x;
    }
    return 0;
}

unsigned long long int maxUnsignedLongLongInt(){
    unsigned long long int x = minUnsignedLongLongInt() - 1; // subtracting 1 from the minimum value will gives us the max
    return x;
}

int main(){
    printf("Si programa apsakiciuoja visu duomenu tipu rezius:\n\n");

    printf("signed:\t\t[%d; %d]\n", minSigned(), maxSigned());
    printf("unsigned:\t[%u; %u]\n\n", minUnsigned(), maxUnsigned());

    printf("------------------------signed------------------------------------------unsigned-----------------------\n");

    printf("char:\t\t\t[%d; %d]\t\t\t\t\t", minChar(), maxChar());
    printf("[%d; %d]\n", minUnsignedChar(), maxUnsignedChar());

    printf("short:\t\t\t[%d; %d]\t\t\t\t\t", minShort(), maxShort());
    printf("[%d; %d]\n", minUnsignedShort(), maxUnsignedShort());
    
    printf("short int:\t\t[%d; %d]\t\t\t\t\t", minShortInt(), maxShortInt());
    printf("[%d; %d]\n", minUnsignedShortInt(), maxUnsignedShortInt());

    printf("int:\t\t\t[%d; %d]\t\t\t", minInt(), maxInt());
    printf("[%u; %u]\n", minUnsignedInt(), maxUnsignedInt());

    printf("long:\t\t\t[%d; %d]\t\t\t", minLong(), maxLong());
    printf("[%u; %u]\n", minUnsignedLong(), maxUnsignedLong());

    printf("long int:\t\t[%d; %d]\t\t\t", minLongInt(), maxLongInt());
    printf("[%u; %u]\n", minUnsignedLongInt(), maxUnsignedLongInt());

    printf("long long:\t\t[%lld; %lld]\t", minLongLong(), maxLongLong());
    printf("[%llu; %llu]\n", minUnsignedLongLong(), maxUnsignedLongLong());

    printf("long long int:\t\t[%lld; %lld]\t", minLongLongInt(), maxLongLongInt());
    printf("[%llu; %llu]\n", minUnsignedLongLongInt(), maxUnsignedLongLongInt());

    return 0;
}