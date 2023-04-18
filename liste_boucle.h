#ifndef GRAPH_CYCLE_FINDER_H
#define GRAPH_CYCLE_FINDER_H

#include <stdio.h>
#include <stdbool.h>

//fonction qui permet de trouver un cycle (si il existe) à partir d'un noeud en particulier
void recherche_cycle(int noeud,int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]);

//fonction qui applique la recherche de cycle sur l'ensemble des noeuds du cycle avec la condition qu'il ne soit pas déja parcouru par un cycle
void trouver_cycles(int n, int tab[n*n],bool visite[n],bool sur_chemin[n],int top, int chemin [n]);

#endif
