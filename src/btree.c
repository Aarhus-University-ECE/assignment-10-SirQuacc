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
  } 
  else { 
    if(x <= t->item){
    t->left = malloc(sizeof(tree_node));
    t->left->item = x; t->left->left = NULL; t->left->right = NULL;
    }
  }
  if(x > t->item && t->right != NULL){
    t->right = Insert(x, t->right);
  } 
  else {
    if(x > t->item){
    t->right = malloc(sizeof(tree_node));
    t->right->item = x; t->right->left = NULL; t->right->right = NULL;
    }
  }

  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  tree_node* copy = t; //Variable to scroll through tree
  tree_node** tPoint = &t; //Pointer that points to the pointer that points to t
  tree_node* deletDis; //Variable to save a pointer to the node we want to remove later
  tree_node** prevPoint; //Variable to scroll through when looking for a replacement for a deleted 
  while(!Empty(t)){
    if(x == copy->item){ //We are at the node we want to remove
      deletDis = copy; //Copy current node's pointer, to free up later
      if(copy->left == NULL){ //If our node doesn't have any left child, we set the pointer to t, to point to t's right child instead.
        *tPoint = copy->right;
        free(deletDis); //Free up the node we want to remove
        break; //Done, exit while loop and return tree
      }
      if(copy->right == NULL){ //Same as above, but with the right child instead of left
        *tPoint = copy->left;
        free(deletDis);
        break;
      }
      if(copy->right != NULL && copy->left != NULL){ //If the node we want to free, has both children, it gets more complicated
        prevPoint = &((*tPoint)->left); //Move left, and keep track of the pointer that points to this spot
        copy = copy->left; //Move left
        while(copy->right != NULL){ //Keep going right, to seek the largest number that is lower than the one we want to remove
          copy = copy->right;
          prevPoint = &((*prevPoint)->right);
        }
        if(copy->left != NULL){ //If this largest number has a left child, we need to remove this largest node, but reassign the pointer to it, to whatever it's left child was.
          *prevPoint = copy->left;
        }
        *tPoint = copy; //Now, the pointer to whatever we wanted to remove, needs to instead point to this largest node, t
        copy->right = deletDis->right; //Reassign the newly moved node's pointers, to fit its new place in the tree
        copy->left = deletDis->left;
      }
      free(deletDis);
      break;
    }
    if(x < copy->item){ //If what we're looking for is lower than current item, go left
      if(copy->left == NULL) break; //If the item doesn't exist in the tree, break to return the tree
      copy = copy->left;
      tPoint = &((*tPoint)->left);
    } else { //Otherwise go right
      if(copy->right == NULL) break; //If the item doesn't exist in the tree, break to return the tree
      copy = copy->right;
      tPoint = &((*tPoint)->right);
    }
  }

  return t;
}

bool Contains(int x, struct tree_node *t) {
  // Return true if the tree t contains item x. Return false otherwise.
  if(x == t->item) return true;
  if(x < t->item && t->left != NULL) return Contains(x, t->left);
  if(x > t->item && t->right != NULL) return Contains(x, t->right);
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
