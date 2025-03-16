#include <stdio.h>

#define MAX_CAPACITY 100

long getFileSize(FILE *file);
int validateIndex(FILE *file, long index);
int getValue(FILE *file, long index);
int setValue(FILE *file, long index, char value);
int addValue(FILE *file, long index, char value);
int remValue(FILE *file, long index);

int main() {
    FILE *file = fopen("testfile.txt", "r+b");
    if(!file){
        printf("Failed to open file.\n");
        return -1;
    }

    char initialData[] = "Hello World!";
    fwrite(initialData, 1, sizeof(initialData) - 1, file); 
    fflush(file);

    char ch = getValue(file, 6); 
    if(ch != -1){
        printf("Character at index 6: %c\n", ch); 
    } 
    else{
        printf("Failed to get value.\n");
    }


    if(setValue(file, 6, 'M') == 0){
        printf("Successfully set value at index 6 to 'M'.\n");
    }
    else{
        printf("Failed to set value.\n");
    }

    if(addValue(file, 5, 'X') == 0){  
        printf("Successfully added value 'X' at index 5.\n");
    }
    else{
        printf("Failed to add value.\n");
    }

    if(remValue(file, 5) == 0){ 
        printf("Successfully removed value at index 5.\n");
    }
    else{
        printf("Failed to remove value.\n");
    }

    fclose(file);

    file = fopen("testfile.txt", "rb");
    if(!file){
        printf("Failed to reopen file.\n");
        return -1;
    }

    printf("Final file content:\n");
    char c;
    while(fread(&c, 1, 1, file)){
        printf("%c", c);
    }
    printf("\n");

    fclose(file);
    return 0;
}

// si funkcija gauna failo dydi baitais
long getFileSize(FILE *file){
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    return fileSize;
}


// si funkcija tikrina, ar tokia index reiksme egzistuoje faile
int validateIndex(FILE *file, long index){
    if((index >= getFileSize(file)) || (index < 0)){
        return 0;
    }
    return 1;
}

// a) funkcija getValue nuskaito faile file įrašytą skaičių, esantį index pozicijoje, kurį ir gražina
int getValue(FILE *file, long index){ 
    if(!validateIndex(file, index)){
        return -1;
    }
    
    fseek(file, index, SEEK_SET);
    int value;
    if(fread(&value, 1, 1, file) != 1){
        return -1;
    }
    fseek(file, 0, SEEK_SET);
    
    return value;
}

// b) funkcija setValue įrašo naują reikšmę value į failo file poziciją, nurodytą parametru index
int setValue(FILE *file, long index, char value){
    if(!validateIndex(file, index)){
        return -1;
    }

    fseek(file, index, SEEK_SET); 
    if(fwrite(&value, 1, 1, file) != 1){ // darome prielaida, jog failas buvo atidarytas skaytymui su uzrasu "r+b"
        fseek(file, 0, SEEK_SET);
        return -1;
    }
    fseek(file, 0, SEEK_SET);

    return 0;
}

// c) funkcija addValue įterpia naują reikšmę value į failo file poziciją, nurodytą parametru index
int addValue(FILE *file, long index, char value){
    if(!validateIndex(file, index)){
        return -1;
    }
    
    char buffer[MAX_CAPACITY];
    int fileSize = getFileSize(file);

    if(MAX_CAPACITY < fileSize - index){
        return -1;    
    }

    fseek(file, index, SEEK_SET);
    if(fread(buffer, 1, fileSize - index, file) != (fileSize - index)){
        return -1;
    }

    fseek(file, index, SEEK_SET);
    if(fwrite(&value, 1, 1, file) != 1){
        return -1;
    }

    if(fwrite(buffer, 1, fileSize - index, file) != (fileSize - index)){
        return -1;
    }

    return 0;
}

// d) funkcija remValue ištrina reikšmę iš failo file pozicijos index
int remValue(FILE *file, long index){
    if(!validateIndex(file, index)){
        return -1;
    }
    
    char buffer[MAX_CAPACITY];
    int fileSize = getFileSize(file);

    if(MAX_CAPACITY < fileSize - index){
        return -1;    
    }

    fseek(file, index, SEEK_SET);
    if(fread(buffer, 1, fileSize - index, file) != (fileSize - index)){
        return -1;
    }

    fseek(file, index, SEEK_SET);
    if(fwrite(buffer, 1, fileSize - index, file) != (fileSize - index)){
        return -1;
    }

    return 0;
}


