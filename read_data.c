#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"

//struct data {int piste;int croisements;};

struct data read_info(char* fname, struct data k) {
    FILE* fichier = fopen(fname, "r");

    if (fichier == NULL) {
        printf("error\n");
    }

    fscanf(fichier, "%d %d", &k.croisements, &k.piste);

    printf("\n");
    printf("le nombre de croisements est :%d et le nombre de pistes est :%d \n", k.croisements, k.piste);
    printf("\n");

    if (k.piste == 0) {
        printf("error\n");
    }

    fclose(fichier);

    return k;
}

struct data remplir(char* fname, int taille, int tab[(taille)*(taille)], struct data k) {
    FILE* fichier = fopen(fname, "r");

    int depart;
    int arrivee;
    int plaisir;
     //pour lire la première ligne (regarder comment sauter une ligne en c)
    fscanf(fichier,"%d %d",&k.croisements,&k.piste);
    //printf("%d,%d \n",croisements,piste);
    for (int i = 0; i < ((taille)*(taille)); i++) {
        tab[i] = 0;
    }

    while (feof(fichier)==0) {
        fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
        tab[(taille)*depart+arrivee] = plaisir;
    }

    fclose(fichier);

    return k;
}

void voir(int taille, int tab[(taille)*(taille)]) {
    printf("La matrice adjacente est :\n");

    for (int i = 0; i < ((taille)*(taille)); i++) {
        printf("%d ", tab[i]);

        if ((i + 1) % taille == 0) {
            printf("\n");
        }
    }
}

/*int main() {
    struct data i;
    struct data k = read_info("data.txt", i);

    int taille = k.croisements + 1;
    int tab[(taille)*(taille)];

    struct data j = remplir("data.txt", taille, tab, k);
    voir(taille, tab);

    return 0;
}*/
