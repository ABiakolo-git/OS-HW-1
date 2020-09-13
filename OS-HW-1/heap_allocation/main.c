// heap_allocation/main.c
// 
// Heap allocation example.
// 
// Nitsan Shai
// nshai@google.com

#include <stdio.h>
#include <stdlib.h>

struct tree {
  int value;
  struct tree *left_child;
  struct tree *right_child;
};

typedef struct tree tree_t;

tree_t *make_tree(int value) {
  tree_t *t = malloc(sizeof(tree_t));
  t->value = value;
  t->left_child = NULL;
  t->right_child = NULL;
  return t;
}

void free_tree(tree_t *t) {
  if (!t) {
    return;
  }
  
  if (t->left_child) {
    free_tree(t->left_child);
  }
  if (t->right_child) {
    free_tree(t->right_child);
  }
  
  free(t);
}

void make_other_things() {
  int fun_array[7] = {1,2,3,4,5,6,7};
  fun_array[5] = 20;
  char fun_string[25] = "I love programming in C!";
  char some_character = fun_string[6];
  int magic_number = some_character + 50;
}

int main() {
  tree_t *t1 = make_tree(3);
  printf("The value of t1 is %d\n", t1->value);

  tree_t *t2 = make_tree(4);
  printf("The value of t2 is %d, not surprising\n", t2->value);
  printf("But the value of t1 is now %d!\n", t1->value);

  printf("Making other things...\n");
  make_other_things();

  printf("Even worse, the value of t1 is now %d\n", t1->value);
  printf("And the value of t2 is %d\n", t2->value);
  
  free_tree(t1);
  free_tree(t2);
  return 0;
}
