#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fisiere.h"

/*! Functie pentru a scrie in fisier situatia userului. -scor inseamna ca are de dat la camatari scor lei*/
void scriereFisier(char nume[30], int scor, int camata){

    FILE *out = fopen("Highscore.txt", "a");
    fprintf(out, "%d %s\n", scor - camata, nume);
    fclose(out);
}

/*! Functia pentru a sorta fisierul in ordine descrescatoare */
void sortare(){

    FILE *read = fopen("Highscore.txt", "r");
    char linie[60] = {0};

    int linii = 0;

    while (!feof(read)){

        fgets(linie, 59, read);
        linii++;
    }

    fseek(read, SEEK_SET, 0);

    linii--;
    char **content = malloc(linii * sizeof(char *));
    for (int i = 0; i < linii; i++){

        content[i] = calloc(60, sizeof(char));
        fgets(content[i], 59, read);

    }
    
    fclose(read);

    for (int i = 0; i < linii; i++){

        for (int j = i + 1; j < linii; j++){

            char bck[60] = {0};
            strcpy(bck, content[i]);
            char *p = strtok(bck, " ");
            int a;
            sscanf(p, "%d", &a);

            strcpy(bck, content[j]);
            p = strtok(bck, " ");
            int b;
            sscanf(p, "%d", &b);

            if (b > a){

                char *aux = content[i];
                content[i] = content[j];
                content[j] = aux;
            }
        }
    }

    read = fopen("Highscore.txt", "w");
    for (int i = 0; i < linii; i++){

        fputs(content[i], read);
        free(content[i]);

    }
    fclose(read);
    free(content);
}

/*! Functia pentru a afisa din fisier scorul si banii */
void afisareFisier(){

    FILE *read = fopen("Highscore.txt", "r");
    char c;

    while (fscanf(read, "%c", &c) != EOF)
        printf("%c", c);

    fclose(read);
}