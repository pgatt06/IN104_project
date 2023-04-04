#include <stdlib.h>
#include <stdio.h>

int read_data(char* fname, int** out)
{
    FILE* fichier = fopen(fname,"r");

    if (fichier==NULL )
    {
         printf("error\n");
    }


//création des variables qu'on va récupérer dans data.txt
int croisements;
int piste; 

fscanf(fichier,"%d %d",&croisements,&piste);

printf("%d,%d \n",croisements,piste);

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

int taille= (int)(croisements+1);
out = (int**)malloc(taille*taille*sizeof(int*));

if (out==NULL){
    printf("caca");
    return(-1);
}

int counter = 0;
while (feof(fichier)!=0)
{
    fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
    *out[counter]=plaisir;
    printf("%d",*out[counter]);
    //modulo tu sais pour savoir si on est allés à un nouvelle ligne genre on arrive au bout de la ligne tmtc
    counter++;

}
return 1;
}


int main(){

    int** out = NULL;
    read_data("data.txt",out);
    free(out);
}

