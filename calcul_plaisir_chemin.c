#include <stdio.h>
#include <stdbool.h>
#include "calcul_plaisir_chemin.h"

int plaisir(int n, int tab[n*n], int n_chemin, int chemin[n_chemin]){
    int compt_plaisir=0;
    for(int i=1; i<n_chemin; i++){
        int depart = chemin[(i-1)];
        int arrive = chemin[i];
        compt_plaisir += tab[depart*n+arrive];
    }
        int depart = chemin[(n_chemin-1)];
        int arrive = chemin[0];
    compt_plaisir=compt_plaisir+tab[depart*n+arrive];
    return (compt_plaisir);
}

/*int main(){
    int n = 5; 
    int tab[n*n];

    for (int i=0; i<n*n; i++){
        tab[i] = 0;
    }

    tab[1] = -10;
    tab[7]=5;
    tab[13]=-2;
    tab[16]=-3;
    tab[19]=-7;
    tab[23]=-2;

   

    int n_chemin = 2;
    int chemin[n_chemin];
    
    chemin[0] = 3;
    chemin[1] = 4;



    int plaisir_nb = 0;

    plaisir_nb = plaisir(n, tab, n_chemin, chemin);
    printf("%d \n", plaisir_nb);

    return 0;
}*/

