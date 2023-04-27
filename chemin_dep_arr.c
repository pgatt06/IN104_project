#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcul_plaisir_chemin.h"
#include "chemin_dep_arr.h"

/*struct chemin {
    int taille;
    int arrete[];
};*/

void affichage(int *A, int c) {
  for (int i = 0; i < c; ++i) {
    printf("%d,", A[i]);
  }
}

//permet d'afficher le chemin
void voir_chemin(struct chemin* chemin) {
    for (int i = 0; i < chemin->taille; i++) {
        printf("%d ", chemin->arrete[i]);
    }
    printf("\n");
}

//permet de trouver tous les chemins entre le début et la fin 
int* tab_plaisir(int n, int T[n*n], int debut, int fin, bool visited[], struct chemin* chemin) {
    visited[debut] = true;
    chemin->arrete[chemin->taille++] = debut;
    int plaisir_f=-20;
    int compt=0;
    int *A = NULL;
    int *tmp_A= NULL;
    
    if (debut == fin){
        compt++;
        tmp_A =malloc((compt-1) * sizeof(int));
        for(int k=0;k<compt-1;k++){
                        tmp_A[k]=A[k];
                    }
                    
        A = realloc(A,compt * sizeof(int));
        A[compt-1]= plaisir(n,T,chemin->taille,chemin->arrete);
                //boucle for remplissage de valeurs
                for(int k=0;k<compt;k++){
                    A[k]=tmp_A[k];
                }
                free (tmp_A);
        voir_chemin(chemin);
        printf("plaisir %d\n",plaisir_f);
    
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (T[debut*n+i] && !visited[i]) {
                
                tab_plaisir(n,T, i,fin, visited, chemin);
            }
        }
    }

    visited[debut] = false;
    chemin->taille--;
    
    return(A);
}



// test de la fonction
int main() {
    
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

    bool visited[n];
    struct chemin chemin = { 0 };

    int*A=tab_plaisir(n,tab, 0, 1, visited, &chemin);
    int size_liste= sizeof(&A)/sizeof(int);
    affichage(A,size_liste);

    return 0;
}
