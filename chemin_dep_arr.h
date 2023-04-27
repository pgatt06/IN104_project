
#include <stdbool.h>

struct chemin {
    int taille;
    int arrete[];
};

void voir_chemin(struct chemin* chemin);
int trouver_chemin(int n, int T[n*n], int debut, int fin, bool visited[], struct chemin* chemin);

