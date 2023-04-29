CC=gcc
CFLAGS=-Wall -Werror

SRC = main.c read_data_3.c test_cycle_positif.c calcul_plaisir_chemin.c chemin_dep_arr.c utilitaires.c

myprogram: $(SRC)
	$(CC) $(CFLAGS) -o myprogram $(SRC)

clean:
	rm -f myprogram
