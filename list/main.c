#include <stdio.h>
#include "list.h"
#include <stdlib.h>
int main(int argc, char *argv[]) {
  printf("Tests for linked list implementation\n");
  //creates list 7,8,9
  list_t* first = list_alloc();
  node_t* temp = malloc(sizeof(node_t));
  node_t* temp_two;
  temp -> value = 7;
  first->head = temp;
  temp_two = malloc(sizeof(node_t));
  temp_two -> value = 8;
  temp -> next = temp_two;
  node_t* temp_three;
  temp_three = malloc(sizeof(node_t));
  temp_three -> value = 9;
  temp_two -> next = temp_three;
  temp_three -> next = NULL;
  
  // prints 7,8,9
  list_print(first);
  printf("\n");
  
  
  // prints 7,8,9,10 added 10 to end
  list_add_to_back(first, 10);
  list_print(first);
  printf("\n");

  // prints 5,7,8,9,10 added 5 to front
  list_add_to_front(first, 5);
  list_print(first);
  printf("\n");

  // prints 4,5,7,8,9,10 added 4 to front using index at function
  list_add_at_index(first, 4, 0);
  list_print(first);
  printf("\n");

  // prints 4,5,6,7,8,9,10 added 6 to 2nd index for 0, 1...
  list_add_at_index(first, 6, 2);
  list_print(first);
  printf("\n");

// can add at the end of the index 
  list_add_at_index(first, 6, 7);
  list_print(first);
  printf("\n");

// //cant add past the end of the list
  list_add_at_index(first, 6, 9);
  list_print(first);
  printf("\n");

//remove from last element, takes out 6 and returns it
  printf("Removed: %d\n", list_remove_from_back(first));
  printf("Removed: %d\n", list_remove_from_back(first));
  printf("\n");
  list_print(first);
  printf("\n");

//removed from first element, takes out 4 and returns it
  printf("Removed: %d\n", list_remove_from_front(first));
  printf("\n");
  list_print(first);
  printf("\n");

//takes out third index which is 8 and returns it
  printf("Removed: %d\n", list_remove_at_index(first, 3));
  printf("\n");
  list_print(first);
  printf("\n");

//checks if is in list, 5 and 6 are but three is not so returns 1 1 0 for true, true, false
  printf("%d\n", list_is_in(first, 5));
  printf("%d\n", list_is_in(first, 6));
  printf("%d\n", list_is_in(first, 3));
  printf("\n");

//checks elment at index, if index is too high says not in list or prints element there so 5 is at top-0, 3 is 9 and 5 doesnt exist
  list_print(first);
  printf("\n");
  printf("%d\n", list_get_elem_at(first, 5));
  printf("%d\n", list_get_elem_at(first, 0));
  printf("%d\n", list_get_elem_at(first, 3));
  printf("\n");

//gets index of element. 5 is top-0, 9 is 3 and 3 is not there so says not in list.
  printf("%d\n", list_get_index_of(first, 5));
  printf("%d\n", list_get_index_of(first, 9));
  printf("%d\n", list_get_index_of(first, 3));
  printf("\n");

  printf("done");
  printf("\n");

}