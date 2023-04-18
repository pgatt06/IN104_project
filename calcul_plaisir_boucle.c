#include <stdio.h>
#include <stdbool.h>

int plaisir(int n, int tab[n*n], int n_chemin, int chemin[n_chemin]){
    int compt_plaisir=0;
    for(int i=1; i<n_chemin; i++){
        int depart = chemin[(i-1)];
        int arrive = chemin[i];
        compt_plaisir += tab[depart*n+arrive];
    }
    return compt_plaisir;
}

int main(){
    int n = 3; 
    int tab[n*n];

    for (int i=0; i<n*n; i++){
        tab[i] = 0;
    }

    tab[1] = 1;
    tab[5] = -3;
   

    int n_chemin = 3;
    int chemin[n_chemin];
    
    chemin[0] = 0;
    chemin[1] = 1;
    chemin[2] = 2;

    int plaisir_nb = 0;

    plaisir_nb = plaisir(n, tab, n_chemin, chemin);
    printf("%d \n", plaisir_nb);

    return 0;
}
