/*Ce programme permet de savoir si le graphe possède un cycle ou non */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//fonction qui permet de déterminer si il existe un cycle entre le point de départ et le point ou l'on est (current) sans passer par le noeud parent
// 1 = on a trouvé un cycle 
// 0 = on ne trouve pas de cycle 
int exist_chemin(int n,int tab[n*n],int depart, int position, int parent,bool visite[n]) {
    //on a visité le point de départ > 1
    visite[position] = 1;
    for (int i = 0; i < n; i++) {
        //si il existe une piste entre le point de départ et le point i
        if (tab[position*n+i]) {
            //si on n'a pas encore visité le point i 
            if (!visite[i]) {
                //on réitère avec le point de départ i tout en conservant le point initial du cycle et l'ancien point parcouru comme parent
                if (exist_chemin(n,tab,depart,i,position,visite)) {
                    return(1);
                }
            //si on a bouclé ie on est retourné sur le point de départ - la condition i!=parent permet de ne pas faire "demi-tour"
            } else if (i != parent && i == depart) {
                return (1);
            }
        }
    }
    return(0);
}

//on applique le test de savoir si il y a un cycle sur l'ensemble des points du cycle si on trouve un cycle alors le cycle est cyclique 
//1 = le graphe a un cycle 
//0 = le graphe n'a pas de cycle 
int est_cyclique(int n,int tab[n*n],bool visite[n]) {
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            if (exist_chemin(n,tab, i, i,-1,visite)) {
                return (1);
            }
        }
    }
    return (0);
}

int main() {
    int n =3;
    int tab[n*n];
    for (int i=0; i<n*n;i++){
        tab[i]=0;
    }
    tab[1]=1;
    tab[5]=1;
    tab[6]=1;
    bool visite[n];
    for (int i = 0; i < n; i++) {
        visite[i] = 0;
    }

   
    if(est_cyclique(n,tab,visite)) {
        printf("Le graphe contient un cycle.\n");
    } 
    else {
        printf("Le graphe ne contient pas de cycle.\n");
    }
    return (0);
 }
