#include "genetic_algorithm.h"

#define MAX_GENERATION 500
#define MUTATION_PROBABILITY 05

Knapsack* ga_find_max_value(Items *it, int capacity, int population_size){
  int generation, i;
  Knapsack *x, *y, *child, *best_knapsack = create_knapsack(capacity, get_size(it));
  Knapsack **new_population = malloc(sizeof(Knapsack*) * population_size);

  Knapsack **population = randomize_population(it, capacity, population_size);
  sort(population, population_size);

  for(generation = 0; generation < MAX_GENERATION; ++generation){
    for(i = 0; i < population_size; ++i){
      x = choose_random_parent(population, population_size);
      y = choose_random_parent(population, population_size);
      child = reproduct(x, y, it);

      if((rand() % 101) < MUTATION_PROBABILITY){
        child = mutate(child, it);
      }
      new_population[i] = child;
      child = NULL;
    }

    sort(new_population, population_size);
    population = select_next_generation(population, new_population, population_size);

    if(get_knapsack_value(population[0]) > get_knapsack_value(best_knapsack)){
      best_knapsack = population[0];
    }

  }

  return best_knapsack;
}

Knapsack** randomize_population(Items *it, int capacity, int k){
  int i, j, item, size = get_size(it);
  Knapsack **population = malloc(sizeof(Knapsack*) * k);

  for(i = 0; i < k; ++i){
    population[i] = create_knapsack(capacity, size);
    for(j = 0; j < size; j++){
      item = rand() % size;
      if(!is_included(population[i], item) && (get_utilized_capacity(population[i]) + get_weight(it, item)) < capacity){
        add_item(population[i], it, item);
      }
    }
  }

  return population;
}

Knapsack* choose_random_parent(Knapsack **population, int size){
  return population[rand() % size];
}

Knapsack* reproduct(Knapsack *x, Knapsack *y, Items *it){
  int i, size = get_size(it), p = rand() % (size - 1);
  Knapsack *child = create_knapsack(get_capacity(x), size);

  for(i = 0; i < p; ++i){
    if(is_included(x, i)){
      add_item(child, it, i);
    }
  }
  for(i = p; i < size; ++i){
    if(is_included(y, i) && (get_utilized_capacity(child) + get_weight(it, i)) <= get_capacity(child)){
      add_item(child, it, i);
    }
  }

  return child;
}

Knapsack* mutate(Knapsack *child, Items *it){
  int i, size = get_size(it);

  for(i = 0; i < size; ++i){
    if((rand() % 101) < MUTATION_PROBABILITY){
      if(is_included(child, i)){
        remove_item(child, it, i);
      }
      else if(!is_included(child, i) && (get_utilized_capacity(child) + get_weight(it, i)) <= get_capacity(child)){
        add_item(child, it, i);
      }
    }
  }

  return child;
}

Knapsack** select_next_generation(Knapsack **a, Knapsack **b, int size){
  Knapsack **aux = malloc(sizeof(Knapsack*) * size);
  int i, j = 0, k = 0;

  for(i = 0; i < size; ++i){
    if(fitness_level(a[j]) > fitness_level(b[k])){
      aux[i] = a[j++];
    }
    else{
      aux[i] = b[k++];
    }
  }
  return aux;
}

void sort(Knapsack **k, int size){
  int i = size / 2, parent, child;
  Knapsack *aux;

  for(;;){
    if(i > 0){
      --i;
      aux = k[i];
    }
    else{
      --size;
      if(size == 0){
        return;
      }
      aux = k[size];
      k[size] = k[0];
    }
    parent = i;
    child = i * 2 + 1;
    while(child < size){
      if(child + 1 < size  &&  fitness_level(k[child + 1]) < fitness_level(k[child])){
        ++child;
      }
      if(fitness_level(k[child]) < fitness_level(aux)){
        k[parent] = k[child];
        parent = child;
        child = parent * 2 + 1;
      }
      else{
        break;
      }
    }
    k[parent] = aux;
  }
}

float fitness_level(Knapsack *state){
  // return ((float)get_knapsack_value(state))/get_utilized_capacity(state);
  return ((float)get_knapsack_value(state));
}
