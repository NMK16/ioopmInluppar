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
void add_merch(ioopm_hash_table_t *merch_table, char *merch_name, char *desc, int price);
void list_merch(ioopm_hash_table_t *merch_table, char* listMore);
void remove_merch(ioopm_hash_table_t *merch_table, char *merch_name, char *confirmation);
void edit_merch(ioopm_hash_table_t *merch_table, char *oldname, char *new_name, char *new_desc, int new_price);
void destroy_merch(merch_t *merch);
// Stock management functions
void show_stock(ioopm_hash_table_t *merch_table, char *name);
void replenish_stock(ioopm_hash_table_t *merch_table, char *name, char *location, int quantity);

// Cart management function

void create_cart(ioopm_hash_table_t *cart_table, char *cart_id);
void remove_cart(ioopm_hash_table_t *cart_table, char *cart_id, char *confirmation);
void add_to_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id, char *merch_name, int quantity);
void remove_from_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id, char *merch_name, int quantity);
void calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id);
void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id);



#endif // INVENTORY_SYSTEM_H
