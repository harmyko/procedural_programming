#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

char *findBiggestFile(int argc, char *argv[]);
long getFileSize(char argv[]);

int main(int argc, char *argv[]){
    char *biggestFile = findBiggestFile(argc, argv);
    printf("%s", biggestFile);
    return 0;
}

char *findBiggestFile(int argc, char *argv[]){
    if(argc < 2){
        return NULL;
    }

    char *biggestFileName = NULL;
    long biggestFileSize = 0;
    for(int i = 1; i < argc; ++i){
        long fileSize = getFileSize(argv[i]);
        if(biggestFileSize <= fileSize){
            biggestFileName = argv[i];
            biggestFileSize = fileSize;
        }
    }
    return biggestFileName;
}

long getFileSize(char *argv){
    FILE *file = fopen(argv, "rb");
    if(file == NULL){
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    return fileSize;
}