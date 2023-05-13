#include <stdlib.h>
#include <stdio.h>
#include "read_data_3.h"
#include "test_cycle_positif.h"
#include "calcul_plaisir_chemin.h"
#include "utilitaires.h"
#include "chemin_dep_arr.h"




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


    int sky_is_the_limit=trouver_cycle_positif(n,matrice);
    printf("il y a un cycle pos (1 oui 0 non) : %d\n",sky_is_the_limit);
  
    
    bool visite[n];



    struct chemin st_chemin ;
    struct liste_plaisir st_liste;


    //initialisation du plaisir maximal 
    int plaisir_max=0;

    // on applique la fonction qui recherche tous les chemins entre 0 et tous les points et on prend le maximum des plaisirs 
    
    for(int i=1;i<n;i++){
        int dep=0;
        
        printf("on est au somment n° %d\n",i);
        tab_plaisir(n,tab,dep,i,visite,&st_chemin,&st_liste);
        int test = maxi(st_liste.liste_p,st_liste.taille);
        if (test>plaisir_max){plaisir_max=test;}
    }
    if(sky_is_the_limit==1){printf("SKY IS THE LIMIT\n");}
    else{printf("Le plaisir max est :%d\n",plaisir_max);}
    
    return (0);
    }