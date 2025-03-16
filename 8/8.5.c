#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 100

char ***createStringArray2D(int row, int column);
int writeString(char ***array, int row, int column, char input[]);
char *getString(char ***array, int row, int column);
void wipeArray(char ***array, int row, int column);

int main(){
    int n = 3, m = 5;
    char ***array = createStringArray2D(n, m);

    printf("a) A two-dimensional array of strings has been created and all the values have been set to 0:\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%s ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    char msg[] = "yeah";
    writeString(array, 2, 3, msg);

    printf("b) Instead of NULL, at line n and column m there is now a string!:\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%s ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("c) Getting the string located at provided coordinates:\n%s", getString(array, 2, 3));

    wipeArray(array, n, m);

    printf("\n\nc) Array wiped.");

    return 0;
}

//a) apibrėžkite funkciją, leidžiančią sukurti dvimatį eilučių masyvą dinaminėje atmintyje, su n eilučių ir m stulpelių; visus
//   elementus nustatykite lygius 0 (NULL)
char ***createStringArray2D(int row, int column){
    char ***newArray = (char***)malloc(row * sizeof(char*));
    if(newArray == NULL){
        return NULL;
    }

    for(int i = 0; i < row; ++i){
        newArray[i] = (char**)calloc(column, sizeof(char*));
    }
    
    return newArray;
}

//b) apibrėžkite funkciją, leidžiančią įrašyti (naują) eilutę į ląstelę, esančią į-ojoje eilutėje ir j-ajame stulpelyje; funkcija
//   gauna pozicijas ir eilutę, tada išskiria atminties bloką į kurį ir nukopijuoja perduotos eilutės turinį
int writeString(char ***array, int row, int column, char input[]){
    int length = strlen(input) + 1;
    array[row-1][column-1] = (char*)malloc(length * sizeof(char));
    if(array[row-1][column-1] == NULL){
        return -1;
    }
    strcpy(array[row-1][column-1], input);
    return 0;
}

//c) apibrėžkite funkciją, leidžiančią gauti (grąžinti) į-ojoje eilutėje ir j-ajame stulpelyje esančios eilutės turinį
char *getString(char ***array, int row, int column){
    return array[row - 1][column - 1];
}

//d) apibrėžkite funkciją, leidžiančią sunaikinti dvimatį masyvą kartu su visomis (dinamiškai sukurtomis) jo viduje
//   esančiomis eilutėmis
void wipeArray(char ***array, int row, int column){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}