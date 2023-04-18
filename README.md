# IN104_project

VERSION_1 :

-read_data_3.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-liste_boucle.c : affiche toutes les boucles présentes dans le graphe (elle affiche chaque sommet présent dans le cycle) - il faut encore rajouter un compteur pour déterminer le plaisir total ou créer une fonction qui a partir d’une boucle détermine le plaisir de la boucle. Dans la deuxième solution il faudra alors que la fonction liste_boucle.c renvoie un tableau a avec tous les sommets et ceci pour chaque boucle. 

-liste_boucle_2.c = test pour retourner un tableau avec tous les cycles présents dans le cycle (NE FONCTIONNE PAS -segmentation fault)

-test_boucle.c : permet de tester si le graphe possède une boucle ou non 

- sommet.c : permet de déterminer l’ensemble des sommets accessibles à partir d’un sommet donné ainsi que les plaisirs associés. 

L’idée du main serait dans un premier temps de lire les données, de déterminer si le graphe présente des cycles ou non ainsi que le plaisir des cycles (si positif = SKY IS THE LIMIT si négatif on ne s’y intéresse pas). Si le graphe ne possède pas de cycle, ou que des cycles dont le plaisir est négatif alors on va parcourir le graphe du début à la fin et pour chaque sommet on va aller sur la piste qui apporte le plus de plaisir jusqu’à déterminer le plaisir final, puis on réitère mais cette fois ci avec la piste qui apporte le plaisir maximal (on enlève la dernière piste prise dans le choix possible). 
On aura ainsi l’ensemble des plaisirs possibles du graphe, il suffira de prendre le max pour déterminer le plaisir maximal. 

compt_ligne : useless 

read_data.c et read_data_2.c versions tests
