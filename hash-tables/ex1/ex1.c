#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  if(length < 2){ // return null if less than 2 weights given
    return NULL;
  }

  // store each weight as a key into a hash table
  for(int i = 0; i < length; i++){
    hash_table_insert(ht, weights[i], 0);
  }

  // edit each value to be the item's index
  for(int i = 0; i < length; i++){
    if(ht->storage[i] != NULL){
      if(ht->storage[i]->next == NULL){
        ht->storage[i]->value = i;
      } else {
        LinkedPair *current_node = ht->storage[i];
        while(current_node->next != NULL){
          current_node->value = i;
          current_node = current_node->next;
        }
      }
    } 
  }

  // look for limit-weight in the storage
  for(int i = 0; i < length; i++){
    if(ht->storage[i] != NULL){
      int search_for = limit - ht->storage[i]->key;
      if(search_for < limit && ht->storage[search_for] != NULL){
        printf("search for: %i\n", ht->storage[search_for]->key);
        if(ht->storage[i]->key + ht->storage[search_for]->key == limit){
          printf("VALUES FOUND!");
        }
      }
      // printf("search for: %i\n", search_for);
    }
    
    // if(ht->storage[search_for] != NULL){
    //   printf("found value: %i", ht->storage[search_for]->value);
    // }

    // if(ht->storage[i] != NULL){

    //   printf("%i\n", ht->storage[i]->value);
    // }
  }


  printf("%i\n", limit);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
