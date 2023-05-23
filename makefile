CC=gcc


SRC = main.c read_data.c test_cycle.c chemin.c

myprogram: $(SRC)
	$(CC) $(CFLAGS) -o myprogram $(SRC)

clean:
	rm -f myprogram
