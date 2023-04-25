#include <stdlib.h>
#include <stdio.h>
#include "sommet.h"
#include "utils.h"


void *malloc(size_t nombre_d_octets);
void free(void *ptr);


/*
but du programme:
-programme récursif
on a notre liste de structure contenant [(arrivee,plaisir), ...]
on recherche le plaisir max dans cette liste de structure
on récupère l'indice de ce plaisir
et on refait une liste à partir du nouveau sommet qui est celui du plaisir max
puis on recherche encore une fois le plaisir max 
on continue ce processus 
*/

int Max_plaisir(int n, int T[n*n]){
    int plaisir=0; 
    
    for(int j=0;j<compteur;j++){
        int compteur= taille (n,T,0);
        int compt_plaisir=0;
        int *L_plaisir=liste_plaisir(n,T,j,compteur);
        int *L_arrivee=liste_arrivee(n,T,j,compteur);

        maximum max(compteur,L_plaisir); 
        compt_plaisir=compt_plaisir+ L_plaisir[max.indice];
        L_plaisir[max.indice]=0;


}
}

#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100

int weight[MAX_NODES][MAX_NODES]; // matrice de poids
int n; // nombre de noeuds
int start, end; // sommets de départ et d'arrivée
int dist[MAX_NODES]; // distance entre le sommet de départ et chaque sommet
bool visited[MAX_NODES]; // sommets déjà visités
int prev[MAX_NODES]; // sommet précédent sur le chemin le plus court

void dijkstra() {
    for(int i = 0; i < n; i++) {
        dist[i] = -1; // initialisation des distances à -1
        visited[i] = false; // initialisation des sommets non visités
    }
    dist[start] = 0; // distance du sommet de départ à lui-même est 0
    
    // Boucle principale de Dijkstra
    while(!visited[end]) {
        // Recherche du sommet non visité de distance maximale
        int max_dist = -1;
        int max_node = -1;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] > max_dist) {
                max_dist = dist[i];
                max_node = i;
            }
        }
        if(max_node == -1) break; // pas de chemin trouvé
        
        // Mise à jour des distances des voisins non visités
        for(int i = 0; i < n; i++) {
            if(weight[max_node][i] > -1 && !visited[i]) {
                int new_dist = dist[max_node] + weight[max_node][i];
                if(new_dist > dist[i]) {
                    dist[i] = new_dist;
                    prev[i] = max_node;
                }
            }
        }
        visited[max_node] = true; // marquage du sommet comme visité
    }
}

void print_path(int node) {
    if(node == start) {
        printf("%d", node);
    } else {
        print_path(prev[node]);
        printf(" -> %d", node);
    }
}

int main() {
    // Lecture de la matrice adjacente
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &weight[i][j]);
        }
    }
    
    // Lecture des sommets de départ et d'arrivée
    scanf("%d %d", &start, &end);
    
    // Recherche du chemin de poids maximal
    dijkstra();
    printf("Le chemin de poids maximal est : ");
    print_path(end);
    printf("\n");
    
    return 0;
}

