#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <unistd.h>

#include "afisari.h"
#include "fisiere.h"


int dubleazaBanii(int bani, int contor, int pierdere, int castig){
   
   srand(time(NULL));
   int RsauN, alegereaTa;
   printBani(bani);
   printf("Daca vrei sa dublezi apasa 0, daca nu, apasa 1 \n");
   scanf("%d",&alegereaTa);


   if(alegereaTa==1)
    return bani;
   
   
   if(alegereaTa==0){

      printf("Pentru ROSU alege 0, pentru NEGRU alege 1\n");
      scanf("%d", &alegereaTa);

      RsauN=rand()%2;

     if(RsauN==1){
        doSleep(1);
         printf("\nNEGRU\n");
        fflush(stdout); 
         }
     if(RsauN==0){
       doSleep(1);
        printf("\nROSU\n");
       fflush(stdout);
        }
      if(alegereaTa==RsauN){
        printf("BRAVO, AI CASTIGAT\n");
        contor++;
        bani= pierdere + castig* pow(2, contor);
        
       return dubleazaBanii(bani, contor, pierdere, castig);
      }


     if(alegereaTa!=RsauN){
        doSleep(1);
        printf("Ai Pierdut\n");
        fflush(stdout);
        bani=pierdere;
        return bani;
     }

   }
   return bani;
 
}

int utilizarePacanea( int bani ){

    srand(time(NULL));
    int nr1, nr2, nr3;
    int contorDublaj=0;
    int castig=0;
    int BaniInainteDeDublaj=0;
    
    nr1=(int)rand()%10;
    nr2=(int)rand()%10;
    nr3=(int)rand()%10;
     
     printf("\n\n\n                                               ");
     printf("%d ", nr1);
     fflush(stdout);
     doSleep(1);
     printf("%d ", nr2);
     fflush(stdout);
     doSleep(1);
     printf("%d", nr3);
     fflush(stdout);
     printf("  \n\n");
    
        if(nr1==nr2 && nr1==nr3 && nr1==7){
            printf("                                            JACKPOT\n");
            castig=7000;
            BaniInainteDeDublaj=bani;
            bani+=castig;
            bani=dubleazaBanii(bani, contorDublaj, BaniInainteDeDublaj, castig);
        }
            else if(nr1==nr2 && nr1==nr3){
                printf("                                 BRAVO, AI CASTIGAT 1000 DE LEI\n");
            castig=1000;
                BaniInainteDeDublaj=bani;
                bani+=castig;
                bani=dubleazaBanii(bani, contorDublaj, BaniInainteDeDublaj, castig);
            }
                else if(nr1==nr2 || nr2==nr3 || nr3==nr1 ){
                    castig=5;
                    BaniInainteDeDublaj=bani;
                    bani+=castig;
                    bani=dubleazaBanii(bani, contorDublaj, BaniInainteDeDublaj, castig);
                }

        

    
        
        return bani;
}


//fct afisare recorder

int main(){

  int BaniiTai, jocul=1, contor=0, camata=0, restCamata=0;
  char nume[30];
  fflush(stdin);
 printf("Introdu usernameul: ");
  scanf("%s", nume); 

  

    BaniiTai = citire_din_fisier(nume);
      
  

  while(jocul==1 && BaniiTai>=10){

   printGameMenu(nume);
   printBani(BaniiTai);

   scanf("%d", &jocul);

   for(int i=0; i<40; i++)
        printf("\n");

    if(jocul==1){
        BaniiTai-=10;
        BaniiTai = utilizarePacanea(BaniiTai);
   }

    if(BaniiTai<10){

        restCamata=BaniiTai;
        BaniiTai+=imprumutaBaniDeLaCamatari();
        camata += BaniiTai - restCamata;
        contor++;
    }

  }
    scriere_fisier(nume , BaniiTai, camata);
    printareFinala(contor, BaniiTai, camata);

    return 0;
}