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

// Compile command: gcc merch_test.c hashtable.c linked_list.c merch.c utils.c -o merch_test -lcunit
#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

bool eq_fn(elem_t e1, elem_t e2)
{
    return strcmp(e1.p, e2.p) == 0;
}

int hash_fn(elem_t key) {
    int hash = 0;
    for (char *str = key.p; *str != '\0'; str++) {
        hash = (hash * 31) + *str;  // hash * 31 + character value
    }
    return hash % 17;  // modulo to fit within the table size
}

merch_t *create_merch(char *name, char *description, int price) {
    merch_t *new_merch = malloc(sizeof(merch_t));
    if (!new_merch) return NULL;
    new_merch->name = strdup(name);
    new_merch->description = strdup(description);
    new_merch->price = price;
    return new_merch;
}

int cmpstringp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void add_merch(ioopm_hash_table_t *merch_table) {
    char *merch_name = ask_question_string("\nEnter merchandise name to add: ");

    for (int i = 0; merch_name[i] != '\0'; i++) {
        merch_name[i] = toupper((unsigned char)merch_name[i]);
    }
    elem_t key = ptr_elem(merch_name);

    while(ioopm_hash_table_has_key(merch_table, key)){
        printf("Name already exists, enter another name:\n");
        merch_name = ask_question_string("\nEnter name of Merch: ");
        key = ptr_elem(merch_name);
    }
    char *desc = ask_question_string("\nEnter description of Merch: ");
    int price = ask_question_int("\nEnter price of Merch: ");
    merch_t *merch = create_merch(merch_name, desc, price);
 
    elem_t value = ptr_elem(merch);
    ioopm_hash_table_insert(merch_table, key, value);
}

// List all merchandise items in alphabetical order

void list_merch(ioopm_hash_table_t *merch_table){
    ioopm_list_iterator_t *allValues = calloc(1, sizeof(ioopm_list_iterator_t));
    allValues->list = ioopm_hash_table_values(merch_table);
    allValues->current = ioopm_hash_table_keys(merch_table)->head;
    size_t size = ioopm_linked_list_size(allValues->list);
    int i = 0;
    char **merch_array = calloc(size, sizeof(merch_t));
    while (ioopm_iterator_has_current(allValues)) {
        merch_array[i] = (char *)allValues->current->value.p;  // Cast and store pointer to merch_t
        if(ioopm_iterator_has_next(allValues)){
            ioopm_iterator_next(allValues);
            i++;
        }
        else{
            break;
        }
    }
    qsort(merch_array, size, sizeof(char *), cmpstringp);
    for (int j = 0; j < size; j++) {
        char *merch = merch_array[j];
        printf("\n%d. %s\n", j+1, merch);  // Print merch name
    }
}





void remove_merch(ioopm_hash_table_t *merch_table) {
    
    char *merch_name = ask_question_string("\nEnter merchandise name to remove: ");

    for (int i = 0; merch_name[i] != '\0'; i++) {
        merch_name[i] = toupper((unsigned char)merch_name[i]);
    }
    elem_t key = ptr_elem(merch_name);
    elem_t *value = ioopm_hash_table_remove(merch_table, key);
    if (!value || value->p == NULL) return;
    char *confirmation;
    while(confirmation[0] != 'Y' || confirmation[0] != 'N'){
        confirmation = ask_question_string("Type 'Y'/'N' to confirm/revoke removal: ");
        if ((confirmation[0]) == 'Y') {
                merch_t *merch = value->p;
                free(merch->name);
                free(merch->description);
                free(merch);
                printf("\nMerchandise removed successfully.\n");
                return;
            }
        else if((confirmation[0]) == 'N'){
                printf("\nMerchandise NOT removed.\n");
                return;
            }
        else    {
                printf("Invalid input.\n");
            }
        }
    }

