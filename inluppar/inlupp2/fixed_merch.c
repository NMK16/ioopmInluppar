#include "product.h"
#include "common.h"
#include "hashtable.h"
#include "linked_list.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iterator.h"
#include <ctype.h>

#define MAX_INPUT 256

#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

bool eq_fn(elem_t e1, elem_t e2) {
    return strcmp(e1.p, e2.p) == 0;
}

int hash_fn(elem_t key) {
    int *hash = (int *) key.p;
    return *hash % 17;  
}

merch_t *create_merch(char *name, char *description, int price) {
    merch_t *new_merch = calloc(1, sizeof(merch_t));
    if (!new_merch) return NULL;
    new_merch->name = strdup(name);
    new_merch->description = strdup(description);
    new_merch->price = price;
    new_merch->locStocks = ioopm_linked_list_create(eq_fn);
    new_merch->amountInStock = 0;
    return new_merch;
}

void destroy_merch(merch_t *merch) {
    free(merch->name);
    free(merch->description);
    ioopm_linked_list_destroy(merch->locStocks);
    free(merch);
}

int cmpstringp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void add_merch(ioopm_hash_table_t *merch_table, char *merch_name, char *desc, int price) {
    elem_t key = ptr_elem(merch_name);

    while(ioopm_hash_table_has_key(merch_table, key)){
        key = ptr_elem(merch_name);
    }
    merch_t *merch = create_merch(merch_name, desc, price);
    elem_t value = ptr_elem(merch);
    ioopm_hash_table_insert(merch_table, key, value);
}

void list_merch(ioopm_hash_table_t *merch_table, char *listMore) {
    ioopm_list_t *allValues = ioopm_hash_table_values(merch_table);
    size_t size = ioopm_linked_list_size(allValues);
    char **merch_array = malloc(size * sizeof(char *));
    
    for (size_t i = 0; i < size; i++) {
        elem_t merch_elem = ioopm_linked_list_get(allValues, i);
        merch_t *merch = merch_elem.p;
        merch_array[i] = merch->name;
    }

    qsort(merch_array, size, sizeof(char *), cmpstringp);

    for (int j = 0; j < size; j++) {
        if (j % 20 == 0 && j != 0) {
            if (toupper(listMore[0]) == 'N'){
                break;
            }
        }
        printf("\n%d. %s\n", j+1, merch_array[j]);
    }

    free(merch_array);
    ioopm_linked_list_destroy(allValues);
}

void remove_merch(ioopm_hash_table_t *merch_table, char *merch_name, char *confirmation) {
    elem_t key = ptr_elem(merch_name);
    elem_t *value = ioopm_hash_table_lookup(merch_table, key);
    if (!value || value->p == NULL) return;

    if (toupper(confirmation[0]) == 'Y') {
        value = ioopm_hash_table_remove(merch_table, key);
        merch_t *merch = value->p;
        destroy_merch(merch);
        free(value);
    }
}

static void edit_helper(ioopm_hash_table_t *merch_table, char *old_name, char *new_name, char *new_description, int new_price) {
    elem_t old_key = ptr_elem(old_name);
    elem_t *existing = ioopm_hash_table_lookup(merch_table, old_key);

    merch_t *merch = existing->p;

    free(merch->name);  
    merch->name = strdup(new_name);  

    free(merch->description); 
    merch->description = strdup(new_description); 

    merch->price = new_price;  

    if (strcmp(old_name, new_name) != 0) {
        ioopm_hash_table_remove(merch_table, old_key);  
        elem_t new_key = ptr_elem(new_name);  
        ioopm_hash_table_insert(merch_table, new_key, ptr_elem(merch)); 
    }
}

void edit_merch(ioopm_hash_table_t *merch_table, char *old_name, char *new_name, char *new_description, int new_price) {
    if (!ioopm_hash_table_has_key(merch_table, ptr_elem(old_name))) {
        printf("Merchandise with name '%s' not found.\n", old_name);
        return; 
    }
    edit_helper(merch_table, old_name, new_name, new_description, new_price);
}

void show_stock(ioopm_hash_table_t *merch_table, char *name) {
    elem_t merch_key = ptr_elem(name);
    elem_t *stock_list = ioopm_hash_table_lookup(merch_table, merch_key);

    if (!stock_list || stock_list->p == NULL) {
        printf("\nNo stock available for %s.\n", name);
        return;
    }

    merch_t *merch = stock_list->p;
    ioopm_list_t *locations = merch->locStocks;

    if (locations->size == 0) {
        printf("\nNo stock locations found for %s.\n", name);
        return;
    }

    char **location_keys = malloc(locations->size * sizeof(char *));
    if (!location_keys) return;

    for (size_t i = 0; i < locations->size; i++) {
        elem_t location_elem = ioopm_linked_list_get(locations, i);
        stock_location_t *stock = location_elem.p;
        location_keys[i] = stock->location;
    }

    qsort(location_keys, locations->size, sizeof(char *), cmpstringp);

    for (size_t i = 0; i < locations->size; i++) {
        if (i > 0 && strcmp(location_keys[i], location_keys[i - 1]) == 0) {
            continue;
        }
        elem_t location_elem = ioopm_linked_list_get(locations, i);
        stock_location_t *stock = location_elem.p;
        printf("Location: %s, Quantity: %d\n", stock->location, stock->quantity);
    }

    free(location_keys);
}

