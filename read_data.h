#include <stdlib.h>
#include <stdio.h>


//création d'une structure
struct data {
    int piste;
    int croisements;
};

//déclaration de la fonction read_info qui permet de lire le fichier et de récupérer le nombre de croisements et de pistes
struct data read_info(char* fname, struct data k);

//déclaration de la fonction remplir qui permet de remplir le tableau des valeurs des plaisirs des pistes
struct data remplir(char* fname, int taille, int tab[(taille)*(taille)], struct data k);

//déclaration de la fonction voir qui permet d'afficher le tableau des plaisirs des pistes existantes
void voir(int taille, int tab[(taille)*(taille)]);
