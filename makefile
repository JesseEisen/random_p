CC = gcc
SRC = random_p.c test.c
OBJ = $(SRC:.c=.o)
CFLAGS = -I deps/color -g


test: $(OBJ)
	$(CC) $(OBJ) -o $@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) -c -o $@

.PHONY: clean
clean:
	rm -rf test $(OBJ)

