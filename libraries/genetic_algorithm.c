#include "genetic_algorithm.h"

#define MAX_GENERATION 17000
#define MUTATION_PROBABILITY 005

Knapsack* ga_find_max_value(Items *it, int capacity, int population_size){
  int generation, i, j, p, x, y;
  float *probability;
  Knapsack *child, *best_knapsack, **new_population, **population;

  new_population = malloc(sizeof(Knapsack*) * population_size);
  population = randomize_states(it, capacity, population_size);
  sort(population, population_size);
  best_knapsack = population[0];

  for(generation = 0; generation < MAX_GENERATION; ++generation){
    probability = calculate_probabilities(population, population_size);

    for(i = 0; i < population_size; ++i){
        roulette_wheel_select(&x, &y, probability, population_size);
        child = crossover(population[x], population[y], it);

        if((rand() % 101) <= MUTATION_PROBABILITY){
          child = mutate(child, it);
        }
        new_population[i] = child;
    }

    sort(new_population, population_size);
    population = select_next_generation(population, new_population, population_size);

    if(is_better_than(population[0], best_knapsack)){
      best_knapsack = population[0];
    }
  }

  return best_knapsack;
}

int calculate_total_fitness(Knapsack **population, int population_size){
  int i, total_fitness = 0;
  for(i = 0; i < population_size; ++i){
    total_fitness += (int)fitness_level(population[i]);
  }
  return total_fitness;
}

float* calculate_probabilities(Knapsack **population, int population_size){
  float probability_sum = 0, *probability = malloc(sizeof(float)*population_size);
  int i, p, total_fitness = calculate_total_fitness(population, population_size);

  for(i = 0; i < population_size; ++i){
    probability[i] = 100 * (fitness_level(population[i]) / total_fitness);
    probability[i] += probability_sum;
    probability_sum += probability[i];
  }

  return probability;
}

void roulette_wheel_select(int *x, int *y, float *probability, int population_size){
  int j, p;

  p = rand() % 101;
  for(j = 0; j < population_size; ++j){
    if(p > probability[j] && (j == population_size-1 || p <= probability[j+1])){
      *x = j;
      break;
    }
  }

  p = rand() % 101;
  for(j = 0; j < population_size; ++j){
    if(p > probability[j] && (j == population_size-1 || p <= probability[j+1])){
      *y = j;
      break;
    }
  }
}

Knapsack* crossover(Knapsack *x, Knapsack *y, Items *it){
  int item, i, p, size = get_size(it);
  Knapsack *child = create_knapsack(get_capacity(x), size);

  for(item = 0; item < size; ++item){
    i = rand() % size;
    p = rand() % 100;

    if(p < 50){
      if(is_included(x, i) && !is_included(child, i) && (get_utilized_capacity(child) + get_weight(it, i)) <= get_capacity(child)){
        add_item(child, it, i);
      }
    }
    else{
      if(is_included(y, i) && !is_included(child, i) && (get_utilized_capacity(child) + get_weight(it, i)) <= get_capacity(child)){
        add_item(child, it, i);
      }
    }
  }

  return child;
}

Knapsack* mutate(Knapsack *child, Items *it){
  int i, position, size = get_size(it);

  for(i = 0; i < size; ++i){
    position = rand() % size;
    if((rand() % 101) < MUTATION_PROBABILITY){
      if(is_included(child, position)){
        remove_item(child, it, position);
      }
      else if((get_utilized_capacity(child) + get_weight(it, position)) <= get_capacity(child)){
        add_item(child, it, position);
      }
    }
  }

  return child;
}

Knapsack** select_next_generation(Knapsack **population, Knapsack **new_population, int size){
  Knapsack **aux = malloc(sizeof(Knapsack*) * size);
  int i, j = 0, k = 0;

  for(i = 0; i < size; ++i){
    if(fitness_level(population[j]) > fitness_level(new_population[k])){
      aux[i] = population[j++];
    }
    else{
      aux[i] = new_population[k++];
    }
  }
  return aux;
}

float fitness_level(Knapsack *state){
  return ((float)get_knapsack_value(state));
}
