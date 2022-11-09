#ifndef BTREE_H
#define BTREE_H
#include <stdbool.h>

typedef struct tree_node { //Changed to typedef for easier coding
  int item;
  struct tree_node *left;
  struct tree_node *right;
} tree_node ;

int Empty(struct tree_node *t);
struct tree_node *Insert(int x, struct tree_node *t);
struct tree_node *Remove(int x, struct tree_node *t);
bool Contains(int x, struct tree_node *t);
struct tree_node *Initialize(struct tree_node *t);
int Full(struct tree_node *t);

#endif // BTREE_H