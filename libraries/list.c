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
    printf(">>>>>>>>>>>>>oi<<<<<<<<<<<<<<<<<<<<<\n");
  }
}

void queue_free(List *l){
  while (l != NULL){
        List *aux = l->next;
        free (l);
        l = aux;
  }
}

// Knapsack* get_min_value(List *l){
//   List *aux;
//   Knapsack *k = l->info;
//
//   for(aux = l; aux != NULL; aux = aux->next){
//     if(){
//
//     }
//   }
//
//   return
// }
