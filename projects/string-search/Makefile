CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

all: KMP trieTester boyer-moore

KMP: src/KMP.c
	$(CC) $(CFLAGS) -o $@ $^

trieTester: src/trieTester.c src/Trie.c
	$(CC) $(CFLAGS) -o $@ $^

boyer-moore: src/boyer_moore.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f KMP trieTester boyer-moore
