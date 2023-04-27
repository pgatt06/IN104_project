#include <stdlib.h>
#include <stdio.h>
#include "sommet.h"
#include "utils.h"



void *malloc(size_t nombre_d_octets);
void free(void *ptr);

//structure contenant par rapport à un sommet donné l'arrivée et le plaisir correspondant
struct sommet_plaisir{int arrivee; int plaisir;};

//je récupère le nbre d'arrivées pour un sommet donné
int taille(int n, int T[n*n], int u)
{
    int compteur=0;
    for (int i=0;i<n;++i)
    {
        if (T[u*n+i]!=0)
        {
            ++compteur;
        }
    }
    return (compteur); 
}

//liste des arrivées pour un sommet donné
//compteur=nbre d'arrivées possibles pour le sommet concerné
//u le sommet 
//n la taille de la liste 
//T la liste avec les donées
int* liste_arrivee(int n, int T[n*n], int u, int compteur)
{
    int *A = malloc(compteur * sizeof(int));

    for (int i=0; i<n; ++i)
    {
        if (T[u*n+i]!=0)
        {
            A[i]=i;
        }
    }
    return (A);
}

//j'affiche ma liste avec toutes les arricées à partit du sommet u
void affichage(int *A, int c) {
  for (int i = 0; i < c; ++i) {
    printf("%d,", A[i]);
  }
}


//je fais de meme pour faire la liste des plaisirs pour chaque arrivée 
int* liste_plaisir(int n, int T[n*n], int u, int compteur)
{
    int *A = malloc(compteur * sizeof(int));

    for (int i=0; i<n; ++i)
    {
        if (T[u*n+i]!=0)
        {
            A[i]=T[u*n+i];
        }
    }
    return (A);
}
//je crée une liste de structure contenant les arrivées possibles avec le plaisir associé 
struct sommet_plaisir *recherche(int n, int T[n*n],int sommet, int compteur)
{
    struct sommet_plaisir *liste =malloc(compteur * sizeof(struct sommet_plaisir)); //liste de structure
    struct sommet_plaisir i;
    int *A = liste_arrivee(n, T, sommet, compteur);//toutes mes arrivées
    int *B = liste_plaisir(n, T, sommet, compteur);//tous les plaisirs de chaque arrivée
    for (int k = 0; k < compteur; ++k) 
    {
        i.arrivee = A[k];
        i.plaisir = B[k];
        liste[k] = i;
     }
  return (liste);//contient la structure (arrivée, plaisir) avec toutes les arrivées possibles à partir du sommet donné
}

//affichage de la liste de structure
void afficher_liste(struct sommet_plaisir *liste, int compteur) {
  for (int i = 0; i < compteur; i++) {
    printf("Sommet : %d, Plaisir : %d\n", liste[i].arrivee, liste[i].plaisir);
  }
}




int main() {
  int n = 2;
  int T[4];
  T[0] = 0;
  T[1] = -10;
  T[2] = 0;
  T[3] = 0;
  int u = 0;
  int compteur = taille(n, T, u);
  printf("%d\n", compteur);

  int *A = liste_arrivee(n, T, u, compteur);
  int *B = liste_plaisir(n, T, u, compteur);
  affichage(A, compteur);
  printf("\n");
  affichage(B, compteur);

  printf("\n");

  struct sommet_plaisir *C = recherche(n, T, u, compteur);
  afficher_liste(C, compteur);


}

