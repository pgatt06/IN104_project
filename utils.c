#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
//changement de utils pour récupérer le max et l'indice dans une liste 
//pour cela on cré une structure 


struct maximum{int maxi;int indice;};



// fonction pour voir si un élément est dans une liste 
int in_liste(int data, int* liste, int n){
    for (int i = 0; i < n-1; i++)
    {
        if (liste[i]==data)
        {
            return 1;
        }
    }
    return 0;
}


//fonction pour la recherche d'un max renvoie le max et son indice 
struct maximum max(int size, int* liste){
    struct maximum k;
    int maxi = liste[0];
    int indice =0;
    for (int i = 0; i < size; i++)
    {
        if (liste[i]>maxi){
            maxi = liste[i];
            indice =i;
            k.maxi=maxi;
            k.indice=indice;
        }
    }
    return k;
}

//j'affiche ma structure 
void affichage_st(struct maximum l)
{
    printf("max=%d,indice=%d",l.maxi,l.indice);
    printf("\n");
}

/*int main(void)
{

    int size=3;
    int liste[size];
    liste[0]=1;
    liste[1]=2;
    liste[2]=3;
    struct maximum l=max (size,liste);
    affichage (l);
    


}*/