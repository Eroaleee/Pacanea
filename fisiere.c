#include <stdio.h>
#include <string.h>

#include "fisiere.h"


    int citire_din_fisier(char nume[30]) {

    FILE *in = fopen("database.txt", "r");
    
    char nume_fisier[30];
    int bani;
    while (!feof(in)) {
        fscanf(in, "%d%30s", &bani, nume_fisier);
        if (!strcmp(nume_fisier, nume)) {
            fclose(in);
            return bani;
        }
    }
    fclose(in);
    
    printf("\n\n\nIntrodu suma de bani cu care intrii in cazino\n");
    scanf("%d", &bani);
    return bani;
}

void scriere_fisier(char nume[30], int scor, int camata) {
    FILE *out = fopen("database.txt", "a");
    fprintf(out, "\n%s a iesit cu %d lei din cazino", nume , scor);
    if (camata!=0)
    fprintf(out, " si cu o datorie de %d la camatari.", camata);
    fclose(out);
}