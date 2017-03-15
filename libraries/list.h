#ifndef 	__QUEUE__
#define   __QUEUE__

#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"
#include "items.h"

typedef struct node{
    Knapsack *info;
    struct node* next;
    struct node* prev;
} List;

List* queue_create(void);
List* queue_insert(List* l, Knapsack *k);
void queue_print(List* l, Items *it);
void queue_free(List *l);

#endif
