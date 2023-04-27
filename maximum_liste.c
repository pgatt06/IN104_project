#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maximum_liste.h"

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