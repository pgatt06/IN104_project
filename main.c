#include <stdlib.h>
#include <stdio.h>
#include "read_data_3.h"
#include "test_cycle_positif.h"
#include "calcul_plaisir_chemin.h"
#include "utilitaires.h"
#include "chemin_dep_arr.h"




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


    int sky_is_the_limit=trouver_cycle_positif(n,tab);
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