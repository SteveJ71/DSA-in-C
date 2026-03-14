CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

all: dijkstra

dijkstra: src/dijkstra.c src/PQueue.c src/WGraph.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f dijkstra
