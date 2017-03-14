#include "items.h"

typedef struct items{
  int size;
  int *value;
  int *weight;
} Items;

Items* create_items(int size){
  Items *it = malloc(sizeof(Items));
  it->size = size;
  it->value = malloc(sizeof(int)*size);
  it->weight = malloc(sizeof(int)*size);
  return it;
}
void set_value(Items *it, int *value){
  memcpy(it->value, value, sizeof(int)*it->size);
}

void set_weight(Items *it, int *weight){
  memcpy(it->weight, weight, sizeof(int)*it->size);
}

int get_size(Items *it){
  return it->size;
}

int get_value(Items *it, int i){
  return it->value[i];
}

int get_weight(Items *it, int i){
  return it->weight[i];
}
void print_all_items(Items *it){
  int i, total_value = 0, total_weight = 0;

  printf("\nTODOS OS ITENS\n");
  printf("Itens [peso, valor]:");
  for(i = 0; i < it->size; ++i){
    printf(" [%2d, %2d]", it->weight[i], it->value[i]);
    total_value += it->value[i];
    total_weight += it->weight[i];
  }
  printf("\nNumero de itens: %d\n", it->size);
  printf("Peso total: %d\n", total_weight);
  printf("Valor total: %d\n", total_value);
  printf("\n");
}