void replenish_stock(ioopm_hash_table_t *merch_table, char *name, char *location, int quantity) {
    elem_t merch_key = ptr_elem(name);
    elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, merch_key);
    if (merch_elem == NULL) return;

    merch_t *merch = merch_elem->p;

    for (size_t i = 0; i < ioopm_linked_list_size(merch->locStocks); i++) {
        elem_t location_elem = ioopm_linked_list_get(merch->locStocks, i);
        stock_location_t *stock = location_elem.p;

        if (strcmp(stock->location, location) == 0) {
            stock->quantity += quantity;
            merch->amountInStock += quantity;
            return;
        }
    }

    stock_location_t *new_stock = malloc(sizeof(stock_location_t));
    new_stock->location = strdup(location);
    new_stock->quantity = quantity;
    ioopm_linked_list_append(merch->locStocks, ptr_elem(new_stock));
    merch->amountInStock += quantity;
}

void create_cart(ioopm_hash_table_t *cart_table, char *cart_id) {
    ioopm_hash_table_t *cart = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_insert(cart_table, ptr_elem(cart_id), ptr_elem(cart));
}

void remove_cart(ioopm_hash_table_t *cart_table, char *cart_id, char *confirmation) {
    if (confirmation[0] == 'Y' || confirmation[0] == 'y') {
        elem_t *cart = ioopm_hash_table_remove(cart_table, ptr_elem(cart_id)); 
        if (cart && cart->p) {
            ioopm_hash_table_destroy(cart->p);
            free(cart);
        }
    }
}

void add_to_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id, char *merch_name, int quantity) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
    if (cart_elem == NULL) return;

    elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, ptr_elem(merch_name));
    merch_t *merch = merch_elem == NULL ? NULL : merch_elem->p;
    if (merch == NULL || merch->locStocks->size == 0 || quantity > merch->amountInStock) return;

    ioopm_hash_table_t *cart = cart_elem->p;
    ioopm_hash_table_insert(cart, ptr_elem(merch_name), int_elem(quantity));
}
 void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
    if (cart_elem == NULL) {
        printf("Cart not found.\n");
        return;
    }

    ioopm_hash_table_t *cart = cart_elem->p;
    ioopm_iterator_t *cart_iter = ioopm_hash_table_iterator(cart);
    bool is_checkout_successful = true;

    while (ioopm_iterator_has_next(cart_iter)) {
        elem_t *entry = ioopm_iterator_next(cart_iter);
        elem_t merch_name_elem = entry->key;
        elem_t quantity_elem = entry->value;

        elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, merch_name_elem);
        if (merch_elem == NULL) {
            printf("Merchandise %s not found.\n", (char *)merch_name_elem.p);
            is_checkout_successful = false;
            continue;
        }

        merch_t *merch = merch_elem->p;
        int quantity = quantity_elem.i;
        
        if (quantity > merch->amountInStock) {
            printf("Not enough stock for %s. Available: %d\n", (char *)merch_name_elem.p, merch->amountInStock);
            is_checkout_successful = false;
        } else {
            merch->amountInStock -= quantity;
            printf("Checked out %d of %s\n", quantity, (char *)merch_name_elem.p);
        }
    }

    ioopm_iterator_destroy(cart_iter);

    if (is_checkout_successful) {
        printf("Checkout completed successfully.\n");
    } else {
        printf("Some items were not available in sufficient quantities.\n");
    }
}

void list_cart(ioopm_hash_table_t *cart_table, char *cart_id) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
    if (cart_elem == NULL) {
        printf("Cart not found.\n");
        return;
    }

    ioopm_hash_table_t *cart = cart_elem->p;
    ioopm_iterator_t *cart_iter = ioopm_hash_table_iterator(cart);

    printf("Items in cart %s:\n", cart_id);

    while (ioopm_iterator_has_next(cart_iter)) {
        elem_t *entry = ioopm_iterator_next(cart_iter);
        printf("- %s: %d\n", (char *)entry->key.p, entry->value.i);
    }

    ioopm_iterator_destroy(cart_iter);
}

void clear_cart(ioopm_hash_table_t *cart_table, char *cart_id) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
    if (cart_elem == NULL) {
        printf("Cart not found.\n");
        return;
    }

    ioopm_hash_table_t *cart = cart_elem->p;
    ioopm_hash_table_clear(cart);

    printf("Cart %s has been cleared.\n", cart_id);
}

int main() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);

    // Sample operations for testing
    add_merch(merch_table, "Laptop", "A powerful laptop", 1000);
    add_merch(merch_table, "Phone", "A sleek smartphone", 500);
    
    list_merch(merch_table, "Y");

    replenish_stock(merch_table, "Laptop", "Warehouse", 10);
    replenish_stock(merch_table, "Phone", "Warehouse", 15);
    
    create_cart(cart_table, "cart123");
    add_to_cart(cart_table, merch_table, "cart123", "Laptop", 2);
    add_to_cart(cart_table, merch_table, "cart123", "Phone", 1);

    list_cart(cart_table, "cart123");

    checkout(cart_table, merch_table, "cart123");

    clear_cart(cart_table, "cart123");

    remove_cart(cart_table, "cart123", "Y");
    
    // Cleanup
    ioopm_hash_table_destroy(merch_table);
    ioopm_hash_table_destroy(cart_table);

    return 0;
}
