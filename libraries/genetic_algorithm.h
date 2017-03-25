#ifndef 	__GENETICALGORITHM__
#define   __GENETICALGORITHM__

#include "items.h"
#include "knapsack.h"

Knapsack* ga_find_max_value(Items *it, int capacity, int population_size);
int calculate_total_fitness(Knapsack **population, int population_size);
float* calculate_probabilities(Knapsack **population, int population_size);
void roulette_wheel_select(int *x, int *y, float *probability, int population_size);
Knapsack* crossover(Knapsack *x, Knapsack *y, Items *it);
Knapsack* mutate(Knapsack *child, Items *it);
Knapsack** select_next_generation(Knapsack **population, Knapsack **new_population, int size);
float fitness_level(Knapsack *state);

#endif
