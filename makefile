CC = gcc
SRC = deps/c_print/c_print.c random_p.c test.c 
OBJ = $(SRC:.c=.o)
CFLAGS = -I deps/c_print -g


test: $(OBJ)
	$(CC) $(OBJ) -o $@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) -c -o $@

.PHONY: clean
clean:
	rm -rf test $(OBJ)

