#include <stdlib.h>
#include <stdio.h>

//-1 =erreur 0 ok 1pb dans les données lues recup valeur piste et croissement et 1 si erreur dans les données

int read_info(char* fname,int piste, int croisements)
{
    FILE* fichier = fopen(fname,"r");

//verification que le fichier est lu et tout ok
    if (fichier==NULL)
    {
         printf("error\n");
         return(-1);
    }

//récupération du nombre de croissements et du nombre de pistes

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

return(0);
fclose(fichier);
}

//fonction qui permet de remplir la liste des valeurs des plaisir des pistes taille =(croisement+1) return 0 si tout est ok 

int remplir(char* fname,int taille, int tab[(taille)*(taille)],int piste, int croisements){
    FILE* fichier = fopen(fname,"r");

    //pour lire la première ligne (regarder comment sauter une ligne en c)
    fscanf(fichier,"%d %d",&croisements,&piste);

    //on parcourt les lignes du fichier pour recup les trajets
    int depart;
    int arrivee;
    int plaisir; 


    //à voir si on garde le fait de remplir par défaut les valeurs par des 0 : pb car création d une piste inexistante
    for(int i =0;i<((taille)*(taille));i++){tab[i]=0;}

    while (feof(fichier)!=0)
    {
        fscanf(fichier,"%d %d %d",&depart,&arrivee,&plaisir);
        tab[(taille)*depart+arrivee]=plaisir;
    }
    fclose(fichier);
    return(0);
    }


//permet d'afficher le tableau des plaisirs des pistes existantes 
void voir(int taille, int tab[(taille)*(taille)]){
    for(int i=0;i<((taille)*(taille));i++){
        printf("%d",tab[i]);
        printf("ok");
    //modulo le nombre de départ pour belle écriture en colonne et ligne comme un tableau
        //if(i%taille==0){printf("\n ");}
    }

}

int main(){
    int piste =0;
    int croisements =0;
    read_info("data.txt",piste,croisements);
    
    int taille = croisements+1;
    int tab[(taille)*(taille)];

    printf("%d\n",taille);
    printf("%d\n",croisements);

    remplir("data.txt",taille,tab,piste,croisements);
    voir(taille,tab);

    return(0);
}