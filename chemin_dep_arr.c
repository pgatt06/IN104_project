#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcul_plaisir_chemin.h"
#include "chemin_dep_arr.h"
#include "utilitaires.h"


/* Ce programme permet de déterminer tous les chemins qui existent entre un point de départ et un point d'arrivée il retourne une struct de type chemin (taille et liste des sommets du chemin)*/


//permet d'afficher le chemin à partir de la struct chemin (taille et liste des sommets )
void voir_chemin(struct chemin* chemin) {
    printf("CHEMIN : \n");
    for (int i = 0; i < chemin->taille; i++) {
        printf("%d ", chemin->arrete[i]);
    }
    printf("\n");
}

//permet de trouver tous les chemins entre le début et la fin 
/* Cette fonction prend en argument le nombre de sommets du graphe n, la matrice adjacente T, le début et la fin considéré, la liste visited permet de savoir si on est
déja passé ou non par un point donné, la struct chemin est le chemin que l'on chercher et la struct liste_plaisir est la liste de tous les plaisirs de chaque chemin 
(contient le nombre de chemin ainsi qu'une liste des plaisirs de chaque chemin )*/
void tab_plaisir(int n, int T[], int debut, int fin, bool visited[], struct chemin* chemin, struct liste_plaisir* liste) {
    visited[debut] = true; // on est au départ
    int* tmpChemin = NULL; // pointeur temporaire qui permet la récupération du chemin
    tmpChemin = malloc(chemin->taille*sizeof(int)); // initialisation et copie des valeurs de chemin dans le pointeur temporaire

    for(int i = 0; i < chemin->taille; i++)
    {
        tmpChemin[i] = chemin->arrete[i];
    }
    chemin->arrete = realloc(chemin->arrete,(chemin->taille+1)*sizeof(int)); //on augmente la taille du chemin

    for(int i = 0; i < chemin->taille; i++) // on remet les valeurs dans le chemin ainsi que le point ou l'on se trouve actuellement 
    {
        chemin->arrete[i] = tmpChemin[i];
    }
    chemin->arrete[chemin->taille] = debut;

    free(tmpChemin); // on libère la mémoire du chemin tampon
    chemin->taille++; // on augmente la taille du chemin
  
    // si on arrive à la fin ou l'on souhaitait arriver on a trouvé un chemin
    if (debut == fin){
        // on fait le même raisonnement qu'avec les chemins mais cette fois ci avec la liste des plaisirs 
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
        liste->liste_p[liste->taille] = plaisir_CH(n,T,chemin->taille,chemin->arrete);

        free(tmpListe);
        liste->taille++;

        // permet de visualiser le chemin (test)
        voir_chemin(chemin);
    } 

    // si on n'est pas encore à la fin alors on continue de parcourir le graphe
    else {
        for (int i = 0; i < n; i++) {
            //condition d'existente d'une piste entre les deux sommets et qu'on n'ait pas déjà visité le sommet en question (i)
            if (T[debut*n+i] != 0 && !visited[i]) {
                
                tab_plaisir(n, T, i, fin, visited, chemin,liste);
            }
        }
    }
    //permet la récursivité on remet le point ou l'on est comme non visité et on modifie la taille du chemin en conséquent 
    visited[debut] = false;
    chemin->taille--;
    
}



// test de la fonction
/*int main() {
    
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

    tab_plaisir(n, tab, 0, 3, visited, &chemin,&liste);
    
   
    affichage(liste.liste_p,liste.taille);

    return 0;
}
*/