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
    ioopm_list_t *locStocks;
    int amountInStock;
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
void edit_merch(ioopm_hash_table_t *merch_table);

// Stock management functions
void show_stock(ioopm_hash_table_t *merch_table);
void replenish_stock(ioopm_hash_table_t *merch_table);

// Cart management function

void create_cart(ioopm_hash_table_t *cart_table);
void remove_cart(ioopm_hash_table_t *cart_table);
void add_to_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table);
void remove_from_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table);
void calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table);
void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table);



#endif // INVENTORY_SYSTEM_H
