#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "chemin.h"
#include "test_cycle.h"
#include "read_data.h"

/* ce programme permet de déterminer le maximum dans une liste A de taille n*/
int maxi(int *A, int n)
{
    int max=A[0];
    for (int k=0; k<n; ++k)
    {
        if (A[k]>max)
        {
            max=A[k];
        }
    }
    return max; 
}

void plaisir_max_ch_sommet(int n, int graph[n*n])
{
    
    
    int plaisir[n]; // tableau des plaisirs 
    int precedant[n]; // tableau des prédécesseurs donc ceux présents sur le chemin pour acceder au point étuidié 
   
    
    
    
    // Initialisation des tableaux
    for (int i = 0; i < n; i++) {
        plaisir[i] = INT_MIN; // plaisir initial entre 0 et chaque sommet est -infini
        precedant[i] = -1; // pas de sommet avant la source 0 
    }
    plaisir[0] = 0; // plaisir de 0 à 0 est de 0
    

for (int k=0;k<n;k++){
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
             if (graph[u*n+v] != 0 && plaisir[u] != INT_MIN && plaisir[u] + graph[u*n+v] > plaisir[v]) {
                plaisir[v] = plaisir[u] + graph[u*n+v]; // mise à jour du plaisir
                precedant[v] = u; // mise à jour du sommet précédent 
                }
            }
        }

}
    // Vérification de la présence de cycles de plaisir infini
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u*n+v] != 0 && plaisir[u] != INT_MIN && plaisir[u] + graph[u*n+v] > plaisir[v]) {
                printf("SKY IS THE LIMIT \n");
                return;
            }
        }
    }

    
    
    
    // Affichage des résultats
    printf("Le plaisir maximal pour chaque sommet est :\n");
    for (int i = 0; i < n; i++) {
        printf("Sommet %d : ", i);
        if (plaisir[i] == INT_MIN) {
            printf("Pas de chemin\n");
        } else {
            printf("%d ", plaisir[i]);
            int pred = precedant[i];
            while (pred != -1) {
                pred = precedant[pred];
            }
            printf("\n");
        }
    }
    int plaisir_max =maxi(plaisir,n);
    affichage(n,plaisir);
    printf("le plaisir maximal est : %d\n",plaisir_max);
}

/*int main()
{
    int n = 3; 
    int tab[n*n];

    for (int i=0; i<n*n; i++){
        tab[i] = 0;
    }

    tab[1] = -1;
    
    tab[5] = 2;
    
    

    plaisir_max_ch_sommet(n,tab);
    return(0);
}*/
