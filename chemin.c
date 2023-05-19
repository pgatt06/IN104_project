#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chemin.h"

int IN(int n, int list[n], int a ){
    for (int i =0; i<n; i++){
        if (list[i]==a){return(1);}

    }
    return(0);
}

int plaisir_CH(int n, int tab[n*n], int n_chemin, int *chemin){
    int compt=0; // compteur du plaisir
    for(int i=1; i<n_chemin; i++){
        int depart = chemin[(i-1)]; //on détermine le point de départ et d'arrive pour déterminer le plaisir de la piste qui relie les deux points
        int arrive = chemin[i];
        compt += tab[depart*n+arrive];
    }
    return (compt);
}

void chemin_f(int n,int tab[n*n], int a,int *chemin, int position,int *plaisir) {
  chemin[position] = a;
  //On calcule le plaisir de l'itinéraire actuel
  int test = plaisir_CH(n,tab,position + 1,chemin);
  printf("test %d\n",test);
  if (*plaisir<test){
    *plaisir = test;
  }

    for (int i = 0; i < n; ++i) {
      if (tab[a*n+i]!=0 && IN(position+1,chemin,i)==0){  
        position++;//On va chercher dans la position suivante un autre chemin
        chemin_f(n,tab,i,chemin,position,plaisir);
        position--;
      }
    }
}

