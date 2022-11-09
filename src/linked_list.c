#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this
  
  printf("-> %d ", p->value); //Print current value
  if(p->next != NULL) print_list(p->next); //If we're not at the end, recursively send the next node
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  if(p == NULL) //If we've gotten to the null pointer at the end of the list, or input was empty, return 0
  {
    return 0;
  }
  else{
    return (p->value*p->value + sum_squares(p->next)); //square the input value and recursively add the same from the next nodes.
  }
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  node* curNew = NULL; //Pointer that goes through the creation of a new list
  node* head = NULL; //Pointer to save the head of that new list
  if(p != NULL){ //Assuming we're not receiving an empty list, create first node and update head.
    curNew = make_node(f(p->value), NULL);
    head = curNew;
    p = p->next; //Scroll onwards in given list
  }
  while(p != NULL){ //Until we reach the end of the list, create new nodes applying the given function and add them to the new list
    curNew->next = make_node(f(p->value), NULL);
    curNew = curNew->next;
    p=p->next;
  }
  return head; //Return pointer to the head of the new list.
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
