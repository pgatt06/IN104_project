#include <stdlib.h>
#include <stdio.h>

void* malloc(size_t nombre_d_octets);
void free(void* ptr);


void read_data(char* fname)
{
    FILE*fichier = fopen(fname,"r");

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
int depart;
int arrivee;
int plaisir; 

int taille=croisements+1;
int** tab=malloc(taille*taille*sizeof(int));

while (feof(fichier)!=0)
{
    fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
    tab[depart][arrivee]=plaisir;
}

//print le tableau pour voir si c'est bien fait 
for (int i=0; i<taille;++i)
{
    for (int j=0; j<taille;++j)
    {
        printf("%d",tab[i][j]);
    }
}
free(tab);

}

int main(){
    read_data("data.txt");
}


