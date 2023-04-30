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
