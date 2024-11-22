#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include "hashtable.h"
#include "linked_list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros to simplify element creation
#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

int hash_fn(elem_t key);

typedef struct merch {
    char *name;              ///< Name of the merchandise
    char *description;       ///< Description of the merchandise
    int price;               ///< Price of the merchandise
    ioopm_list_t *locStocks; ///< List of stock locations for the merchandise
    int amountInStock;       ///< Total amount in stock across all locations
} merch_t;

typedef struct stock_location {
    char *location; ///< Location identifier
    int quantity;   ///< Quantity of merchandise at this location
} stock_location_t;

/**
 * Equality function for elements.
 * 
 * @param a The first element to compare.
 * @param b The second element to compare.
 * @return `true` if elements are equal, `false` otherwise.
 */
bool eq_fn(elem_t a, elem_t b);

// Merchandise management functions

/**
 * Creates a new merchandise item.
 * 
 * @param name The name of the merchandise.
 * @param description The description of the merchandise.
 * @param price The price of the merchandise.
 * @return A pointer to the created `merch_t` object.
 */
merch_t *create_merch(char *name, char *description, int price);

/**
 * Adds merchandise to the inventory.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param price The price of the new merchandise item.
 * @param description Description of the new merchandise item.
 * @param name Name of the new merchandise item.
 */
void add_merch(ioopm_hash_table_t *merch_table, int price, char *description, char *name);

/**
 * Lists all merchandise items in the inventory.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param additional_info Additional information for listing (if any).
 */
void list_merch(ioopm_hash_table_t *merch_table, char* additional_info);

/**
 * Removes a merchandise item from the inventory.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param confirmation Confirmation to proceed with removal.
 * @param name Name of the merchandise item to be removed.
 */
void remove_merch(ioopm_hash_table_t *merch_table, char *confirmation, char *name);

/**
 * Edits details of an existing merchandise item.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param new_price New price for the merchandise item.
 * @param new_description New description for the merchandise item.
 * @param new_name New name for the merchandise item.
 * @param old_name Current name of the merchandise item.
 */
void edit_merch(ioopm_hash_table_t *merch_table, ioopm_hash_table_t *cart_table, int new_price, char *new_description, char *new_name, char *old_name);

/**
 * Destroys a merchandise item, freeing its memory.
 * 
 * @param merch Pointer to the `merch_t` object to destroy.
 */
void destroy_merch(merch_t *merch);

// Stock management functions

/**
 * Shows the stock of a specified merchandise item.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param name Name of the merchandise item to display stock for.
 */
void show_stock(ioopm_hash_table_t *merch_table, char *name);

/**
 * Replenishes stock for a merchandise item at a specified location.
 * 
 * @param merch_table Hash table containing all merchandise.
 * @param quantity Quantity to add to the stock.
 * @param location Location to add the stock to.
 * @param name Name of the merchandise item.
 */
void replenish_stock(ioopm_hash_table_t *merch_table, int quantity, char *location, char *name);

// Cart management functions

/**
 * Creates a new shopping cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param cart_id Identifier for the new cart.
 */
void create_cart(ioopm_hash_table_t *cart_table, char *cart_id);

/**
 * Removes a shopping cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param cart_id Identifier for the cart to be removed.
 * @param confirmation Confirmation to proceed with removal.
 */
void remove_cart(ioopm_hash_table_t *cart_table, char *cart_id, char *confirmation);

/**
 * Adds a merchandise item to a cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param merch_table Hash table containing all merchandise.
 * @param quantity Quantity of the item to add.
 * @param merch_name Name of the merchandise item to add.
 * @param cart_id Identifier for the cart to add the item to.
 */
void add_to_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, int quantity, char *merch_name, char *cart_id);

/**
 * Removes a merchandise item from a cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param merch_table Hash table containing all merchandise.
 * @param quantity Quantity of the item to remove.
 * @param merch_name Name of the merchandise item to remove.
 * @param cart_id Identifier for the cart to remove the item from.
 */
void remove_from_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, int quantity, char *merch_name, char *cart_id);

/**
 * Calculates the total cost of items in a cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param merch_table Hash table containing all merchandise.
 * @param cart_id Identifier for the cart to calculate the total cost of.
 */
void calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id);

/**
 * Finalizes a purchase and checks out the cart.
 * 
 * @param cart_table Hash table containing all shopping carts.
 * @param merch_table Hash table containing all merchandise.
 * @param cart_id Identifier for the cart to check out.
 */
void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id);

/**
 * Destroys the cart table, freeing all associated memory.
 * 
 * @param cart_table Hash table containing all shopping carts.
 */
void cart_table_destroy(ioopm_hash_table_t *cart_table);

/**
 * Destroys the merchandise table, freeing all associated memory.
 * 
 * @param merch_table Hash table containing all merchandise.
 */
void merch_table_destroy(ioopm_hash_table_t *merch_table);

#endif // INVENTORY_SYSTEM_H
