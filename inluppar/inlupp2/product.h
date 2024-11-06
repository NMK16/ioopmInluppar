#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include "product.h"
#include "hashtable.h"
#include "linked_list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros to simplify element creation
#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

typedef struct merch {
    char *name;
    char *description;
    int price;
} merch_t;

typedef struct stock_location {
    char *location;
    int quantity;
} stock_location_t;

// Equality function for elements
bool eq_fn(elem_t a, elem_t b);

// Merchandise management functions
merch_t *create_merch(char *name, char *description, int price);
void add_merch(ioopm_hash_table_t *merch_table);
void list_merch(ioopm_hash_table_t *merch_table);
void remove_merch(ioopm_hash_table_t *merch_table);
bool edit_merch(ioopm_hash_table_t *merch_table, char *old_name, char *new_name, char *new_description, int new_price);

// Stock management functions
void show_stock(ioopm_hash_table_t *stock_table, char *name);
bool replenish_stock(ioopm_hash_table_t *merch_table, ioopm_hash_table_t *stock_table, char *name, char *location, int quantity);

// Cart management function

void create_cart(ioopm_hash_table_t *cart_table, int cart_id);
void remove_cart(ioopm_hash_table_t *cart_table, int cart_id);
void add_to_cart(ioopm_hash_table_t *cart_table, int cart_id, char *name, int quantity);
void remove_from_cart(ioopm_hash_table_t *cart_table, int cart_id, char *name);
int calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, int cart_id);
void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *stock_table, int cart_id);



#endif // INVENTORY_SYSTEM_H


