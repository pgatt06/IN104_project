#include <stdlib.h>
#include <stdio.h>



int taille_liste_entier(int* A)
{
    int taille=0;
    
    while (A[taille]!='\0')
    {
        taille++;
    }
    return taille; 
}

void affichage(int n)
{
    printf("%d\n",n);
}

int main ()
{
    int A[]={1,2,3,4,6};
    int k=taille_liste_entier(A);
    affichage(k);
}