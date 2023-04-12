#include <stdio.h>
#include <stdbool.h>
/*
#define N 100

bool visite[N];
bool sur_chemin[N];
int chemin[N];
int top = 0;
int tab[N*N];
int n;
*/

void recherche_cycle(int noeud,int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]) {
    visite[noeud] = true;
    sur_chemin[noeud] = true;
    chemin[top++] = noeud;

    for (int i = 0; i < n; i++) {
        if (tab[noeud*n+i]) {
            if (!visite[i]) {
                recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin );
            } else if (sur_chemin[i]) {
                printf("Cycle found: ");
                for (int j = top - 1; j >= 0; j--) {
                    if (chemin[j] == i) break;
                    printf("%d ", chemin[j]);
                }
                printf("%d\n", i);
            }
        }
    }

    top--;
    sur_chemin[noeud] = false;
}

void trouver_cycles(int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]) {
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin );
        }
    }
}

int main() {

    int n=3;
    bool visite[n];
    bool sur_chemin[n];
    int chemin[n];
    int top = 0;
    
    int tab[n*n];

    
    for (int i=0; i<n*n;i++){
        tab[i]=0;
    }
    tab[1]=1;
    tab[5]=1;
    tab[6]=1;
    
    
    // Find cycles
    trouver_cycles(n , tab, visite, sur_chemin, top,  chemin );

    return 0;
}