static void edit_helper(ioopm_hash_table_t *merch_table, char *old_name, char *new_name, char *new_description, int new_price){
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

void edit_merch(ioopm_hash_table_t *merch_table) {
 
    char *old_name = ask_question_string("Enter old name: ");
    for (int i = 0; old_name[i] != '\0'; i++) {
        old_name[i] = (unsigned char) toupper(old_name[i]);  
    }

    if (!ioopm_hash_table_has_key(merch_table, ptr_elem(old_name))) {
        printf("Merchandise with name '%s' not found.\n", old_name);
        return; 
    }

    char *new_name = ask_question_string("Enter new name: ");
    for (int i = 0; new_name[i] != '\0'; i++) {
        new_name[i] = (unsigned char) toupper(new_name[i]);  
    }

    char *new_description = ask_question_string("Enter new description: ");
    int new_price = ask_question_int("Enter new price: ");

    edit_helper(merch_table, old_name, new_name, new_description, new_price);
}

void show_stock(ioopm_hash_table_t *stock_table, char *name) {
    elem_t merch_key = ptr_elem(name);
    elem_t *stock_list = ioopm_hash_table_lookup(stock_table, merch_key);

    if (!stock_list || stock_list->p == NULL) {
        printf("No stock available for %s.\n", name);
        return;
    }

    ioopm_list_t *locations = stock_list->p;

    size_t total_locations = ioopm_linked_list_size(locations);
    if (total_locations == 0) {
        printf("No stock locations found for %s.\n", name);
        return;
    }

    // Allocate memory to sort and store unique location keys
    char **location_keys = malloc(total_locations * sizeof(char *));
    if (!location_keys) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (size_t i = 0; i < total_locations; i++) {
        elem_t location_elem = ioopm_linked_list_get(locations, i);
        stock_location_t *stock = location_elem.p;
        location_keys[i] = stock->location;
    }

    // Sort location keys alphabetically
    qsort(location_keys, total_locations, sizeof(char *), cmpstringp);

    // Print stock quantities for each unique location
    for (size_t i = 0; i < total_locations; i++) {
        if (i > 0 && strcmp(location_keys[i], location_keys[i - 1]) == 0) {
            continue;  // Skip duplicate locations
        }

        elem_t location_elem = ioopm_linked_list_get(locations, i);
        stock_location_t *stock = location_elem.p;
        printf("Location: %s, Quantity: %d\n", stock->location, stock->quantity);
    }

    free(location_keys);
}


bool replenish_stock(ioopm_hash_table_t *merch_table, ioopm_hash_table_t *stock_table, char *name, char *location, int quantity) {
    elem_t merch_key = ptr_elem(name);
    if (!ioopm_hash_table_has_key(merch_table, merch_key)) {
        return false;
    }

    elem_t *stock_list_elem = ioopm_hash_table_lookup(stock_table, merch_key);
    ioopm_list_t *locations;

    if (!stock_list_elem || !stock_list_elem->p) {
        locations = ioopm_linked_list_create(eq_fn);
        ioopm_hash_table_insert(stock_table, merch_key, ptr_elem(locations));
    } else {
        locations = stock_list_elem->p;
    }

    for (size_t i = 0; i < ioopm_linked_list_size(locations); i++) {
        elem_t location_elem = ioopm_linked_list_get(locations, i);
        stock_location_t *stock = location_elem.p;
        
        if (strcmp(stock->location, location) == 0) {
            stock->quantity += quantity; // Update quantity
            printf("Updated %d units of %s at location %s\n", stock->quantity, name, location);
            return true;
        }
    }

    stock_location_t *new_stock = malloc(sizeof(stock_location_t));
    new_stock->location = strdup(location);
    new_stock->quantity = quantity;
    ioopm_linked_list_append(locations, ptr_elem(new_stock));

    printf("Added %d units of %s at location %s\n", quantity, name, location);
    return true;
}



void create_cart(ioopm_hash_table_t *cart_table, char* user_id) {
    ioopm_hash_table_t *cart = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);  
    ioopm_hash_table_insert(cart_table, ptr_elem(user_id), ptr_elem(cart));  
}

