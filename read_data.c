#include <stdlib.h>
#include <stdio.h>

FILE*file= fopen(data.txt,"rb");

//création des variables qu'on va récupérer dans data.txt
int croisements;
int piste; 

fscanf(file,"%d %d",&croisements,&piste);
