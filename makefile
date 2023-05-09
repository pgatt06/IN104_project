CC=gcc
CFLAGS=-Wall -Werror

SRC = main.c read_data.c chemin.c test_cycle.c

myprogram: $(SRC)
	$(CC) $(CFLAGS) -o myprogram $(SRC)

clean:
	rm -f myprogram
