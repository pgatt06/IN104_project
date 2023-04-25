#include <stdlib.h>
#include <stdio.h>
#include "sommet.h"
#include "utils.h"


void *malloc(size_t nombre_d_octets);
void free(void *ptr);


/*
but du programme:
-programme récursif
on a notre liste de structure contenant [(arrivee,plaisir), ...]
on recherche le plaisir max dans cette liste de structure
on récupère l'indice de ce plaisir
et on refait une liste à partir du nouveau sommet qui est celui du plaisir max
puis on recherche encore une fois le plaisir max 
on continue ce processus 
*/

int Max_plaisir(int n, int T[n*n]){
    int plaisir=0; 
    
    for(int j=0;j<compteur;j++){
        int compteur= taille (n,T,0);
        int compt_plaisir=0;
        int *L_plaisir=liste_plaisir(n,T,j,compteur);
        int *L_arrivee=liste_arrivee(n,T,j,compteur);

        maximum max(compteur,L_plaisir); 
        compt_plaisir=compt_plaisir+ L_plaisir[max.indice];
        L_plaisir[max.indice]=0;


}
}
