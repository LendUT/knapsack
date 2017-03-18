#include "beam_search.h"

Knapsack* bs_find_max_value(Items *it, int capacity, int k){
  int i, j, size = get_size(it);

  Knapsack **set = malloc(sizeof(Knapsack*) * k * size);
  Knapsack **beam = randomize_states(it, capacity, k);
  Knapsack *best_knapsack = beam[0];

  while(beam[0] != NULL){
    j = 0;

    for(i = 0; i < k; ++i){
       generate_successors(beam[i], it, set, &j);
    }

    if(j < k){
      printf(">>> ERRO: set vazio!\n");
      exit(1);
    }

    sort(set, j-1);
    for(i = 0; i < k; ++i){
      beam[i] = set[i];
    }

    if(is_better_than(beam[0], best_knapsack)){
      best_knapsack = beam[0];
    }
    else{
      break;
    }
  }

  return best_knapsack;
}

void generate_successors(Knapsack *state, Items *it, Knapsack **set, int *j){
  int item, size = get_size(it), capacity = get_capacity(state);

  for(item = 0; item < size; ++item){
    if(is_included(state, item)){
      Knapsack *aux = copy_knapsack(state, size);
      remove_item(aux, it, item);
      set[(*j)++] = aux;
    }
    else if(get_utilized_capacity(state) + get_weight(it, item) <= capacity){
      Knapsack *aux = copy_knapsack(state, size);
      add_item(aux, it, item);
      set[(*j)++] = aux;
    }
  }
}

float heuristic_cost(Knapsack *state){
  return ((float)get_knapsack_value(state));
}
