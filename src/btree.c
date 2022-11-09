#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  if(Empty(t)) {
    t = malloc(sizeof(tree_node));
    t->item = x; t->left = NULL; t->right = NULL;
    return t;
  } 
  if(x <= t->item && t->left != NULL){
    t->left = Insert(x, t->left);
  } else if(x <= t->item){
    t->left = malloc(sizeof(tree_node));
    t->left->item = x; t->left->left = NULL; t->left->right = NULL;
    return t; //Maybe unnecessary
  }
  if(x > t->item && t->right != NULL){
    t->right = Insert(x, t->right);
  } else if(x > t->item){
    t->right = malloc(sizeof(tree_node));
    t->right->item = x; t->left->left = NULL; t->left->right = NULL;
    return t; //Maybe unnecessary
  }

  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  return NULL;
}

bool Contains(int x, struct tree_node *t) {
  // Return true if the tree t contains item x. Return false otherwise.
  if(x == t->item) return true;
  if(x < t->item) return Contains(x, t->left);
  if(x > t->item) return Contains(x, t->right);
  return false; //Base case
}

struct tree_node *Initialize(struct tree_node *t) {
  return NULL;
}

int Empty(struct tree_node *t) {
  return t == NULL;
}

int Full(struct tree_node *t) {
  // Test if full (it can't be as a linked list)
  return 0;
}
