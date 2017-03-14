#include "knapsack.h"
#include "beam_search.h"
#include "genetic_algorithm.h"

#define TRUE 1
#define FALSE 0
#define NIL -1

typedef struct knapsack{
  int capacity;
  int size;
  int utilized_capacity;
  int *is_included;
  int *value;
  int *weight;
} Knapsack;

Knapsack* create_knapsack(int size){
  Knapsack *k = malloc(sizeof(Knapsack));
  k->capacity = NIL;
  k->size = size;
  k->utilized_capacity = 0;
  k->is_included = malloc(sizeof(int)*size);
  k->value = malloc(sizeof(int)*size);
  k->weight = malloc(sizeof(int)*size);
  empty_knapsack(k);
  return k;
}

void empty_knapsack(Knapsack *k){
  int i;
  for(i = 0; i < k->size; ++i){
    k->is_included[i] = FALSE;
  }
}

void set_capacity(Knapsack *k, int capacity){
  k->capacity = capacity;
}

void set_value(Knapsack *k, int *value){
  memcpy(k->value, value, sizeof(int)*k->size);
}

void set_weight(Knapsack *k, int *weight){
  memcpy(k->weight, weight, sizeof(int)*k->size);
}

int get_capacity(Knapsack *k){
  return k->capacity;
}

int get_size(Knapsack *k){
  return k->size;
}

int get_total_value(Knapsack *k){
  int i, total = 0;
  for(i = 0; i < k->size; ++i){
    if(k->is_included[i]){
      total += k->value[i];
    }
  }
  return total;
}

int get_utilized_capacity(Knapsack *k){
  return k->utilized_capacity;
}

int get_value(Knapsack *k, int i){
  return k->value[i];
}

int get_weight(Knapsack *k, int i){
  return k->weight[i];
}

int is_included(Knapsack *k, int i){
  return k->is_included[i];
}

void add_item(Knapsack *k, int i){
  if(!k->is_included[i]){
    k->utilized_capacity += k->weight[i];
    k->is_included[i] = TRUE;
  }
  else{
    printf(">>> Erro: tentando adicionar item ja presente na mochila\n");
  }
}

void remove_item(Knapsack *k, int i){
  if(k->is_included[i]){
    k->utilized_capacity -= k->weight[i];
    k->is_included[i] = FALSE;
  }
  else{
    printf(">>> Erro: tentando remover item nao presente na mochila\n");
  }
}

void print_knapsack(Knapsack *k){
  int i, items = 0, total_value = 0;

  printf("\nITENS NA MOCHILA\n");
  printf("Itens [peso, valor]:");
  for(i = 0; i < k->size; ++i){
    if(k->is_included[i]){
      printf(" [%2d, %2d]", k->weight[i], k->value[i]);
      total_value += k->value[i];
      ++items;
    }
  }
  printf("\nNumero de itens: %d\n", items);
  printf("Peso total: %d\n", k->utilized_capacity);
  printf("Valor total: %d\n", total_value);
}

void print_all_items(Knapsack *k){
  int i, total_value = 0, total_weight = 0;

  printf("\nTODOS OS ITENS\n");
  printf("Itens [peso, valor]:");
  for(i = 0; i < k->size; ++i){
    printf(" [%2d, %2d]", k->weight[i], k->value[i]);
    total_value += k->value[i];
    total_weight += k->weight[i];
  }
  printf("\nNumero de itens: %d\n", k->size);
  printf("Peso total: %d\n", total_weight);
  printf("Valor total: %d\n", total_value);
  printf("\n");
}

void find_max_value(Knapsack *k){
  printf("\nVALOR MAXIMO\n");
  printf("Busca por feixe local: %d\n", bs_find_max_value(k));
  printf("Busca por algoritmo genetico: %d\n", ga_find_max_value(k));
}
