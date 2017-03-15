#ifndef 	__BEAMSEARCH__
#define   __BEAMSEARCH__

#include "items.h"
#include "knapsack.h"
#include "list.h"

#define CAPACITY 15

int bs_find_max_value(Items *it, int capacity, int k);
List* randomize_states(Items *it, int capacity, int k);
void generate_successors(Knapsack *state, Items *it, List** set);
float heuristic_cost(Knapsack *state);

#endif
