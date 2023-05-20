# IN104_project
groupe: Agathe PAscal-Nastassia Bonetti 

plusieurs versions ont été testées (cf les deux branches du github). 
Dans la version 1, il y a plusieurs codes qui fonctionnement mais sans succes final 
Dans la version 2, un algorithme de la première version a permis l'écriture de chemin.c qui permet de déterminer le plaisir maximal d'un graphe. 
Dans la version 3, on reprend les bases de la version 1 mais en simplifiant la recherche des plaisirs sur tous les chemins possibles. 

Les versions 2 et 3 sont celles qui sont exécutables et affichent le bon résultat. 

Chaque version presente un main et un makefile. 
il faut donc taper make puis ./myprogram data.txt avec data.txt le fichier texte contenant les données 
Encore une fois les lignes de commandes à écrire sont : 
make 
./myprogram data.txt 


VERSION_2:
-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-chemin.c: parcours du graphe avec des arcs qui peuvent avoir un plaisir négatif. Il permet de trouver le chemin avec le plaisir max et détecte en même temps s'il existe un cycle positif ou négatif et donc d'éliminer certains cas pour la résolution du problème. 
On forme un tableau de plaisir et des prédécesseurs. Quand on parcourt le graphe on met à jour les plaisirs et les prédécesseurs. Puis on vérifie la présence d'un cycle avec palisir infini puis on affiche les résultats et enfin on utilise une fonction qui recherche le max pour afficher le plaisir max qui peut être réalisé avec le graphe. 
-chemin.c: fonction qui permet de déterminer le plaisir max d'un graphe. L'idée et de déterminer le plaisir max entre 0 et chaque points mais aussi si le cycle présente un cycle positif. Si il y a un cycle positif alors sky is the limit (si on détecte le cycle c'est qu'on peut y arriver dans le cycle). Quand à la détermination des plaisirs max, on détermine le chemin de plaisir maximum en déterminant le chemin (liste de prédécesseurs) afin de maximiser le plaisir ( test de supériorité). On trouve alors le plaisir maximal pour chaque point et il suffit juste de prendre le max de chacun.  