// Remove a user's cart from the cart_table
void remove_cart(ioopm_hash_table_t *cart_table, char *user_id) {
    elem_t *cart = ioopm_hash_table_remove(cart_table, ptr_elem(user_id));  // Remove cart from the cart_table
    if (cart && cart->p) {
        ioopm_hash_table_destroy(cart->p); 
    }
}

// Add an item to a user's cart (increases the quantity if the item already exists)
void add_to_cart(ioopm_hash_table_t *cart_table, char *user_id, char *item_name, int quantity) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(user_id));  
    if (!cart_elem || !cart_elem->p) {
        return;  
    }

    ioopm_hash_table_t *cart = cart_elem->p;  
    
    elem_t *item_elem = ioopm_hash_table_lookup(cart, ptr_elem(item_name));
    if (item_elem) {
        // Item exists, increase the quantity
        item_elem->i += quantity;
    } else {
        // Item doesn't exist, add it with the specified quantity
        ioopm_hash_table_insert(cart, ptr_elem(item_name), int_elem(quantity));
    }
}

// Remove an item from a user's cart (decreases the quantity or removes it)
void remove_from_cart(ioopm_hash_table_t *cart_table, char *user_id, char *item_name, int quantity) {
    elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(user_id));  
    if (!cart_elem || !cart_elem->p) {
        return;  
    }

    ioopm_hash_table_t *cart = cart_elem->p;  

    elem_t *item_elem = ioopm_hash_table_lookup(cart, ptr_elem(item_name));
    if (!item_elem) {
        return;  // If the item doesn't exist, return
    }

    if (item_elem->i > quantity) {
        item_elem->i -= quantity;  // Decrease quantity
    } else {
        ioopm_hash_table_remove(cart, ptr_elem(item_name));  
    }
}



int calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char* cart_id) {
    int total_cost = 0;
    elem_t *cart = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
    if (!cart || !cart->p) return total_cost;

    ioopm_list_t *cart_list = cart->p;
    for (size_t i = 0; i < ioopm_linked_list_size(cart_list); i++) {
        elem_t name = ioopm_linked_list_get(cart_list, i);
        elem_t *merch = ioopm_hash_table_lookup(merch_table, name);
        if (merch && merch->p) {
            merch_t *merch_item = merch->p;
            total_cost += merch_item->price;
        }
    }
    return total_cost;
}

void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *stock_table, char* cart_id) {
    elem_t *cart = ioopm_hash_table_remove(cart_table, ptr_elem(cart_id));
    if (cart && cart->p) {
        ioopm_linked_list_destroy(cart->p);  
    }
}

