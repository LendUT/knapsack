#ifndef 	__BEAMSEARCH__
#define   __BEAMSEARCH__

#include "items.h"
#include "knapsack.h"

Knapsack* bs_find_max_value(Items *it, int capacity, int k);

void generate_successors(Knapsack *state, Items *it, Knapsack **set, int *j);
float heuristic_cost(Knapsack *state);

#endif
