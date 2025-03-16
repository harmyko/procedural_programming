#include <stdio.h>

long getFileSize(char *fileName);

int main(){
    char fileName[] = "7.1.c";
    printf("%ld", getFileSize(fileName));
    return 0;
}

long getFileSize(char *fileName){
    FILE *file = fopen(fileName, "rb");
    if(file == NULL){
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    return fileSize;
}