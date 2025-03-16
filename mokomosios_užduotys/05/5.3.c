#include <stdio.h>

int main(){
    int n, s, count = 0;
    printf("Si programa apskaiciuos visas teigiamas ivesto masyvo skaiciu poras, kuriu sandauga sudaro ivesta skaiciu.\n");
    int noValidInput = 1;
    while(noValidInput){
        printf("Iveskite, kokia sandaugos reiksme norite gauti: ");
        int inputValid = scanf("%d", &s);
        if(inputValid == 1){
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
        else{
            printf("Duomenys buvo ivesti klaidingai, bandykite dar karta!\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
    }

    noValidInput = 1;
    while(noValidInput){
        printf("Iveskite, kokio dydzio bus masyvas: ");
        int inputValid = scanf("%d", &n);
        if((n < 1) || (inputValid != 1)){
            printf("Duomenys buvo ivesti neteisingai! Masyvo talpa privalo buti bent vieno elemento dydzio, bandykite dar karta...\n");
            int temp;
            while((temp = getchar()) != '\n');
        }
        else{
            printf("Duomenys buvo nuskaityti sekmingai!\n");
            noValidInput = 0;
        }
    }

    int x[n];

    for(int i = 0; i < n; ++i){
        noValidInput = 1;
        while(noValidInput){
            printf("Iveskite %d-ojo masyvo elemento reiksme: ", i + 1);
            int inputValid = scanf("%d", &x[i]);
            if((x[i] <= 0) || (inputValid != 1)){
                printf("Jusu ivestas skaicius neatitinka reikalavimu, jo reiksme privalo buti teigiama! Bandykite dar karta...\n");
                int temp;
                while((temp = getchar()) != '\n');
            }
            else{
                printf("Duomenys buvo nuskaityti sekmingai!\n");
                noValidInput = 0;
            }
        }
    }

    printf("Masyvo elementu poros, kuriu sandauga sudaro skaiciu %d: \n", s);
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(x[i] * x[j] == s){
                printf("(%d, %d)\n", x[i], x[j]);
                ++count;
            }
        }
    }

    if(count == 0){
        printf("Masyvas neturi tokiu elementu poru, kurios sudarytu skaiciu %d.", s);
    }

    return 0;
}