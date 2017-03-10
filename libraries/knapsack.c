#include "knapsack.h"
#include "beam_search.h"
#include "genetic_algorithm.h"

Knapsack* create_knapsack(int size){
  Knapsack *k = malloc(sizeof(Knapsack));
  k->size = size;
  k->capacity = 0;
  k->weight = malloc(sizeof(int)*size);
  k->value = malloc(sizeof(int)*size);
  k->is_included = malloc(sizeof(int)*size);
  empty_knapsack(k);
  return k;
}

void empty_knapsack(Knapsack *k){
  int i;

  for(i = 0; i < k->size; ++i){
    k->is_included[i] = 0;
  }
}

void set_capacity(Knapsack *k, int capacity){
  k->capacity = capacity;
}

void set_weight(Knapsack *k, const int *weight){
    memcpy(k->weight, weight, sizeof(k->weight));
}

void set_value(Knapsack *k, const int *value){
  memcpy(k->value, value, sizeof(k->value));
}

void print_knapsack(Knapsack *k){
  int i, total_value = 0;

  printf("\nITENS NA MOCHILA\n");
  printf("Itens [peso, valor]:");
  for(i = 0; i < k->size; ++i){
    if(k->is_included[i]){
      printf(" [ %2d, %2d]", k->weight[i], k->value[i]);
      total_value += k->value[i];
    }
  }
  printf("\nValor total: %d\n", total_value);
}

void print_all_items(Knapsack *k){
  int i;

  printf("\nTODOS OS ITENS\n");
  printf("Numero de itens: %d\n", k->size);
  printf("Itens [peso, valor]:");
  for(i = 0; i < k->size; ++i){
    printf(" [ %2d, %2d]", k->weight[i], k->value[i]);
  }
  printf("\n");
}

void find_max_value(Knapsack *k){
  printf("\nVALOR MAXIMO\n");
  printf("Busca por feixe local: %d\n", bs_find_max_value(k));
  printf("Busca por algoritmo genetico: %d\n", ga_find_max_value(k));
}
