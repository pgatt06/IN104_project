# IN104_project
-projet IN104 -Ski - version_2 -BELLMANN FORD- 
-Nastassia Bonetti et Agathe Pascal -


Les lignes de commandes à écrire sont : 
make 
./myprogram data.txt 


VERSION_2

le make file execute les différents programme et cree un fichier executable du nom de " myprogram" 

-read_data.c = permet de lire les données d'un fichier et de le convertir en matrice adjacente dont les coefficients sont les plaisirs des pistes. 0 signifie qu'il n'y a pas de piste ( on suppose ici qu'il n'existe pas de piste à plaisir nul)

-chemin.c: fonction qui permet de déterminer le plaisir max d'un graphe. Grâce à l'algorithme de Bellmann-ford. 
 L'idée et de déterminer le plaisir max entre 0 et chaque points mais aussi si le cycle présente un cycle positif.
  Si il y a un cycle positif alors sky is the limit (si on détecte le cycle c'est qu'on peut y arriver dans le cycle).
   Quand à la détermination des plaisirs max, on détermine le chemin de plaisir maximum en déterminant le chemin (liste de
   prédécesseurs) afin de maximiser le plaisir ( test de supériorité).
 On trouve alors le plaisir maximal pour chaque point et il suffit juste de prendre le max de chacun.  

