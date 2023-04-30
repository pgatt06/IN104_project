#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"
#include "chemin.h"




int main(int argc, char* argv[]){

//lecture des données du fichier data.txt
    struct data i ={0,0};
    char* texte =argv[argc-1];
    struct data k=read_info(texte,i);
//création de la matrice adjacente
    int n = k.croisements+1;
    int tab[n*n];
    i=remplir("data.txt",n,tab,k);
//affichage de la matrice adjacente
    voir(n,tab);
    printf("\n");

plaisir_max_ch_sommet(n,&tab[n*n]);

   
    return (0);
    }