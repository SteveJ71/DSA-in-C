CC      = gcc
CFLAGS  = -Wall -Werror -std=c11 -Iinclude

# Default graph implementation (adjacency list)
GRAPH   = src/graph_adjlist.c src/list.c

all: graphtester dfs bfs components euler hamiltonian cyclecheck

graphtester: src/graphtester.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

# Use edge-list representation for the tester (shows the alternative)
graphtester-edgelist: src/graphtester.c src/graph_edgelist.c
	$(CC) $(CFLAGS) -o $@ $^

dfs: src/dfs.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

bfs: src/bfs.c src/queue.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

components: src/components.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

euler: src/euler.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

hamiltonian: src/hamiltonian.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

cyclecheck: src/cyclecheck.c $(GRAPH)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f graphtester graphtester-edgelist dfs bfs components euler hamiltonian cyclecheck
