#include <stdlib.h>
#include <stdio.h>
#include"read_2.h"

// lecture du fichier et création d'une matrice dynamique 

int ** read_info(char* fname, int** tab)
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
    

    //on lit toutes les lignes du fichier 
    while (!feof(file))
    {
        ++compteur;
        if (compteur>1) // on met les données du fichier dans le tableau
        {
            fscanf(file,"%d %d %d",&depart, &arrivee, &plaisir);
            tab[depart][arrivee]=plaisir;

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
void voir(int taille, int **tab){
    printf("La matrice adjacente est :\n");
    for(int i=0;i<taille;i++){
        for (int j=0; j<taille;++j)
        {
            printf("%d ",tab[i][j]);
    //modulo le nombre de départ pour belle écriture en colonne et ligne comme un tableau   
        }
        printf("\n");
    }
    printf("\n");

}

void affichage (int taille, int *tab)
{
    for (int i=0; i<taille;++i)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int main (int argc, char *argv[])
{
    int *donnees= station_de_ski(argv[1]);
    int croisements = donnees[0];
    
    int taille=croisements+1;
    // Création d'une matrice nulle dans le main, qu'on pourra réutiliser en paramètre des fonctions
    int **mat = malloc(taille*sizeof(int *));
    for (int i = 0; i < taille; i++) {
        mat[i] = malloc(taille*sizeof(int));
        for (int j = 0; j < taille; j++) {
            mat[i][j]=0;
        }
    } 
    int **matrice = read_info(argv[1], mat);
    voir(taille,matrice);
    affichage(2,donnees);
    printf("\n");
    
}

