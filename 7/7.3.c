#include <stdio.h>

char msg[] = "Iveskite teigiama skaiciu >> ";

int getPositiveNumber(char *msg);


int main(){
    printf("%d", getPositiveNumber(msg));
    return 0;
}

int getPositiveNumber(char *msg){
    int validInput = 0;
    int number = 0;
    while(!validInput){
        printf("%s", msg);
        char character = 0;
        if((scanf("%9d%c", &number, &character) == 2) && (character == '\n')){
            if(number > 0){
                validInput = 1;
            }
        }
        else{
            while(getchar() != '\n');
        }
    }
    return number;
}
