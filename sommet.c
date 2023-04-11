#include <stdlib.h>
#include <stdio.h>

struct sommet_plaisir{int arrivee; int plaisir;};

//je récupère le nbre d'arrivées pour un sommet donné
int taille(int n, int T[n*n], int u)
{
    int compteur=0
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
    int A[compteur];

    for (int i=0; i<n; ++i)
    {
        if (T[u*n+i]!=0)
        {
            A[i]=i;
        }
    }
    return (A);
}


//je fais de meme pour faire la liste des plaisirs pour chaque arrivée 
int* liste_plaisir(int n, int T[n*n], int u, int compteur)
{
     int A[compteur];

    for (int i=0; i<n; ++i)
    {
        if (T[u*n+i]!=0)
        {
            A[i]=T[u*n+i];
        }
    }
    return (A);
}
//je cré une liste de structure contenant les arrivées possibles avec le plaisir associé 
struct sommet_plaisir recherche(int n, int T[n*n],int sommet, int compteur)
{
    struct sommet_plaisir liste[compteur];
    struct sommet_plaisir i;
    int A=liste_arrivee(n,T,[n*n],sommet,compteur);
    int B=liste_plaisir(n,T,[n*n],sommet,compteur); 
    for(int k=0; k<compteur;++k)
    {
        i.arrivee= A[k];
        i.plaisir=B[k];
        liste[k]=i;
    }
    return (liste);
}