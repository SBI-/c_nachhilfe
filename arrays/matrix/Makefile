CFLAGS=-Wall -Wextra -g -std=c11
LIBS=matrix.c -lm

array_matrix:
	gcc -o $@ $@.c $^ $(CFLAGS) $(LIBS)

clean:
	rm -f array_matrix
