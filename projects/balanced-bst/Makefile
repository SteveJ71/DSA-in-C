CC     = gcc
CFLAGS = -Wall -Werror -std=c11 -Iinclude

all: treeLab rbt

treeLab: src/treeLab.c src/BST.c src/queue.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

rbt: src/RBTester.c src/RBTree.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f treeLab rbt
