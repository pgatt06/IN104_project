/*Ce programme permet de récupérer tous les cycles d'un graphe grâce à sa matrice adjacente. */

#include <stdio.h>
#include <stdbool.h>

//fonction qui permet de trouver un cycle (si il existe) à partir d'un noeud en particulier
void recherche_cycle(int noeud,int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]) {
    visite[noeud] = true; //on est passé par le noeud de départ
    sur_chemin[noeud] = true; //le noeud de départ est sur le chemin
    chemin[top++] = noeud; //enregistre la valeur du noeud de départ dans le chemin

    for (int i = 0; i < n; i++) {
        //si il existe une piste entre le point de départ et le point i
        if (tab[noeud*n+i]) { 
            //si on a a pas visité le point i 
            if (!visite[i]) { 
                //récurcivité cette fois ci départ est le point i 
                recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin );

            } 
            //si le point i est sur le chemin = on a trouvé un cycle on imprime le cycle
            else if (sur_chemin[i]) {
                printf("Cycle trouvé : ");
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

//fonction qui applique la recherche de cycle sur l'ensemble des noeuds du cycle avec la condition qu'il ne soit pas déja parcouru par un cycle
void trouver_cycles(int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]) {
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin );
        }
    }
}

/*int main() {

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
    
    
    // trouver les cycles affichage simple
    trouver_cycles(n , tab, visite, sur_chemin, top,  chemin );

    return 0;
}*/
