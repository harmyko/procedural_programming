#include <stdio.h>
#include <string.h>
#include <math.h>

int dvejetaineIDesimtaine(char dvejetainesSistemosSkaicius[]){
    int desimtainesSistemosSkaicius = 0;
    int dvejetainesSistemosSkaiciausIlgis = strlen(dvejetainesSistemosSkaicius);

    for (int i = 0; i < dvejetainesSistemosSkaiciausIlgis; i++) {
        if (dvejetainesSistemosSkaicius[i] == '1') {
            desimtainesSistemosSkaicius += pow(2, dvejetainesSistemosSkaiciausIlgis - 1 - i);
        }
    }
    return desimtainesSistemosSkaicius;
}

void desimtaineIDvejetaine(int desimtainesSistemosSkaicius){
    char dvejetainesSistemosSkaicius[100];
    
    if(desimtainesSistemosSkaicius == 0)
        printf("0"); // atveji, kai skaicius yra lygus 0, sutvarkome atskirai
    else{
        int dvejetainesSistemosSkaicius[100];
        int dvejetainesSistemosSkaiciausIlgis = 0;

        // paverciame desimtaines sistemos skaiciu i atbulos tvarkos dvejetaines sistemos skaiciu
        while (desimtainesSistemosSkaicius > 0) {
            dvejetainesSistemosSkaicius[dvejetainesSistemosSkaiciausIlgis++] = desimtainesSistemosSkaicius % 2;
            desimtainesSistemosSkaicius /= 2;
   }
   
        // isspauzdiname dvejetaines skaiciavimo sistemos skaiciu teisinga eiles tvarka
        for (int j = dvejetainesSistemosSkaiciausIlgis-1; j >= 0; j--)
             printf("%d", dvejetainesSistemosSkaicius[j]);
        }
              printf("\n");
 }

int main(){
    int konversijosTipas = 0;

    printf("Si programa atliks skaiciu konversija is vienos pozicines skaiciavimo sistemos i kita.\n");
    printf("Visu pirma, pasirinkite, kokia skaiciu konversija norite atlikti, ivesdami skaiciu 1, 2, 3 arba 4:\n");

    pradzia:
    printf("1) is dvejetaines i desimtaine\n");
    printf("2) is desimtaines i dvejetaine\n");
    printf("3) is sesioliktaines i desimtaine\n");
    printf("4) is desimtaines i sesioliktaine\n");

    while((konversijosTipas != 1) && (konversijosTipas != 2) && (konversijosTipas != 3) && (konversijosTipas != 4)){
        scanf("%d", &konversijosTipas);
        if((konversijosTipas != 1) && (konversijosTipas != 2) && (konversijosTipas != 3) && (konversijosTipas != 4)){
            printf("Jusu ivestas skaicius neatitinka nurodymu!\n");
            printf("Prasau iveskite skaiciu nuo 1 iki 4 imtinai.\n");
        }
    }

    if(konversijosTipas == 1){
        printf("Jus pasirinkote skaiciu konversija is dvejetaines skaiciavimo sistemos i desimtaine.\n");
        printf("Iveskite dvejetaines skaiciavimo sistemos skaiciu.\n");

        char dvejetainesSistemosSkaicius[100];

        scanf("%s", &dvejetainesSistemosSkaicius);

        int desimtainesSistemosSkaicius = dvejetaineIDesimtaine(dvejetainesSistemosSkaicius);
        printf("%d", desimtainesSistemosSkaicius);
    }

    if(konversijosTipas == 2){
        printf("Jus pasirinkote skaiciu konversija is desimtaines skaiciavimo sistemos i dvejetaine.\n");
        printf("Iveskite desimtaines skaiciavimo sistemos skaiciu.\n");

        int desimtainesSistemosSkaicius;

        scanf("%d", &desimtainesSistemosSkaicius);
        desimtaineIDvejetaine(desimtainesSistemosSkaicius); 
        }

    if(konversijosTipas == 3){
        printf("Jus pasirinkote skaiciu konversija is sesioliktaines skaiciavimo sistemos i desimtaine.\n");
        printf("Iveskite sesioliktaines skaiciavimo sistemos skaiciu.\n");

        int skaicius;

        scanf("%x", &skaicius);
        printf("%d\n", skaicius);
    }

    if(konversijosTipas == 4){
        printf("Jus pasirinkote skaiciu konversija is desimtaines skaiciavimo sistemos i sesioliktaine.\n");
        printf("Iveskite desimtaines skaiciavimo sistemos skaiciu.\n");

        int skaicius;

        scanf("%d", &skaicius);
        printf("%x\n", skaicius);
    }

    konversijosTipas = 0;
    printf("Pasirinkite, ka norite daryti toliau: \n");
    printf("1) skaiciuoti vel\n");
    printf("2) iseiti is programos\n");
    int kadaryt = 0;
    scanf("%d", &kadaryt);

    if(kadaryt == 1){
        printf("Pasirinkite, kokio tipo konversija norite atlikti\n");
        goto pradzia;
    }
    return 0;
}