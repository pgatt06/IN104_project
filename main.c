#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "read_data.h"
#include "test_cycle.h"
#include "chemin.h"

int main(int argc, char* argv[]){


//création de la matrice adjacente
    int *donnees= station_de_ski(argv[1]);
    int croisements = donnees[0];
    int taille=croisements;


    // Création d'une matrice nulle dans le main, qu'on pourra réutiliser en paramètre des fonctions
    int tab[taille*taille];

    for (int i=0; i<taille*taille;++i){
        tab[i]=0;}
    
    // remplir la matrice adjacente 
    int *matrice = read_info(argv[1], donnees, taille, tab);
    
// affichage de la matrice adjacente enlever les commentaires dans read_data pour afficher 
    voir(taille,matrice);
   // printf("\n");

    // initialisation des variables pour la détection de cycle et du parcours du cycle 
    bool visite[taille];
    bool sur_chemin[taille];
    int chemin[taille];
    int top = 0;
    int cycle=-1;
   
   int position=0;
    int plaisir=0;
    int *iti=malloc(sizeof(int)*taille);
    iti[0]=0;

    //détection du cycle 

    trouver_cycles(taille , tab, visite, sur_chemin,top,chemin,&cycle);
    
    if(cycle==1){printf("SKY IS THE LIMIT\n");
                return(0);}

    //parcours du graphe si pas de graphe 
   
    chemin_f(taille,tab,0,iti,position,&plaisir);
 
    printf("plaisir :%d\n",plaisir);

   
    return (0);
    free(iti);
    }