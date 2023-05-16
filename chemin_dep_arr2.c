#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct chemin {
    int taille;
    int arrete[];
};

//permet d'afficher le chemin
void voir_chemin(struct chemin* chemin) {
    for (int i = 0; i < chemin->taille; i++) {
        printf("%d ", chemin->arrete[i]);
    }
    printf("\n");
}

int plaisir_CH(int n, int tab[n*n], int n_chemin, int chemin[n_chemin]){
    int compt_plaisir=0; // compteur du plaisir
    for(int i=1; i<n_chemin; i++){
        int depart = chemin[(i-1)]; //on détermine le point de départ et d'arrive pour déterminer le plaisir de la piste qui relie les deux points
        int arrive = chemin[i];
        compt_plaisir += tab[depart*n+arrive];
    }
        //int depart = chemin[(n_chemin-1)];
        //int arrive = chemin[0];
    // compt_plaisir=compt_plaisir+tab[depart*n+arrive];
    return (compt_plaisir);
}

//permet de trouver tous les chemins entre le début et la fin 
int trouver_chemin(int n, int T[n*n], int debut, int fin, bool visited[], struct chemin* chemin) {
    visited[debut] = true;
    chemin->arrete[chemin->taille++] = debut;
    int plaisir_f=-20;
    

    
    if (debut == fin){
        int test= plaisir_CH(n,T,chemin->taille,chemin->arrete);
        if (test>plaisir_f){plaisir_f=test;}
        voir_chemin(chemin);
    
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (T[debut*n+i] && !visited[i]) {
                
                trouver_chemin(n,T, i,fin, visited, chemin);
            }
        }
    }

    visited[debut] = false;
    chemin->taille--;
    return(plaisir_f);
}


/*
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

    trouver_chemin(n,tab, 0, 1, visited, &chemin);

    return 0;
}
    
    if (debut == fin){
        int test= plaisir(n,T,chemin->taille,chemin->arrete);
        if (test>plaisir_f){plaisir_f=test;}
        voir_chemin(chemin);
    
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (T[debut*n+i] && !visited[i]) {
                
                trouver_chemin(n,T, i,fin, visited, chemin);
            }
        }
    }

    visited[debut] = false;
    chemin->taille--;
    return(plaisir_f);
}

*/


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

    trouver_chemin(n,tab, 0, 1, visited, &chemin);

    return 0;
}
