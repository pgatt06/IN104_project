#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maximum_liste.h"


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