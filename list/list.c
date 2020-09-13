// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//allocate space
list_t *list_alloc(){
  list_t* new_list = malloc(sizeof(list_t));
  if (new_list == NULL){
    printf("Allocation Failed");
    return NULL;
  }
  new_list -> head = NULL;
  return new_list;
}

//free space
void list_free(list_t *l) {
  if (l -> head == NULL) {
    return;
  }
  node_t* curr = l -> head;
  node_t* temp;
  while(curr != NULL){
    temp = curr;
    curr = curr -> next;
    free(temp);
  }
  l -> head = NULL;
  free(l);
}

//print linked list 
void list_print(list_t *l) {
  if (l->head == NULL){
    printf("empty list\n");
    return;
  }
  node_t* curr = l-> head;
  while (curr != NULL){
    printf("%d \n", curr-> value);
    curr = curr-> next;
  }
  return;
}

//get length of list 
int list_length(list_t *l) { 
  if (l-> head == NULL)
  {
    return 0;
  }
  node_t* curr = l->head; 
  int count = 0;
  while (curr != NULL){
    count += 1;
    curr = curr->next;
  }
  return count;
 }

// append 
void list_add_to_back(list_t *l, elem value) {
  node_t* new_node = malloc(sizeof(new_node));
  new_node -> value = value;
  new_node -> next = NULL;
  if (l->head == NULL)
  {
    l -> head = new_node;
  }
  else{
    node_t* curr = l->head;
    while(curr->next != NULL){
      curr = curr -> next;
    }
    curr -> next = new_node;
    new_node = curr -> next;
  }
}

// add to the fron
void list_add_to_front(list_t *l, elem value) {
  node_t* new_node = malloc(sizeof(new_node));
  new_node -> value = value;
  if (l->head == NULL)
  {
    l -> head = new_node;
    new_node -> next = NULL;
  }
  else{
    new_node -> next = l -> head;
    l-> head = new_node;
  }
}

// add at a specific index. using the indexing for software engineers
void list_add_at_index(list_t *l, elem value, int index) {
  node_t* new_node = malloc(sizeof(new_node));
  new_node -> value = value;
  int count = 0;
  node_t* curr_node = l->head;
  int len = list_length(l);
  if (l-> head == NULL)
  {
    printf("List does not exist");
    return;
  }
  if(index == 0)
  {
    list_add_to_front(l, value);
    return;
  }
  while (count < index-1 && curr_node != NULL){
    count += 1;
    curr_node = curr_node -> next;
  }
  if (len == index){
    list_add_to_back(l, value);
    return;
  }

  if (len < index){
    printf("Out of bounds\n");
    return;
  }
    new_node -> next = curr_node -> next;
    curr_node -> next = new_node;
    return;
}

// remove the back of the list and then return that last number 
elem list_remove_from_back(list_t *l) { 
  node_t* temp = NULL;
  node_t* curr = l->head;
  if (l->head == NULL)
  {
    printf("empty list");
    return -1;
  }
  if (l->head->next == NULL)
  {
    l-> head = NULL;
    return -1;
  }
  else{
    while(curr->next->next != NULL){
      curr = curr -> next;
    }
    temp = curr -> next;
    curr -> next = NULL;
  }
  return temp -> value;
}

// remove head of the list and return that first number
elem list_remove_from_front(list_t *l) { 
  node_t* temp_node;
  node_t* temp;
  if (l->head == NULL)
  {
    printf("list already empty");
    return -1;
  }
  if (l->head->next == NULL)
  {
    temp = l-> head;
    l-> head = NULL;
    return temp -> value;
  }
  else{
    temp = l -> head;
    temp_node = l -> head -> next;
    l -> head = temp_node;
  }
  return temp -> value;
  }

// remove element at a particular index 
elem list_remove_at_index(list_t *l, int index) { 
  node_t* prev;
  node_t* temp;
  int count = 0;
  node_t* curr_node = l->head;
  if (l-> head == NULL)
  {
    printf("List does not exist\n");
    return -1;
  }
  if(index == 0)
  {
    list_remove_from_front(l);
    return curr_node->value;
  }
  while (count < index && curr_node -> next != NULL){
    count += 1;
    prev = curr_node;
    curr_node = curr_node -> next;
  }
  if (count < index){
      printf("Out of bounds\n");
      return -1;
  }
    prev -> next = curr_node -> next;
    return curr_node -> value;
  }

//check if element is or is not in list 
bool list_is_in(list_t *l, elem value) { 
  node_t* curr_node = l->head;
  if (l -> head == NULL)
  {
    printf("List does not exist");
    return false;
  }
  while (curr_node != NULL){
  if (curr_node -> value == value){
    return true;
  }
    curr_node = curr_node -> next;
  }
  return false;
  }

//returns the element of the given index if it is in the list 
elem list_get_elem_at(list_t *l, int index) { 
  node_t* curr_node = l->head;
  int count = 0;
  if (l -> head == NULL)
  {
    printf("List does not exist");
    return false;
  }
  while (curr_node != NULL){
  if (count == index){
    return curr_node -> value;
  }
    count +=1;
    curr_node = curr_node -> next;
  }
  printf("Not in List");
  return -1;
  }

//gets index of the element if it is in the list
int list_get_index_of(list_t *l, elem value) { 
  node_t* curr_node = l->head;
  int count = 0;
  if (l -> head == NULL)
  {
    printf("List does not exist");
    return -1;
  }
  while (curr_node != NULL){
  if (curr_node -> value == value){
    return count;
  }
    count += 1;
    curr_node = curr_node -> next;
  }
  printf("Not in the List");
  return -1;
  }