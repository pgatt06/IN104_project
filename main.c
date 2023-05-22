#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"
#include "chemin.h"
#include <time.h>






int main(int argc, char* argv[]){
clock_t begin = clock();

//création de la matrice adjacente
    int *donnees= station_de_ski(argv[1]);
    int croisements = donnees[0];
    
    int taille=croisements;
    // Création d'une matrice nulle dans le main, qu'on pourra réutiliser en paramètre des fonctions
    int tab[taille*taille];
    for (int i=0; i<taille*taille;++i)
    {
        tab[i]=0;
    }
    int *matrice = read_info(argv[1], donnees, taille, tab);
    
//affichage de la matrice adjacente enlever les commentaire dans le read_data pour afficher 
    voir(taille,matrice);
   // printf("\n");

    

    plaisir_max_ch_sommet(taille,matrice);

   clock_t end = clock();
   unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis );  
    return (0);
    }