#ifndef 	__ITEMS__
#define   __ITEMS__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct items Items;

Items* create_items(int size);
void set_value(Items *it, int *value);
void set_weight(Items *it, int *weight);
int get_size(Items *it);
int get_value(Items *it, int i);
void print_all_items(Items *it);

#endif
