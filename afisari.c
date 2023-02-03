#include <stdio.h>
#include <unistd.h>

#include "afisari.h"

/*! Functie pentru a da delay in program la afisari pentru estetica */
void doSleep(int sec){
     #ifdef _WIN32
         Sleep(sec);
        #else 
            usleep(sec*1000*1000);
         #endif
 
}

/*! Functie pentru a afisa banii (scorul) actuali ai userului  */
void printBani(int bani){
    printf("Mai ai : %d lei\n\n\n\n", bani);
}

/*! Functie pentru printarea meniului in program */
void printGameMenu(char nume[30]){
    for(int i=0;i<5;i++)
        printf("\n");

    printf("                    ---------------------------GAME MENU----------------------------- \n");
    printf("                    daca vrei sa bagi o pacanea %s, introdu 1, tine minte ca costa 10 lei \n", nume);
    printf("                                daca vrei sa pleci cu banii , apasa 0\n\n");

}


/*! Functie de a ii reumple fondurile jucatorului printr un imprumut la "camatari" pentru a continua programul */
int imprumutaBaniDeLaCamatari(char nume[30]){
    
    int bani_camatari;
    
        printf("%s ai ramas fara bani, daca vrei sa te imprumuti la CAMATARI spune-le suma pe care o vrei\n Daca nu, apasa 0\n", nume);
        scanf("%d", &bani_camatari);
        return bani_camatari;
    
}

/*! Functie pentru a afisa starea finala a userului(scorul)  */
void printareFinala(int contor, int bani, int camata, char nume[30], int baniinitiali){

    if(contor!=0){
        printf("%s, ai intrat in cazino cu %d lei si ai iesit din cazino cu %d lei si cu o datorie de %d lei la camatari.\n Daca nu o platesti in 10 zile o sa vina dupa tine! ",nume,baniinitiali,  bani, camata);
    }
     else{

            if(bani<10)
                printf("Nu mai ai bani sa joci asa ca ai plecat\n\n\n");

        printf("%s, ai intrat in cazino cu %d lei si ai iesit din cazino cu %d lei\n\nAlte persoane au iesit din cazino cu un castig de bani astfel: \n", nume,baniinitiali, bani);
    }

}