#ifndef 	__KNAPSACK__
#define   __KNAPSACK__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct knapsack Knapsack;

Knapsack* create_knapsack(int size);
void empty_knapsack(Knapsack *k);
void set_capacity(Knapsack *k, int capacity);
void set_value(Knapsack *k, int *value);
void set_weight(Knapsack *k, int *weight);
int get_capacity(Knapsack *k);
int get_size(Knapsack *k);
int get_total_value(Knapsack *k);
int get_utilized_capacity(Knapsack *k);
int get_value(Knapsack *k, int i);
int get_weight(Knapsack *k, int i);
int is_included(Knapsack *k, int i);
void add_item(Knapsack *k, int i);
void remove_item(Knapsack *k, int i);
void print_knapsack(Knapsack *k);
void print_all_items(Knapsack *k);
void find_max_value(Knapsack *k);

#endif
