#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

// sa rezolv  ctime

void PrintBani(int bani){
    printf("Mai ai : %d lei\n\n\n\n", bani);
}

void GameMenu(){
    for(int i=0;i<5;i++)
        printf("\n");

    printf("                    ---------------------------GAME MENU----------------------------- \n");
    printf("                    daca vrei sa bagi o pacanea, introdu 1, tine minte ca costa 10 lei \n");
    printf("                                daca vrei sa pleci cu banii , apasa 0\n\n");

}

int Camatari(){

    int bani_camatari;

        printf("Ai ramas fara bani, daca vrei sa te imprumuti la CAMATARI spune-le suma pe care o vrei\n Daca nu, apasa 0\n");
        scanf("%d", &bani_camatari);
        return bani_camatari;

}

int Dublaj(int bani, int contor, int pierdere, int castig){

   srand(time(NULL));
   int RsauN, alegereaTa;
   PrintBani(bani);
   printf("Daca vrei sa dublezi apasa 0, daca nu, apasa 1 \n");
   scanf("%d",&alegereaTa);


   if(alegereaTa==1)
    return bani;


   if(alegereaTa==0){

      printf("Pentru ROSU alege 0, pentru NEGRU alege 1\n");
      scanf("%d", &alegereaTa);

      RsauN=rand()%2;

     if(RsauN==1)
         printf("\nNEGRU\n");
     if(RsauN==0)
        printf("\nROSU\n");

      if(alegereaTa==RsauN){
        printf("BRAVO, AI CASTIGAT\n");
        contor++;
        bani= pierdere + castig* pow(2, contor);

       return Dublaj(bani, contor, pierdere, castig);
      }


     if(alegereaTa!=RsauN){
        printf("Ai Pierdut\n");
        bani=pierdere;
        return bani;
     }

   }


}

int Pacanea( int banii ){

    srand(time(NULL));
    int nr1, nr2, nr3;
    int contorDublaj=0;
    int castig=0;
    int BaniInainteDeDublaj=0;

    nr1=(int)rand()%10;
    nr2=(int)rand()%10;
    nr3=(int)rand()%10;

     //printf("\n\n\n                                               ");
     //sleep(10);
     printf("%d  ", nr2);
     sleep(3);
     fflush(stdout);
     printf("%d  ", nr1);
     sleep(3);
     fflush(stdout);
     printf("%d", nr3);
     printf("  \n\n");

        if(nr1==nr2 && nr1==nr3 && nr1==7){
            printf("                                            JACKPOT\n");
            castig=7000;
            BaniInainteDeDublaj=banii;
            banii+=castig;
            banii=Dublaj(banii, contorDublaj, BaniInainteDeDublaj, castig);
        }
        else if(nr1==nr2 && nr1==nr3){
            printf("                                 BRAVO, AI CASTIGAT 1000 DE LEI\n");
           castig=1000;
            BaniInainteDeDublaj=banii;
            banii+=castig;
            banii=Dublaj(banii, contorDublaj, BaniInainteDeDublaj, castig);
        }
        else if(nr1==nr2 || nr2==nr3 || nr3==nr1 ){
             castig=5;
            BaniInainteDeDublaj=banii;
            banii+=castig;
            banii=Dublaj(banii, contorDublaj, BaniInainteDeDublaj, castig);
        }





        return banii;
}


int main(){

  int BaniiTai, jocul=1, contor=0, camata=0, restCamata=0;

  printf("\n\n\nIntrodu suma de bani cu care intrii in cazino\n");
  scanf("%d", &BaniiTai);


  while(jocul==1 && BaniiTai>=10){

   GameMenu();
   PrintBani(BaniiTai);
   scanf("%d", &jocul);
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    if(jocul==1){
        BaniiTai-=10;
        BaniiTai = Pacanea(BaniiTai);
   }

    if(BaniiTai<10){

        restCamata=BaniiTai;
        BaniiTai+=Camatari();
        camata += BaniiTai - restCamata;
        contor++;
    }

  }


    if(contor!=0){
        printf("Ai iesit din cazino cu %d lei si cu o datorie de %d la camatari.\n Daca nu o platesti in 10 zile o sa vina dupa tine! ", BaniiTai, camata);
    }
    else{

            if(BaniiTai<10)
                printf("Nu mai ai bani sa joci asa ca ai plecat\n\n\n");

        printf("Ai iesit din cazino cu %d lei", BaniiTai);
    }

    return 0;
}