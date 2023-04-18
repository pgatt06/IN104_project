#include <stdlib.h>
#include <stdio.h>

//structure contenant par rapport à un sommet donné l'arrivée et le plaisir correspondant
struct sommet_plaisir {
    int arrivee;
    int plaisir;
};

//je récupère le nbre d'arrivées pour un sommet donné
int taille(int n, int T[n * n], int u);

//liste des arrivées pour un sommet donné
//compteur=nbre d'arrivées possibles pour le sommet concerné
//u le sommet 
//n la taille de la liste 
//T la liste avec les donées
int *liste_arrivee(int n, int T[n * n], int u, int compteur);

//j'affiche ma liste avec toutes les arricées à partir du sommet u
void affichage(int *A, int c);

//je fais de meme pour faire la liste des plaisirs pour chaque arrivée 
int *liste_plaisir(int n, int T[n * n], int u, int compteur);

//je cré une liste de structure contenant les arrivées possibles avec le plaisir associé 
struct sommet_plaisir *recherche(int n, int T[n * n], int sommet, int compteur);

//affichage de la liste de structure
void afficher_liste(struct sommet_plaisir *liste, int compteur);

