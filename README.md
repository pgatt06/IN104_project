# IN104_project

plusieurs versions ont été testées (cf les deux branches du github). 
Dans la version 1, il y a plusieurs codes qui fonctionnement mais sans succes final 
Dans la version 2, un algorithme de la première version a permis l'écriture de chemin.c qui permet de déterminer le plaisir maximal d'un graphe. 

Chaque version presente un main et un makefile. 
il faut donc taper make puis ./myprogram data.txt avec data.txt le fichier texte contenant les données 

MAIN: 

-data.txt = exemple de fichier de données 

VERSION_1 : 

-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-test_boucle.c = permet de savoir si le graphe présente un cycle ou non (utile ? )

-liste_boucle_2.c = permet d'afficher une liste des sommets de chaque cycle 
TODO : il faut que la fonction retourne un tableau de sommets et non seulement les afficher 
TODO : calculer le plaisir total de chaque cycle. 

-sommet.c : fonction qui permet de retourner la liste des sommets adjacents à un sommet donné ainsi que la liste des plaisirs associés .

-calcul_plaisir.c: calcul le plaisir associé à un chemin donné

-test_boucle.c : permet de tester si le graphe possède une boucle ou non

-chemin_dep_arr.c =permet de trouver tous es chemins possibles entre le début et la fin donnés en argument.

-taille_liste.c = programme qui permet de calculer la taille d'une liste donée en argument

-maximum_liste.c =programme qui renvoi le maximum d'une liste

-utils.c =renvoi une structure (maximum, indice_du_max) d'une liste en argument

VERSION_2:


-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-chemin.c: programme qui permet à la fois de calculer les plaisirs max pour chaque sommet et de tester s'il y a des cycles. Il fonctionne suivant la manière de l'algorithme de Bellman-Ford qui permet d'avoir des arcs dans le graphe de poids négatifs. 

