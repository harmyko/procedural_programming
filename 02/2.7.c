#include <stdio.h>
#include <math.h>

int skaitmenuKiekis(int skaicius){
    int skaitmenys = 0; // siame kintamajame yra talpinamas skaitmenu kiekis

    if(skaicius == 0)
        skaitmenys = 1;
    else{
        while(skaicius > 0){
            skaicius = skaicius / 10;
            skaitmenys ++;
        }
    }

    return skaitmenys;
}

int skaitmenuRikiavimas(int skaicius, int skaitmenys){
    for(int i = 0; i < skaitmenys - 1; i ++){
        for(int j = i + 1; j < skaitmenys; j ++){
            int q = 1, w = 1, e = 1, r = 1;

            for(int k = 0; k < i + 1; k++){
                q *= 10;
            }

            for(int k = 0; k < i; k++){
                w *= 10;
            }

            for(int k = 0; k < j + 1; k++){
                e *= 10;
            }

            for(int k = 0; k < j; k++){
                r *= 10;
            }

            int a = skaicius % q / w; // sio kintamojo verte yra lygi i + 1 skaitmeniui nuo desines
            int b = skaicius % e / r; // sio kintamojo verte yra lygi j + 1 skaitmeniui nuo desines

            if(a > b){
                skaicius = skaicius - (a * w) + (b * w); // pastatome j + 1 skaitmeni i i + 1 skaitmens vieta
                skaicius = skaicius - (b * r) + (a * r); // pastatome i + 1 skaitmeni i j + 1 skaitmens vieta
            }
        }
    }
    return skaicius;
}

int main(){
    int skaicius; // bet koks sveikas skaicius
    int skaitmenys; // skaiciaus skaitmenu kiekis
    int surikiuotiSkaitmenys; // skaiciaus versija, kai skaitmenys yra surikiuoti mazejimo tvarka

    printf("Iveskite bet koki sveika skaiciu ir programa surikiuos skaiciaus skaitmenis didejimo tvarka\n");
    scanf("%d", &skaicius); // nuskaitomas skaicius

    skaitmenys = skaitmenuKiekis(skaicius); // apskaiciuojamas skaitmenu kiekis
    surikiuotiSkaitmenys = skaitmenuRikiavimas(skaicius, skaitmenys); // surikiuojami skaitmenys mazejimo tvarka

    printf("Rezultatas: %d", surikiuotiSkaitmenys); // spauzdinamas skaicius su surikiuotais skaitmenimis

    return 0;
}