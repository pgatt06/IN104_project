CC=gcc
CFLAGS=-Wall -Werror


myprogram: main.c read_data_3.c liste_boucle.c
	$(CC) $(CFLAGS) -o myprogram main.c read_data_3.c liste_boucle_2.c calcul_plaisir_chemin.c

clean:
	rm -f myprogram
