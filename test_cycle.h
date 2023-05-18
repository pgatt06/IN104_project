#include <stdio.h>


void recherche_cycle(int noeud,int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]);
void trouver_cycles(int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n] );