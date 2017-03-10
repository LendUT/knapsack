#ifndef 	__KNAPSACK__
#define   __KNAPSACK__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct knapsack{
  int size;
  int capacity;
  int *weight;
  int *value;
  int *is_included;
} Knapsack;

Knapsack* create_knapsack(int size);
void empty_knapsack(Knapsack *k);
void set_capacity(Knapsack *k, int capacity);
void set_weight(Knapsack *k, const int *weight);
void set_value(Knapsack *k, const int *value);
void print_knapsack(Knapsack *k);
void print_all_items(Knapsack *k);
void find_max_value(Knapsack *k);

#endif
