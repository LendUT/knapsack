/**
 * @author: Guilherme Alves - Leonardo de Assis da Silva
 * @date: 2017-03-10
 *
 * 0/1 knapsack problem - beam search - genetic algorithm
 *
 **/

#include <stdlib.h>
#include <stdio.h>
#include "libraries/beam_search.h"
#include "libraries/genetic_algorithm.h"
#include "libraries/items.h"

#define SIZE 28
#define CAPACITY 28
#define K 320
#define POPULATION_SIZE 1000
int SOURCE_VALUES[SIZE] = {1, 3, 1, 8, 9, 3, 2, 8, 5, 1, 1, 6, 3, 2,
                           5, 2, 3, 8, 9, 3, 2, 4, 5, 4, 3, 1, 3, 2};
int SOURCE_WEIGHTS[SIZE] = {3, 8, 12, 2, 8, 4, 4, 5, 1, 1, 8, 6, 4, 3,
                           3, 5, 7, 3, 5, 7, 4, 3, 7, 2, 3, 5, 4, 3};

void find_max_value(Items *it, int capacity, int k, int population_size);

int main(){
  Items *it = create_items(SIZE);
  set_weight(it, SOURCE_WEIGHTS);
  set_value(it, SOURCE_VALUES);

  print_all_items(it);
  find_max_value(it, CAPACITY, K, POPULATION_SIZE);

  return 0;
}

void find_max_value(Items *it, int capacity, int k, int population_size){
  Knapsack *beam = bs_find_max_value(it, capacity, k);
  Knapsack *ga = ga_find_max_value(it, capacity, population_size);

  printf("MOCHILA FINAL (feixe)\n");
  print_knapsack(beam, it);
  printf("\nMOCHILA FINAL (genetico)\n");
  print_knapsack(ga, it);
}
