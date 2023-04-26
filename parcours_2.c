#include <stdio.h>
#include <stdlib.h>


void parcours_prof(int n ,int T[n*n], int v,int visite[n],chemin[n],ind_chemin) {
    visite[v] = 1;
    chemin[ind_chemin++] = v;

    if (ind_chemin == vertices) {
        // affiche le chemin todo recup le chemin
        int i;
        for (i = 0; i < ind_chemin; i++) {
            printf("%d ", chemin[i]);
        }
        printf("\n");
    } else {
        int i;
        for (i = 0; i < vertices; i++) {
            if (T[v*n+i] && !visite[i]) {
                parcours_prof(n,T, i);
            }
        }
    }

    // Backtrack
    ind_chemin--;
    visite[v] = 0;
}

void trouve_tout_chemin(int T[n*n], int vertices) {
    int i;
    for (i = 0; i < vertices; i++) {
        parcours_prof(n, T , i);
    }
}

int main() {
    int n=5;
    int visite[n];
    int chemin[n];
    int ind_chemin = 0;

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


    printf("tous les chemins possibles sont :\n");
    find_all_paths(tab, n);

    return 0;
}
