/**
 * @author: Guilherme Alves - Leonardo de Assis da Silva
 * @date: 2017-03-10
 *
 * 0/1 knapsack problem - beam search - genetic algorithm
 *
 **/

#include <stdlib.h>
#include <stdio.h>
#include "libraries/knapsack.h"

#define SIZE 28

int main(){
  const int SOURCE_WEIGHT[SIZE] = {1, 3, 1, 8, 9, 3, 2, 8, 5, 1, 1, 6, 3, 2,
                                   5, 2, 3, 8, 9, 3, 2, 4, 5, 4, 3, 1, 3, 2};
  const int SOURCE_VALUES[SIZE] = {3, 8, 12, 2, 8, 4, 4, 5, 1, 1, 8, 6, 4, 3,
                                   3, 5, 7, 3, 5, 7, 4, 3, 7, 2, 3, 5, 4, 3};

  Knapsack *k = create_knapsack(SIZE);
  set_capacity(k, 15);
  set_weight(k, SOURCE_WEIGHT);
  set_value(k, SOURCE_VALUES);

  print_all_items(k);
  print_knapsack(k);
  find_max_value(k);

  return 0;
}
