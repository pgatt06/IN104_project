#include <stdlib.h>
#include <stdio.h>

void* malloc(size_t nombre_d_octets);
void free(void* ptr);
int main()
{
    fichier = fopen("data.txt",r);

if (fichier==NULL )
{
    printf("error\n");
}
//création des variables qu'on va récupérer dans data.txt
int croisements;
int piste; 

fscanf(fichier,"%d %d",&croisements,&piste);

//on ne peut pas avoir plus de croisements que de pistes 
if (croisements>piste)
{
    printf("error\n");
}

if (piste==0)
{
    printf("error\n");
}

//on parcourt les lignes du fichier pour recup les trajets
int sommet;
int arrivee;
int plaisir; 

int tab*;

int cpt=0;
while (feof(fichier)!=0)
{
    fscanf(fichier,"%d %d %d",&sommet,&arrivee,&plaisir);
    ++cpt;
}

tab=malloc(cpt*3*sizeof(int));

}



