#include <stdlib.h>
#include <stdio.h>
#include "read_data_3.h"
#include "liste_boucle.h"
#include "sommet.h"

int main(){

//lecture des données du fichier data.txt
    struct data i;
    struct data k=read_info("data.txt",i);
//création de la matrice adjacente
    int taille = k.croisements+1;
    int tab[(taille)*(taille)];
    struct data j=remplir("data.txt",taille,tab,k);
//affichage de la matrice adjacente
    voir(taille,tab);


    int n=taille;
    bool visite[n];
    bool sur_chemin[n];
    int chemin[n];
    int top = 0;
    
// trouver les cycles de la matrice adjacente
    trouver_cycles(n , tab, visite, sur_chemin, top,  chemin );

   

    return(0);
    }