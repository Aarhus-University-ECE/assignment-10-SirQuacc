#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>		/* bool, true, false */
#include "btree.h"



typedef struct stack
{
  struct tree_node *node;
  struct stack *next;
} stack;
bool isEmpty (stack * topp)
{
  return (topp->next == NULL && topp->node == NULL); //If stack points to the initialized node, it's empty
}
void print_node (tree_node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("-> %d ", p->item);
}
void initStack (stack* topp){ //Initialize a stack with a root node, that points to nothing
  topp->next = NULL;
  topp->node = NULL;
}
stack *push (stack * topp, tree_node * node)
{
  stack* add = malloc(sizeof(stack)); //Create new "stack" node to add to the list
  add->node = node; //add the tree node to "add" as the top in the stack
  add->next = topp; //add previous topp node below "add"
	return add;
}
tree_node *make_node (int num, tree_node * left, tree_node * right)
{
  tree_node* new = malloc(sizeof(tree_node)); //Allocate new node in heap
  new->item = num; //add num data
  new->left = left; //add children
  new->right = right;
	return new; //return pointer to new node
}
void free_node (tree_node * p) //free a given node, and its children
{
  if(p->right != NULL){
    free_node(p->right);
  }
  if(p->left != NULL){
    free_node(p->left);
  }
  free(p);
}
void print_tree (tree_node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->item);


  if (p->left)
    {
      print_tree (p->left, depth + 1);
    }

  if (p->right)
    print_tree (p->right, depth + 1);
}
stack *pop (stack ** topp) //Using double pointer allows editing the what the input points toward.
{
  assert(!isEmpty(*topp)); //Can't pop from an empty stack
  stack* save = *topp; //Save a copy of the top stack node
  *topp = (*topp)->next; //New top node is the next one
	return save; //Return the popped node
}
void DFT (tree_node* root)
{
  printf("The given tree:\n");
  print_tree(root, 0); //Print the given tree first

  stack* mainStack = malloc(sizeof(stack)); //Allocate a stack node
  initStack(mainStack); //Initialize the stack
  mainStack = push(mainStack, root); //Push the root on to the stack first
  stack* popped; //Pointer to the saved node after popping

  printf("Order of visiting tree: ");
  while(!isEmpty(mainStack)){ //!isEmpty(mainStack)
    popped = pop(&mainStack); //Pop the top node, popped variable saves pointer to the popped node
    print_node(popped->node); //Print the visited (popped) node's value.
    if(popped->node->right != NULL) mainStack = push(mainStack, popped->node->right); //If there is a right child, add this to the stack
    if(popped->node->left != NULL) mainStack = push(mainStack, popped->node->left); //If there is a left child, add this to the stack
    free(popped); // Free stack-node, clean-up.
  }
  printf("\n");
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}






// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
  struct tree_node *root = NULL;


  Contains(3, NULL);
  root = Initialize(root);
  
  
  root = Insert(20, root);
  root = Insert(5, root);
  root = Insert(1, root);
  root = Insert(15, root);
  root = Insert(9, root);
  root = Insert(7, root);
  root = Insert(12, root);
  root = Insert(30, root);
  root = Insert(25, root);
  root = Insert(40, root);
  root = Insert(45, root);
  root = Insert(42, root);

  for(int i = 0; i < 46; i++){
    printf("Contains %d: %d\n",i ,Contains(i, root));
  }
  
  //DFT(root);
  return 0;

}


