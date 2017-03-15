#include "beam_search.h"

int bs_find_max_value(Items *it, int capacity, int k){
  int i;

  List *beam = queue_create();
  List *set = queue_create();

  randomize_states(beam, it, capacity, k);


  return 0;
}


void randomize_states(List *states, Items *it, int capacity, int k){
  int i, j, item, size = get_size(it);
  Knapsack *aux;

  for(i = 0; i < k; ++i){
    aux = create_knapsack(capacity, size);
    states = queue_insert(states, aux);
    for(j = 0; j < size; j++){
      item = rand() % size;
      if((get_utilized_capacity(aux) + get_weight(it, item)) < capacity){
        add_item(aux, it, item);
      }
    }
    printf(">>teste");
    printf("\n %d", i);
    print_knapsack(aux, it);
  }
}

void generate_successors(Knapsack **states, Items *it, int i){
  int item, capacity = get_capacity(states[i]);
  for(item = 0; item < get_size(it); ++item){
    if(get_utilized_capacity(states[i]) + get_weight(it, item) <= capacity){
      add_item(states[i], it, item);
    }
    if(is_included(states[i], item)){
      remove_item(states[i], it, item);
    }
  }
}

float heuristic_cost(Knapsack *state){
  return get_knapsack_value(state)/get_utilized_capacity(state);
}