int main() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *stock_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);

    printf("Welcome to MAMAZON! \n");

    while (1) {
        char *option = ask_question_string("\nEnter input/action:  \nA: Add \nL: List \nD: Remove \nE: Edit \nS: Show Stock \nP: Replenish \nC: Create Cart \nR: Remove Cart \n+: Add to Cart \n-: Remove from Cart \n=: Calculate Cost \nO: Checkout \nQ: Quit\n");

        for(int i = 0; option[i] != '\0'; i++){
            option[i] = (unsigned char) toupper(option[i]);
        }
        switch (*option) {
            case 'A':
                {
                    add_merch(merch_table);
                    break;
                }

            case 'L':
                list_merch(merch_table);
                printf("Merch table size: %zu\n", ioopm_hash_table_size(merch_table)); //Den ökar men de list_merch printar inte us svaren
                break;

            case 'D':
                {
                    remove_merch(merch_table);
                    break;
                }
                

            case 'E':
                {
                    edit_merch(merch_table); 
                    break;
                }

            case 'S':
                {
                    char name[MAX_INPUT];
                    printf("Enter merchandise name (in all caps) to show stock: ");
                    fgets(name, sizeof(name), stdin);
                    strtok(name, "\n");
                    show_stock(stock_table, name);
                }
                break;

            case 'P':
                {
                    char name[MAX_INPUT], location[MAX_INPUT];
                    int quantity;
                    printf("Enter merchandise name in all capss: ");
                    fgets(name, sizeof(name), stdin);
                    strtok(name, "\n"); 
                    printf("Enter storage location: ");
                    fgets(location, sizeof(location), stdin);
                    strtok(location, "\n"); 
                    printf("Enter quantity to add: ");
                    scanf("%d", &quantity);
                    getchar(); 

                    if (replenish_stock(merch_table, stock_table, name, location, quantity)) {
                        printf("Stock replenished successfully.\n");
                    } else {
                        printf("Failed to replenish stock. Merchandise may not exist.\n");
                    }
                }
                break;

            case 'C':
                {
                    char* cart_id = ask_question_string("Enter cart ID: "); 
                    create_cart(cart_table, cart_id);
                    printf("Cart %s created successfully.\n", cart_id);
                }
                break;

            case 'R':
                {
                    char* cart_id = ask_question_string("Enter cart ID: "); 
                    char confirmation[MAX_INPUT];
                    printf("Enter cart ID to remove: ");
                    getchar(); 
                    printf("Type 'Y' to confirm removal: ");
                    fgets(confirmation, sizeof(confirmation), stdin);
                    if (confirmation[0] == 'Y' || confirmation[0] == 'y') {
                        remove_cart(cart_table, cart_id);
                        printf("Cart removed successfully.\n");
                    }
                }
                break;

            case '+':
                {
                    char* cart_id = ask_question_string("Enter cart ID: "); 
                    char name[MAX_INPUT];
                    int quantity;
                    printf("Enter cart ID: ");
                    scanf("%d", &cart_id);
                    getchar(); 
                    printf("Enter merchandise name: ");
                    fgets(name, sizeof(name), stdin);
                    strtok(name, "\n"); 
                    printf("Enter quantity to add: ");
                    scanf("%d", &quantity);
                    getchar(); 
                    add_to_cart(cart_table, cart_id, name, quantity);
                    printf("Added %d of %s to cart %d.\n", quantity, name, cart_id);
                }
                break;

            case '-':
                {
                    int cart_id;
                    char name[MAX_INPUT];
                    printf("Enter cart ID: ");
                    scanf("%d", &cart_id);
                    getchar(); 
                    printf("Enter merchandise name: ");
                    fgets(name, sizeof(name), stdin);
                    strtok(name, "\n"); 
                    int quantity = ask_question_int("Write the quanitity that you want to remove:");
                    remove_from_cart(cart_table, cart_id, name, quantity);
                    printf("Removed %s from cart %d.\n", name, cart_id);
                }
                break;

            case '=':
                {
                    int cart_id = 0;
                    printf("Enter cart ID: ");
                    scanf("%d", &cart_id);
                    getchar(); 
                    int cost = calculate_cost(cart_table, merch_table, cart_id);
                    printf("Total cost for cart %d is: %d\n", cart_id, cost);
                }
                break;

            case 'O':
                {
                    int cart_id;
                    printf("Enter cart ID for checkout: ");
                    scanf("%d", &cart_id);
                    getchar(); 
                    checkout(cart_table, stock_table, cart_id);
                    printf("Checked out cart %d.\n", cart_id);
                }
                break;

            case 'Q':
                {
                    char confirmation[MAX_INPUT];
                    printf("Are you sure you want to quit? Type 'Y' to confirm: ");
                    fgets(confirmation, sizeof(confirmation), stdin);
                    if (confirmation[0] == 'Y' || confirmation[0] == 'y') {
                        printf("Exiting...\n");
                        ioopm_hash_table_destroy(merch_table);
                        ioopm_hash_table_destroy(stock_table);
                        ioopm_hash_table_destroy(cart_table);
                        return 0;
                    }
                }
                break;

            default:
                printf("Invalid action code. Please try again.\n");
                break;
        }
    }

    ioopm_hash_table_destroy(merch_table);
    ioopm_hash_table_destroy(stock_table);
    ioopm_hash_table_destroy(cart_table);
    return 0;
}