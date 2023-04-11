#include <stdlib.h>
#include <stdio.h>
//fonction qui permet de déterminer si il existe un cycle entre le point de départ et le point ou l'on est (current) sans passer par le noeud parent
int exist_chemin(int n,int tab[n*n],int start_node, int current_node, int parent_node,int visited[n]) {
    visited[current_node] = 1;
    for (int i = 0; i < n; i++) {
        if (tab[current_node*n+i]) {
            if (!visited[i]) {
                if (exist_chemin(n,tab,start_node,i,current_node,visited)) {
                    return(1);
                }
            } else if (i != parent_node && i == start_node) {
                return (1);
            }
        }
    }
    return(0);
}

int est_cyclique(int n,int tab[n*n],int visited[n]) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (exist_chemin(n,tab, i, i,-1,visited)) {
                return (1);
            }
        }
    }
    return (0);
}

int main() {
    int n =3;
    int tab[n*n];
    for (int i=0; i<n*n;i++){
        tab[i]=0;
    }
    tab[1]=1;
    tab[5]=1;
    tab[6]=1;
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

   
    if(est_cyclique(n,tab,visited)) {
        printf("Le graphe contient un cycle.\n");
    } 
    else {
        printf("Le graphe ne contient pas de cycle.\n");
    }
    return (0);
 }
