// Red-Black Tree ADT interface

#include <stdbool.h>

typedef int Item;      // item is just a key

typedef struct Node *Tree;

Tree newTree();        // create an empty Tree
void freeTree(Tree);   // free memory associated with Tree
void showTree(Tree);   // display a Tree (sideways, red nodes in colour)

bool TreeSearch(Tree, Item);   // check whether an item is in a Tree
Tree TreeInsert(Tree, Item);   // insert a new item into a Tree
