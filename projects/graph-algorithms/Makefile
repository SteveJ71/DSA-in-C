CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

WGRAPH = src/wgraph.c

all: warshall kruskal floyd edmonds-karp

warshall: src/warshall.c
	$(CC) $(CFLAGS) -o $@ $^

kruskal: src/kruskal.c $(WGRAPH)
	$(CC) $(CFLAGS) -o $@ $^

floyd: src/floyd.c $(WGRAPH)
	$(CC) $(CFLAGS) -o $@ $^

edmonds-karp: src/edmonds_karp.c src/queue.c $(WGRAPH)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f warshall kruskal floyd edmonds-karp
