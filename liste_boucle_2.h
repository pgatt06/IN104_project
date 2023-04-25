
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct cycle
{
    int taille;
    int* tableau;
};

void recherche_cycle(int noeud, int n, int tab[n*n], bool visite[n], bool sur_chemin[n], int top, int chemin[n], struct cycle** resultat, int* taille);
void trouver_cycles(int n, int tab[n*n], bool visite[n], bool sur_chemin[n], int top, int chemin[n], struct cycle** resultat, int* taille);


