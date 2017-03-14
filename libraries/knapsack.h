#ifndef 	__KNAPSACK__
#define   __KNAPSACK__

#include <stdlib.h>
#include <stdio.h>
#include "items.h"

typedef struct knapsack Knapsack;

Knapsack* create_knapsack(int capacity, int size);
void empty_knapsack(Knapsack *k, int size);
int get_capacity(Knapsack *k);
int get_knapsack_value(Knapsack *k);
int get_utilized_capacity(Knapsack *k);
int get_weight(Items *it, int i);
int is_included(Knapsack *k, int i);
void add_item(Knapsack *k, Items *it, int i);
void remove_item(Knapsack *k, Items *it, int i);
void print_knapsack(Knapsack *k, Items *it);

#endif
