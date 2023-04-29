#include <stdio.h>
#include "test_cycle_positif.h"

// fonction qui retourne 1 si le graphe présente un cycle positif et 0 sinon 
// elle prend en argument la taille de la matrice donc le nombre de sommets et la matrice adjacente
int trouver_cycle_positif(int n, int matrice[n*n]) {
    //initialisation des tableau pour les sommets visités ou non et ceux présents dans la pile étudiée
    int compt = 0;
    int visite[n];
    int pile[n];
    int top = -1;
    int i, j;

    // on n'a visité encore aucun sommet
    for (i = 0; i < n; i++) {
        visite[i] = 0;
    }


    for (i = 0; i < n; i++) {
        //Si on n'est pas encore passé par ce sommet 
        if (visite[i] == 0) {
            //on commence la pile étudiée et on a visité le sommet i
            top = 0;
            pile[top] = i;
            visite[i] = 1;
            
            while (top >= 0) {
                int sommet = pile[top];
                int trouve_cycle_positif = 0;
                
                // on parcours les autres sommets à partir du sommet i 
                for (j = 0; j < n; j++) {
                    compt =compt+matrice[sommet*n+j];
                    if (matrice[sommet*n+j]) {
                        if (visite[j] == 0) {
                            top++;
                            pile[top] = j;
                            visite[j] = 1;
                            break;
                        } else if (j == i) {
                            if(compt>0){
                            trouve_cycle_positif = 1;}
                            break;
                        }
                    }
                }
                
                if (trouve_cycle_positif) {
                    return 1;
                }
                
                if (j == n) {
                    top--;
                }
            }
        }
    }
    
    return 0;
}

/*int main() {
  
    int n=3;
    int tab[n*n];

    for (int i=0; i<n*n;i++){
        tab[i]=0;
    }
    tab[1]=1;
    tab[5]=1;
    tab[3]=-1;
   
    
    int sky =trouver_cycle_positif(n,tab);
    printf("%d\n",sky);
    return(0);
}*/
