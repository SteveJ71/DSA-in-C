CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

all: treeLab

treeLab: src/treeLab.c src/BSTree.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f treeLab
