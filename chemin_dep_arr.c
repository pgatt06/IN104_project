#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcul_plaisir_chemin.h"
#include "chemin_dep_arr.h"
#include "taille_liste.c"

/*struct chemin {
    int taille;
    int arrete[];
};*/

/*struct liste_plaisir{
    int taille;
    int * liste_p;
};*/


void affichage(int *A, int c) {
    printf("LISTE : \n");
  for (int i = 0; i < c; ++i) {
    printf("%d\n", A[i]);
  }
}

void affichage_matrix(int* M, int n) {
    printf("MATRIX : \n");
    int tmp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        tmp = printf("%d", M[i*n+j]);   
        for (int k = 0; k <= 4-tmp; k++)    //4 = max displayed int size + 1
        {
            printf(" ");
        }
    }
    printf("\n");
  }
}

//permet d'afficher le chemin
void voir_chemin(struct chemin* chemin) {
    printf("CHEMIN : \n");
    for (int i = 0; i < chemin->taille; i++) {
        printf("%d ", chemin->arrete[i]);
    }
    printf("\n");
}

//permet de trouver tous les chemins entre le début et la fin 
void tab_plaisir(int n, int T[], int debut, int fin, bool visited[], struct chemin* chemin, struct liste_plaisir* liste) {
    visited[debut] = true;

    int* tmpChemin = NULL;
    tmpChemin = malloc(chemin->taille*sizeof(int));
    for(int i = 0; i < chemin->taille; i++)
    {
        tmpChemin[i] = chemin->arrete[i];
    }
    chemin->arrete = malloc((chemin->taille+1)*sizeof(int));
    for(int i = 0; i < chemin->taille; i++)
    {
        chemin->arrete[i] = tmpChemin[i];
    }
    chemin->arrete[chemin->taille] = debut;

    free(tmpChemin);
    chemin->taille++;
  
    if (debut == fin){
        int* tmpListe = NULL;
        tmpListe = malloc(liste->taille*sizeof(int));
        for(int i = 0; i < liste->taille; i++)
        {
            tmpListe[i] = liste->liste_p[i];
        }
        liste->liste_p = malloc((liste->taille+1)*sizeof(int));
        for(int i = 0; i < liste->taille; i++)
        {
            liste->liste_p[i] = tmpListe[i];
        }
        liste->liste_p[liste->taille] = plaisir(n,T,chemin->taille,chemin->arrete);

        free(tmpListe);
        liste->taille++;

        voir_chemin(chemin);
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (T[debut*n+i] != 0 && !visited[i]) {
                
                tab_plaisir(n, T, i, fin, visited, chemin, liste);
            }
        }
    }

    visited[debut] = false;
    chemin->taille--;
    
}



// test de la fonction
int main() {
    
    int n = 5; 
    int tab[n*n];

    for (int i=0; i<n*n; i++){
        tab[i] = 0;
    }

    tab[1] = -10;
    tab[3] = 1;
    tab[8] = 50;
    tab[9] = 5;
    tab[13]=-2;
    tab[16]=-3;
    tab[19]=-7;
    tab[23]=-2;

    affichage_matrix(tab,n);

    bool visited[n];
    struct chemin chemin;
    chemin.taille = 0;
    chemin.arrete = NULL;
    struct liste_plaisir liste;
    liste.taille = 0;
    liste.liste_p = NULL;

    tab_plaisir(n, tab, 0, 3, visited, &chemin, &liste);
    
   
    affichage(liste.liste_p,liste.taille);

    return 0;
}
