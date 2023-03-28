#include <stdlib.h>
#include <stdio.h>

FILE*file= fopen(data.txt,"rb");

//création des variables qu'on va récupérer dans data.txt
int croisements;
int piste; 

fscanf(file,"%d %d",&croisements,&piste);

//on ne peut pas avoir plus de croisements que de pistes 
if (croisements>piste)
{
    printf("error\n");
}

if (piste==0)
{
    printf("error\n");
}