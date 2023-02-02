#include <stdio.h>
#include <unistd.h>

#include "afisari.h"


void doSleep(int sec){
     #ifdef _WIN32
         Sleep(sec);
        #else 
            usleep(sec*1000*1000);
         #endif
 
}

void printBani(int bani){
    printf("Mai ai : %d lei\n\n\n\n", bani);
}

void printGameMenu(char nume[30]){
    for(int i=0;i<5;i++)
        printf("\n");

    printf("                    ---------------------------GAME MENU----------------------------- \n");
    printf("                    daca vrei sa bagi o pacanea %s, introdu 1, tine minte ca costa 10 lei \n", nume);
    printf("                                daca vrei sa pleci cu banii , apasa 0\n\n");

}

int imprumutaBaniDeLaCamatari(){
    
    int bani_camatari;
    
        printf("Ai ramas fara bani, daca vrei sa te imprumuti la CAMATARI spune-le suma pe care o vrei\n Daca nu, apasa 0\n");
        scanf("%d", &bani_camatari);
        return bani_camatari;
    
}

void printareFinala(int contor, int bani, int camata){

    if(contor!=0){
        printf("Ai iesit din cazino cu %d lei si cu o datorie de %d lei la camatari.\n Daca nu o platesti in 10 zile o sa vina dupa tine! ", bani, camata);
    }
     else{

            if(bani<10)
                printf("Nu mai ai bani sa joci asa ca ai plecat\n\n\n");

        printf("Ai iesit din cazino cu %d lei", bani);
    }

}