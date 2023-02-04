#include <stdio.h>
#include <string.h>

#include "afisari.h"
#include "fisiere.h"
#include "functionarepacanea.h"

/*! Functia main unde ruleaza programul. */
int main()
{

    int BaniiTai, jocul = 1, contor = 0, camata = 0, restCamata = 0;
    char nume[30];

    printf("\n\nINTRODU USERNAME-UL: ");

    scanf("%s", nume);
    printf("Cu cati bani vrei sa incepi: \n");
    scanf("%d", &BaniiTai);
    int baniInitiali;
    baniInitiali = BaniiTai;

    while (jocul == 1 && BaniiTai >= 10){

        printGameMenu(nume);
        printBani(BaniiTai);

        scanf("%d", &jocul);

        for (int i = 0; i < 40; i++)
            printf("\n");

        if (jocul == 1)
        {
            BaniiTai -= 10;
            BaniiTai = utilizarePacanea(BaniiTai);
        }

     verificatBani(BaniiTai); 
    }

    scriereFisier(nume, BaniiTai - baniInitiali, camata);

    printareFinala(contor, BaniiTai, camata, nume, baniInitiali);

    sortare();

    afisareFisier();

    return 0;
}