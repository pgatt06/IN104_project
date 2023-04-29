#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilitaires.h"


/* ce programme permet de déterminer le maximum dans une liste A de taille n*/
int maxi(int *A, int n)
{
    int max=A[0];
    for (int k=0; k<n; ++k)
    {
        if (A[k]>max)
        {
            max=A[k];
        }
    }
    return max; 
}

//j'affiche ma liste avec toutes les arricées à partit du sommet u
void affichage(int *A, int c) {
  for (int i = 0; i < c; ++i) {
    printf("%d,", A[i]);
  }
}
