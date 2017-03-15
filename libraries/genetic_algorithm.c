#include "genetic_algorithm.h"

Knapsack* ga_find_max_value(Items *it, int capacity){
  Knapsack *best_knapsack = create_knapsack(capacity, get_size(it));

  return best_knapsack;
}
