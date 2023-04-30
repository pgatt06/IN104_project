#include <stdlib.h>
#include <stdio.h>
#include "read_data.h"




//créé une structure
//struct data {int piste;int croisements;};


struct data read_info(char* fname, struct data k)
{
    FILE* fichier = fopen(fname,"r");

//verification que le fichier est lu et tout ok
    if (fichier==NULL)
    {
         printf("error\n");
         
    }

//récupération du nombre de croissements et du nombre de pistes

fscanf(fichier,"%d %d",&k.croisements,&k.piste);

printf("\n");
printf("le nombre de croisements est :%d et le nombre de pistes est :%d \n",k.croisements,k.piste);
printf("\n");
//on ne peut pas avoir plus de croisements que de pistes 
if (k.croisements>k.piste)
{
    printf("error\n");
    
}

if (k.piste==0)
{
    printf("error\n");
   
}

return(k);
fclose(fichier);
}

//fonction qui permet de remplir la liste des valeurs des plaisir des pistes taille =(croisement+1) return 0 si tout est ok 

struct data remplir(char* fname,int taille, int tab[(taille)*(taille)],struct data k){
    FILE* fichier = fopen(fname,"r");

    //pour lire la première ligne (regarder comment sauter une ligne en c)
    fscanf(fichier,"%d %d",&k.croisements,&k.piste);
    //printf("%d,%d \n",croisements,piste);

    //on parcourt les lignes du fichier pour recup les trajets
    int depart;
    int arrivee;
    int plaisir; 


    //à voir si on garde le fait de remplir par défaut les valeurs par des 0 : pb car création d une piste inexistante
    for(int i =0;i<((taille)*(taille));i++){tab[i]=0;}

    while (feof(fichier)==0)
    {
        fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
        tab[(taille)*depart+arrivee]=plaisir;
        //printf("%d \n",tab[(taille)*depart+arrivee]);
    }
    fclose(fichier);
    return(k);
    }


//permet d'afficher le tableau des plaisirs des pistes existantes 
void voir(int taille, int tab[(taille)*(taille)]){
    printf("La matrice adjacente est :\n");
    for(int i=0;i<((taille)*(taille));i++){
        printf("%d ",tab[i]);
    //modulo le nombre de départ pour belle écriture en colonne et ligne comme un tableau
        if((i+1)%(taille)==0){printf("\n ");}
    }

}

/*int main(){
    struct data i;
    struct data k=read_info("data.txt",i);
    
    int taille = k.croisements+1;
    int tab[(taille)*(taille)];

    struct data j=remplir("data.txt",taille,tab,k);
    voir(taille,tab);

    return(0);
}*/