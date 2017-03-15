#include "list.h"

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

void queue_print(List* l, Items *it){
  List *aux;

  for(aux = l; aux != NULL; aux = aux->next){
    print_knapsack(aux->info, it);
  }
}

void queue_free(List *l){
  while (l != NULL){
        List *aux = l->next;
        free (l);
        l = aux;
  }
}

Knapsack* queue_get_max(List *l){
  List *aux, *max = l;

  for(aux = l; aux != NULL; aux = aux->next){
    // if(get_knapsack_value(aux->info) > get_knapsack_value(max->info)){
    if(heuristic_cost(aux->info) > heuristic_cost(max->info)){
      max = aux;
    }
  }

  if(max->prev != NULL){
    max->prev->next = max->next;
  }
  if(max->next != NULL){
    max->next->prev = max->prev;
  }

  return max->info;
}
