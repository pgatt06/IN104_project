/*Ce programme permet de récupérer tous les cycles d'un graphe grâce à sa matrice adjacente. */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct cycle
{
    int taille;
    int* tableau;
};
//fonction qui permet de trouver un cycle (si il existe) à partir d'un noeud en particulier
void recherche_cycle(int noeud,int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n], struct cycle** resultat, int* taille) {

    visite[noeud] = true; //on est passé par le noeud de départ
    sur_chemin[noeud] = true; //le noeud de départ est sur le chemin
    chemin[top++] = noeud; //enregistre la valeur du noeud de départ dans le chemin

    int compteur_cycle = *taille;
    struct cycle* tmp;

    for (int i = 0; i < n; i++) {
        //si il existe une piste entre le point de départ et le point i
        if (tab[noeud*n+i]) { 
            int* tableau = NULL;
            int* tmp_tableau = NULL;
            //si on a a pas visité le point i 
            if (!visite[i]) { 
                //récurcivité cette fois ci départ est le point i 
                recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin, resultat, taille);

            } 
            //si le point i est sur le chemin = on a trouvé un cycle on imprime le cycle
            else if (sur_chemin[i]) {

                //permet de compter le nombre de cycle présent dans le graphe 
                compteur_cycle++;
                printf("Cycle trouvé : ");
                //permet de déterminer la taille de chaque cycle 
                int compteur_taille_cycle = 0;

                for (int j = top - 1; j >= 0; j--) {
                    compteur_taille_cycle++;
                    // si on revient au départ du cycle on a parcouru tout le cycle 
                    if (chemin[j] == i) break;
                    printf("%d ", chemin[j]);

                    tmp_tableau=malloc((compteur_taille_cycle -1)*sizeof(int));
                    //boucle for copie de valeurs
                    for(int k=0;k<compteur_taille_cycle-1;k++){
                        tmp_tableau[k]=tableau[k];
                    }
                    
                    //augmente taille
                    tableau = realloc(tableau,(compteur_taille_cycle)*sizeof(int));

                    //on ajoute au tableau du cycle le dernier point parcouru 
                    tableau[compteur_taille_cycle-1] = chemin[j];
                    //boucle for remplissage de valeurs
                    for(int k=0;k<compteur_taille_cycle;k++){
                        tableau[k]=tmp_tableau[k];
                    }
                    free (tmp_tableau);

                }
                printf("%d\n", i);

                //Sauvegarder cycle
                struct cycle nouveau_cycle;

                //ajout des valeurs dans la structure 
                nouveau_cycle.taille = compteur_taille_cycle;
                nouveau_cycle.tableau = tableau;
                tmp=malloc(compteur_cycle*sizeof(struct cycle));
                for(int k=0;k<compteur_cycle-1;k++){
                        tmp[k]=(*resultat)[k];
                    }
                
                *resultat = malloc(compteur_cycle*sizeof(struct cycle));
                if(*resultat== NULL)
                {printf("rr");}
                //Copier tmp dans resultat
                for(int k=0;k<compteur_cycle-1;k++){
                        (*resultat)[k]=tmp[k];
                    }

                (*resultat)[compteur_cycle-1] = nouveau_cycle;
                *taille=compteur_cycle;
                free(tmp);
            }
        }
    }

    top--;
    sur_chemin[noeud] = false;
}

//fonction qui applique la recherche de cycle sur l'ensemble des noeuds du cycle avec la condition qu'il ne soit pas déja parcouru par un cycle
void trouver_cycles(int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n],struct cycle** resultat, int* taille) {
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            recherche_cycle(i,n , tab, visite, sur_chemin, top,  chemin, resultat, taille);
        }
    }
}

int main() {
    struct cycle* resultat; 
    int taille = 0;
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
    trouver_cycles(n , tab, visite, sur_chemin,top,chemin,&resultat,&taille);
    printf("%d \n",taille);
    for(int i=0;i<taille;i++){
        printf("%d\n ",resultat[i].taille);
    }
    return 0;
}
