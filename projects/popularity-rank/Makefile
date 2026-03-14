CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

popularity-rank: src/popularity_rank.c src/WGraph.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f popularity-rank
