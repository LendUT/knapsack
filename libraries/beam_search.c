#include "beam_search.h"

void bs_find_max_value(Items *it, int capacity, int k){
  int i;
  List *aux, *set;

  List *beam = randomize_states(it, capacity, k);
  Knapsack *best_knapsack = beam->info;

  while(beam != NULL){
    set = NULL;

    for(aux = beam; aux != NULL; aux = aux->next){
       generate_successors(aux->info, it, &set);
    }
    beam = NULL;

    for(i = 0; i < k; ++i){
      beam = queue_insert(beam, queue_get_max(set));
      if(set == NULL){
        printf(">>> ERRO: beam vazio!\n");
        exit(1);
      }
    }

    if(get_knapsack_value(beam->info) > get_knapsack_value(best_knapsack)){
      best_knapsack = beam->info;
    }
    else{

      break;
    }
  }

  printf("MOCHILA FINAL (feixe)");
  print_knapsack(best_knapsack, it);
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
  }

  return beam;
}

void generate_successors(Knapsack *state, Items *it, List **set){
  int item, size = get_size(it), capacity = get_capacity(state);

  for(item = 0; item < size; ++item){
    Knapsack *aux = copy_knapsack(state, size);
    Knapsack *aux2 = copy_knapsack(state, size);

    if(!is_included(aux, item) && get_utilized_capacity(aux) + get_weight(it, item) <= capacity){
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
