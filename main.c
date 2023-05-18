#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "read_data.h"
#include "test_cycle.h"

int main(int argc, char* argv[]){


//création de la matrice adjacente
    int *donnees= station_de_ski(argv[1]);
    int croisements = donnees[0];
    int taille=croisements;


    // Création d'une matrice nulle dans le main, qu'on pourra réutiliser en paramètre des fonctions
    int tab[taille*taille];

    for (int i=0; i<taille*taille;++i){
        tab[i]=0;}
    
    int *matrice = read_info(argv[1], donnees, taille, tab);
    
//affichage de la matrice adjacente
    voir(taille,matrice);
    printf("\n");


    
    bool visite[taille];
    bool sur_chemin[taille];
    int chemin[taille];
    int top = 0;
    int cycle=-1;
   

    trouver_cycles(taille , tab, visite, sur_chemin,top,chemin,&cycle);
    
    if(cycle==1){printf("SKY IS THE LIMIT\n");}
   

   
    return (0);
    }