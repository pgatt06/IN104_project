# IN104_project

MAIN: 

-data.txt = exemple de fichier de données 

VERSION_1 : 

-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-test_boucle.c = permet de savoir si le graphe présente un cycle ou non (utile ? )

-liste_boucle.c = permet d'afficher une liste des sommets de chaque cycle 
TODO : il faut que la fonction retourne un tableau de sommets et non seulement les afficher 
TODO : calculer le plaisir total de chaque cycle. 

-sommet.c : fonction qui permet de retourner la liste des sommets adjacents à un sommet donné ainsi que la liste des plaisirs associés .

VERSION_2:
-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-chemin.c: parcours du graphe avec des arcs qui peuvent avoir un plaisir négatif. Il permet de trouver le chemin avec le plaisir max et détecte en même temps s'il existe un cycle positif ou négatif et donc d'éliminer certains cas pour la résolution du problème. 
On forme un tableau de plaisir et des prédécesseurs. Quand on parcourt le graphe on met à jour les plaisirs et les prédécesseurs. Puis on vérifie la présence d'un cycle avec palisir infini puis on affiche les résultats et enfin on utilise une fonction qui recherche le max pour afficher le plaisir max qui peut être réalisé avec le graphe. 
