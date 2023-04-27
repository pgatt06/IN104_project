
#include <stdbool.h>

struct chemin {
    int taille;
    int arrete[];
};

struct liste_plaisir{
    int taille;
    int * liste_p;
};


void voir_chemin(struct chemin* chemin);
int tab_plaisir(int n, int T[n*n], int debut, int fin, bool visited[], struct chemin* chemin, struct liste_plaisir liste);

