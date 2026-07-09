// Red-Black Tree ADT implementation

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "../include/RBTree.h"

#define PRINT_COLOUR_RED   "\x1B[31m"
#define PRINT_COLOUR_RESET "\x1B[0m"

#define data(tree)   ((tree)->data)
#define left(tree)   ((tree)->left)
#define right(tree)  ((tree)->right)
#define colour(tree) ((tree)->colour)
#define isRed(tree)  ((tree) != NULL && (tree)->colour == RED)

typedef enum {RED,BLACK} Colr;

typedef struct Node {
   int  data;
   Colr colour;
   Tree left, right;
} Node;

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// make a new node containing data
Tree newNode(Item it) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   data(new) = it;
   colour(new) = RED;
   left(new) = right(new) = NULL;
   return new;
}

Tree rotateRight(Tree);
Tree rotateLeft(Tree);

// fix red-red violations after insertion
static Tree insertFixup(Tree t) {
   // left-left or left-right red-red: rotate right
   if (isRed(left(t)) && isRed(right(left(t)))) {
      left(t) = rotateLeft(left(t));
   }
   if (isRed(left(t)) && isRed(left(left(t)))) {
      t = rotateRight(t);
      colour(t) = BLACK;
      colour(right(t)) = RED;
   }
   // right-right or right-left red-red: rotate left
   if (isRed(right(t)) && isRed(left(right(t)))) {
      right(t) = rotateRight(right(t));
   }
   if (isRed(right(t)) && isRed(right(right(t)))) {
      t = rotateLeft(t);
      colour(t) = BLACK;
      colour(left(t)) = RED;
   }
   return t;
}

static Tree insertRB(Tree t, Item it) {
   if (t == NULL)
      return newNode(it);
   if (it < data(t))
      left(t) = insertRB(left(t), it);
   else if (it > data(t))
      right(t) = insertRB(right(t), it);
   else
      return t;  // duplicate, no insert
   return insertFixup(t);
}

// insert a new item into a tree
Tree TreeInsert(Tree t, Item it) {
   t = insertRB(t, it);
   colour(t) = BLACK;  // root is always black
   return t;
}

// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
   if (t == NULL)
      return false;
   else if (it < data(t))
      return TreeSearch(left(t), it);
   else if (it > data(t))
      return TreeSearch(right(t), it);
   else                                 // it == data(t)
      return true;
}

Tree rotateRight(Tree n1) {
   if (n1 == NULL || left(n1) == NULL)
      return n1;
   Tree n2 = left(n1);
   left(n1) = right(n2);
   right(n2) = n1;
   return n2;
}

Tree rotateLeft(Tree n2) {
   if (n2 == NULL || right(n2) == NULL)
      return n2;
   Tree n1 = right(n2);
   right(n2) = left(n1);
   left(n1) = n2;
   return n1;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   if (t != NULL) {
      showTreeR(right(t), depth+1);
      int i;
      for (i = 0; i < depth; i++)
	 putchar('\t');            // TAB character
      if (isRed(t))
	 printf("%s%d%s\n", PRINT_COLOUR_RED, data(t), PRINT_COLOUR_RESET);
       else
	 printf("%d\n", data(t));
      showTreeR(left(t), depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}
