#include <stdio.h>
#include <stdbool.h>

int plaisir(int n, int tab[n*n],int n_chemin, int chemin[n_chemin]){
    int compt_plaisir=0;
    for(int i=1;i<n_chemin;i++){
        int depart = n_chemin[i-1];
        int arrive = n_chemin[i];
        compt_plaisir=compt_plaisir+tab[depart*n+arrive];
    }
    return(compt_plaisir);
}

int main(){

}