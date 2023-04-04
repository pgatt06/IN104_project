#include <stdlib.h>
#include <stdio.h>

//-1 =erreur 0 ok 1pb dans les données lues 
int read_data(char* fname, int** out,int taille)
{
    FILE* fichier = fopen(fname,"r");

//verification que le fichier est lu et tout ok
    if (fichier==NULL)
    {
         printf("error\n");
         return(-1);
    }


//récupération du nombre de croissements et du nombre de pistes
int croisements;
int piste; 

fscanf(fichier,"%d %d",&croisements,&piste);

printf("%d,%d \n",croisements,piste);

//on ne peut pas avoir plus de croisements que de pistes 
if (croisements>piste)
{
    printf("error\n");
    return(1);
}

if (piste==0)
{
    printf("error\n");
    return(1);
}

//on parcourt les lignes du fichier pour recup les trajets
int depart;
int arrivee;
int plaisir; 

//creation de la liste contenant les valeurs de plaisir des pistes (liste representant un tableau car plus facile à traiter)
taille= croisements+1;
out = malloc(taille*taille*sizeof(int*));

// verification de l'allocation de la memoire 
if (out==NULL){
    printf("pb memoire non allouée");
    return(-1);
}
//remplissage de la liste des pistes avec les plaisirs associées 

/* à voir si on garde le fait de remplir par défaut les valeurs par des 0 : pb car création d'une piste inexistante
for(int i =0;i<taille*taille;i++){*out[i]=0}

*/
while (feof(fichier)!=0)
{
    fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
    *out[taille*depart+arrivee]=plaisir;
}
return(0);
}

//permet d'afficher le tableau des plaisirs des pistes existantes 
void voir(int** out,int taille){
    for(int i=0;i<taille;i++){
        printf("%d",*out[i]);
    //modulo le nombre de départ pour belle écriture en colonne et ligne comme un tableau
    if(i%taille==0){printf("\n ");}
    }
  
}

int main(){

    int** out = NULL;
    int taille =0;
    read_data("data.txt",out,taille);
    voir (out,taille);
    free(out);
}

