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
 #include "functionarepacanea.h"

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