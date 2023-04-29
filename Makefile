CC=gcc
CFLAGS=-Wall -Werror

SRC = main.c read_data_3.c liste_boucle_2.c calcul_plaisir_chemin.c chemin_dep_arr.c taille_liste.c maximum_liste.c

myprogram: $(SRC)
	$(CC) $(CFLAGS) -o myprogram $(SRC)

clean:
	rm -f myprogram
