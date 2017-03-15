#include "knapsack.h"

#define TRUE 1
#define FALSE 0
#define NIL -1

typedef struct knapsack{
  int capacity;
  int knapsack_value;
  int utilized_capacity;
  int *is_included;
} Knapsack;

Knapsack* create_knapsack(int capacity, int size){
  Knapsack *k = malloc(sizeof(Knapsack));
  k->capacity = capacity;
  k->knapsack_value = 0;
  k->utilized_capacity = 0;
  k->is_included = malloc(sizeof(int)*size);
  empty_knapsack(k, size);
  return k;
}

void empty_knapsack(Knapsack *k, int size){
  int i;
  for(i = 0; i < size; ++i){
    k->is_included[i] = FALSE;
  }
}

int get_capacity(Knapsack *k){
  return k->capacity;
}

int get_knapsack_value(Knapsack *k){
  return k->knapsack_value;
}

int get_utilized_capacity(Knapsack *k){
  return k->utilized_capacity;
}

int is_included(Knapsack *k, int i){
  return k->is_included[i];
}

void add_item(Knapsack *k, Items *it, int i){
  if(!k->is_included[i]){
    k->knapsack_value += get_value(it, i);
    k->utilized_capacity += get_weight(it, i);
    k->is_included[i] = TRUE;
  }
  else{
    printf(">>> Erro: tentando adicionar item ja presente na mochila\n");
  }
}

void remove_item(Knapsack *k, Items *it, int i){
  if(k->is_included[i]){
    k->knapsack_value -= get_value(it, i);
    k->utilized_capacity -= get_weight(it, i);
    k->is_included[i] = FALSE;
  }
  else{
    printf(">>> Erro: tentando remover item nao presente na mochila\n");
  }
}

void print_knapsack(Knapsack *k, Items *it){
  int i, items = 0;

  printf("Itens [indice, peso, valor]:");
  for(i = 0; i < get_size(it); ++i){
    if(k->is_included[i]){
      printf(" [%2d,%2d,%2d]", i, get_weight(it, i), get_value(it, i));
      ++items;
    }
  }
  printf("\nNumero de itens: %d\n", items);
  printf("Peso total: %d\n", k->utilized_capacity);
  printf("Valor total: %d\n", k->knapsack_value);
  printf("Valor por quilo: %.1f\n", ((float)k->knapsack_value / k->utilized_capacity));
}

Knapsack* copy_knapsack(Knapsack *k, int size){
  Knapsack *aux = malloc(sizeof(Knapsack));
  aux->capacity = k->capacity;
  aux->knapsack_value = k->knapsack_value;
  aux->utilized_capacity = k->utilized_capacity;
  aux->is_included = malloc(sizeof(int)*size);

  int i;
  for(i = 0; i < size; ++i){
    aux->is_included[i] = k->is_included[i];
  }
  return aux;
}
