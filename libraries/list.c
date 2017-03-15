#include "list.h"

typedef struct node{
    Knapsack *info;
    struct node* next;
    struct node* prev;
} List;

List* queue_create(void){
  return NULL;
}

List* queue_insert(List* l, Knapsack *k){
  List* new =(List*)malloc(sizeof(List));
  new->info = k;
  new->next = l;
  new->prev = NULL;
  /* verifica se lista n~ao esta vazia */
  if (l != NULL)
      l->prev = new;
  return new;
}

void queue_free(List *l){
  while (l != NULL){
        List *aux = l->next;
        free (l);
        l = aux;
  }
}
