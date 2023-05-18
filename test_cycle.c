#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "test_cycle.h"


struct cycle
{
    int taille;
    int* tableau;
};

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
                recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin);

            } 
            //si le point i est sur le chemin = on a trouvé un cycle on imprime le cycle
            else if (sur_chemin[i]) {
                printf("Cycle trouvé : ");
                int compt=0;
                for (int j = top - 1; j >= 0; j--) {
                    printf("%d\n",j);
                    if (chemin[j] == i) {
                        printf("ca%d\n",compt);
                        compt = compt + tab[chemin[top-1]*n+i];
                        printf("ca%d avec le chacal %d et j %d ",compt,tab[chemin[top-1]*n+i],j);
                        break;
                        }                    
                        compt=compt+tab[(j-1)*n+j];
                        printf("compt %d\n",compt);
                    // si on revient au départ du cycle on a parcouru tout le cycle 
                    printf("pts %d\n ", chemin[j]);
                }

                printf("TOTAL Adrien LPB%d\n", compt);
               
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
            recherche_cycle(i,n , tab, visite, sur_chemin, top,chemin);
        }
    }
}

/*int main() {
    
  
    int n=5;
    bool visite[n];
    bool sur_chemin[n];
    int chemin[n];
    int top = 0;
    
    int tab[n*n];

    

    
    for (int i=0; i<n*n;i++){
        tab[i]=0;
    }
    tab[1]=1;
    tab[2]=1;
    tab[3]=1;
    tab[8]=1;
    tab[14]=1;
    tab[15]=1;
    tab[20]=1;
    
    
    // trouver les cycles affichage simple
    trouver_cycles(n , tab, visite, sur_chemin,top,chemin);
    return 0;
}*/
