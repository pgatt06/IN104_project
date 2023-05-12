#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"
#include "chemin.h"






int main(int argc, char* argv[]){


//création de la matrice adjacente
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
    
//affichage de la matrice adjacente
    voir(taille,matrice);
    printf("\n");

    

    plaisir_max_ch_sommet(taille,matrice);

   
    return (0);
    }