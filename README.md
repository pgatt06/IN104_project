# IN104_project

VERSION_1 :

-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-liste_boucle.c : affiche toutes les boucles présentes dans le graphe (elle affiche chaque sommet présent dans le cycle) - il faut encore rajouter un compteur pour déterminer le plaisir total ou créer une fonction qui a partir d’une boucle détermine le plaisir de la boucle. Dans la deuxième solution il faudra alors que la fonction liste_boucle.c renvoie un tableau a avec tous les sommets et ceci pour chaque boucle. 

-liste_boucle_2.c = test pour retourner un tableau avec tous les cycles présents dans le cycle ainsi que leur taille 

_calcul_plaisir.c=  calcul le plaisir associé à un chemin donné 

-test_boucle.c : permet de tester si le graphe possède une boucle ou non 

-sommet.c : permet de déterminer l’ensemble des sommets accessibles à partir d’un sommet donné ainsi que les plaisirs associés.On récupère l'ensemble des arrivées et des plaisirs sous forme de liste et on renvoi une liste de structure de type [ (arrivée, plaisir), () ....] pour un sommmet donné en argument. 


-chemin_dep_arr.c =permet de trouver tous es chemins possibles entre le début et la fin donnés en argument. 

-taille_liste.c = programme qui permet de calculer la taille d'une liste donée en argument

-maximum_liste.c =programme qui renvoi le maximum d'une liste

-utils.c =renvoi une structure (maximum, indice_du_max) d'une liste en argument

L’idée du main serait dans un premier temps de lire les données, de déterminer si le graphe présente des cycles ou non ainsi que le plaisir des cycles (si positif = SKY IS THE LIMIT si négatif on ne s’y intéresse pas). Si le graphe ne possède pas de cycle, ou que des cycles dont le plaisir est négatif alors on va parcourir le graphe du début à la fin et pour chaque sommet on va aller sur la piste qui apporte le plus de plaisir jusqu’à déterminer le plaisir final, puis on réitère mais cette fois ci avec la piste qui apporte le plaisir maximal (on enlève la dernière piste prise dans le choix possible). 
On aura ainsi l’ensemble des plaisirs possibles du graphe, il suffira de prendre le max pour déterminer le plaisir maximal. 


