#include <stdlib.h>
#include <stdio.h>
#include "read_data_3.h"







// lecture du fichier et création d'une matrice dynamique 

int *read_info(char* fname, int* station, int n,int tab[n*n])
{
    FILE*file=fopen(fname,"rb");
    if (file==NULL)
    {
        printf("error\n");
    }

    int croisements;
    int pistes;
    int depart;
    int arrivee;
    int plaisir;
    int compteur;

    //on récupère le nb de croisements et de piste
    fscanf(file,"%d %d", &croisements,&pistes);

    if (pistes==0)
    {
        printf("error\n");
        fclose(file); 
    }   
    int taille=croisements+1;

    //on lit toutes les lignes du fichier 
    while (!feof(file))
    {
        ++compteur;
        if (compteur>1) // on met les données du fichier dans le tableau
        {
            fscanf(file,"%d %d %d",&depart, &arrivee, &plaisir);
            tab[(taille)*depart+arrivee] = plaisir;

        }
    }
    fclose (file);
    return tab; 
}


//fonction pour former le tableau pour récupérer les valeurs croisments et pistes pour pouvoir avoir la taille de tab donné en argument de la fonction du dessus  
int *station_de_ski(char* fname)
{
    FILE *file = fopen(fname,"rb");
    if (file==NULL) {
        printf("error\n");
        return NULL;
    }
    
    int croisements, pistes;
    int *tab = malloc(2*sizeof(int));// on sait que la taille sera de 2
    for (int i = 0; i < 2; ++i) {
        tab[i]=0;
    }

    fscanf(file, "%d %d", &croisements, &pistes);
    tab[0] = croisements;
    tab[1] = pistes;

    fclose(file);
    return tab;
}
//permet d'afficher le tableau des plaisirs des pistes existantes 
void voir(int taille, int tab[(taille)*(taille)]) {
    printf("La matrice adjacente est :\n");

    for (int i = 0; i < ((taille)*(taille)); i++) {
        printf("%d ", tab[i]);

        if ((i + 1) % taille == 0) {
            printf("\n");
        }
    }
}

void affichage (int taille, int *tab)
{
    for (int i=0; i<taille;++i)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

/*int main (int argc, char *argv[])
{
    int *donnees= station_de_ski(argv[1]);
    int croisements = donnees[0];
    
    int taille=croisements+1;
    // Création d'une matrice nulle dans le main, qu'on pourra réutiliser en paramètre des fonctions
    int tab[taille*taille];
    for (int i=0; i<taille*taille;++i)
    {
        tab[i]=0;
    }
    int *matrice = read_info(argv[1], donnees, taille, tab);


    voir(taille,matrice);
    affichage(2,donnees);
    printf("\n");
    
}*/
