#ifndef 	__QUEUE__
#define   __QUEUE__

#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

typedef struct node List;

List* queue_create(void);
List* queue_insert(List* l, Knapsack *k);
void queue_free(List *l);

#endif
