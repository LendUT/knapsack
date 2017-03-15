#include "beam_search.h"

int bs_find_max_value(Items *it, int capacity, int k){
  List *aux, *set;

  List *beam = randomize_states(it, capacity, k);

  while(beam != NULL){
    set = NULL;

    for(aux = beam; aux != NULL; aux = aux->next){
       generate_successors(aux->info, it, &set);
    }
    queue_print(set, it);
    beam = NULL;

    /*
      ESCOLHA DOS K MELHORES E CONDICAO DE PARADA
    */
    break;
  }

  return 0;
}

List* randomize_states(Items *it, int capacity, int k){
  int i, j, item, size = get_size(it);
  Knapsack *aux;
  List *beam = queue_create();

  for(i = 0; i < k; ++i){
    aux = create_knapsack(capacity, size);
    beam = queue_insert(beam, aux);
    for(j = 0; j < size; j++){
      item = rand() % size;
      if((get_utilized_capacity(aux) + get_weight(it, item)) < capacity){
        add_item(aux, it, item);
      }
    }
    printf(">>teste randomize_states()");
    printf("\n %d", i);
    print_knapsack(beam->info, it);
  }

  return beam;
}

void generate_successors(Knapsack *state, Items *it, List **set){
  int item, size = get_size(it), capacity = get_capacity(state);

  for(item = 0; item < size; ++item){
    Knapsack *aux = copy_knapsack(state, size);
    Knapsack *aux2 = copy_knapsack(state, size);

    if(get_utilized_capacity(aux) + get_weight(it, item) <= capacity){
      add_item(aux, it, item);
      *set = queue_insert(*set, aux);
    }
    if(is_included(aux2, item)){
      remove_item(aux2, it, item);
      *set = queue_insert(*set, aux2);
    }

    aux = NULL;
    aux2 = NULL;
  }
}

float heuristic_cost(Knapsack *state){
  return get_knapsack_value(state)/get_utilized_capacity(state);
}
