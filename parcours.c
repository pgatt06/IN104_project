#include <stdlib.h>
#include <stdio.h>
#include "sommet.h"

void *malloc(size_t nombre_d_octets);
void free(void *ptr);


/*
but du programme:
-programme récursif
on a notre liste de structure contenant [(arrivee,plaisir), ...]
on recherche le plaisir max dans cette liste de structure
on récupère l'indice de ce plaisir
et on refait une liste à partir du nouveau sommet qui est celui du plaisir max
puis on recherche encore une fois le plaisir max 
on continue ce processus 
*/

