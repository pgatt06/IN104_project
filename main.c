#include <stdlib.h>
#include <stdio.h>
#include "read_data_3.h"
#include "liste_boucle_2.h"
#include "sommet.h"
#include "calcul_plaisir_chemin.h"

int main(int argc, char* argv[]){

//lecture des données du fichier data.txt
    struct data i ={0,0};
    char* texte =argv[argc-1];
    struct data k=read_info(texte,i);
//création de la matrice adjacente
    int taille = k.croisements+1;
    int tab[(taille)*(taille)];
    i=remplir("data.txt",taille,tab,k);
//affichage de la matrice adjacente
    voir(taille,tab);
    printf("\n");

//resultat = tableau de structure 
// structure cycle = taille du cycle et tableau avec tous les sommets de chaque cycle
    int n= taille;
    struct cycle* resultat; 
    int taille_resultat = 0;
    bool visite[n];
    bool sur_chemin[n];
    int chemin[n];
    int top = 0;
    
    

    // trouver les cycles affichage simple
    trouver_cycles(taille , tab, visite, sur_chemin,top,chemin,&resultat,&taille_resultat);

    printf("\n");
    printf("Le graphe possède %d cycle.s. \n",taille_resultat);
    printf("\n");

    for(int i=0;i<taille_resultat;i++){
        printf("Le %d eme cycle est de taille :%d\n ",i, resultat[i].taille);

        int plaisir_cycle= plaisir(n,tab,resultat[i].taille, resultat[i].tableau);
        printf("Le plaisir du cycle est %d\n",plaisir_cycle);
        if(plaisir_cycle>0){printf("SKY IS THE LIMIT \n");
        }
    }
    
    return (0);
    }