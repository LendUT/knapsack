#ifndef 	__GENETICALGORITHM__
#define   __GENETICALGORITHM__

#include "items.h"
#include "knapsack.h"

Knapsack* ga_find_max_value(Items *it, int capacity, int population_size);
Knapsack** randomize_population(Items *it, int capacity, int k);
Knapsack* choose_random_parent(Knapsack **population, int size);
Knapsack* reproduct(Knapsack *x, Knapsack *y, Items *it);
Knapsack* mutate(Knapsack *child, Items *it);
Knapsack** select_next_generation(Knapsack **a, Knapsack **b, int size);
void sort(Knapsack **k, int size);
float fitness_level(Knapsack *state);

#endif
