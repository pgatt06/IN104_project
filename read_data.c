#include <stdlib.h>
#include <stdio.h>

fichier = fopen("data.txt",r);


//création des variables qu'on va récupérer dans data.txt
int croisements;
int piste; 

fscanf(fichier,"%d %d",&croisements,&piste);
