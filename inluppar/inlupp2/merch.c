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

    //FIX TESTS

    //VALGRIND

    #define int_elem(x) (elem_t) { .i = (x) }
    #define ptr_elem(x) (elem_t) { .p = (x) }

    bool eq_fn(elem_t e1, elem_t e2) {
        return strcmp(e1.p, e2.p) ==  0;
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

    void destroy_merch(merch_t *merch){
        free(merch->name);  
        free(merch->description);
        for(int i = 0; i < merch->locStocks->size; i++){
            elem_t merch_elem = ioopm_linked_list_get(merch->locStocks, i);
            stock_location_t *stock = merch_elem.p;
            free(stock->location);
            free(stock);
        }
        ioopm_linked_list_destroy(merch->locStocks);
        free(merch);
    }

    void cart_table_destroy(ioopm_hash_table_t *cart_table) {
        ioopm_list_t *cart_table_list = ioopm_hash_table_values(cart_table);
        ioopm_list_iterator_t *iterator_list = ioopm_list_iterator_create(cart_table_list);
        for(int i = 0; i < ioopm_linked_list_size(cart_table_list) && ioopm_iterator_has_current(iterator_list); i++){
            ioopm_hash_table_destroy(iterator_list->current->value.p);
            ioopm_iterator_next(iterator_list);
        }
        ioopm_iterator_destroy(iterator_list);
        ioopm_linked_list_destroy(cart_table_list);
        ioopm_hash_table_destroy(cart_table);
    }

    void merch_table_destroy(ioopm_hash_table_t *merch_table) {
        ioopm_list_t *merch_value_list = ioopm_hash_table_values(merch_table);
        ioopm_list_iterator_t *iterator_list = ioopm_list_iterator_create(merch_value_list);
        for(int i = 0; i < ioopm_linked_list_size(merch_value_list) && ioopm_iterator_has_current(iterator_list); i++){
            destroy_merch((merch_t *)iterator_list->current->value.p);
            ioopm_iterator_next(iterator_list);
        }
        ioopm_iterator_destroy(iterator_list);
        ioopm_linked_list_destroy(merch_value_list);
        ioopm_hash_table_destroy(merch_table);
    }

    int cmpstringp(const void *a, const void *b) {
        return strcmp(*(const char **)a, *(const char **)b);
    }

    void add_merch(ioopm_hash_table_t *merch_table, int price, char *desc,  char *merch_name) {
        // char *merch_name = ask_question_string("\nEnter merchandise name to add: ");
        elem_t key = ptr_elem(merch_name);

        while(ioopm_hash_table_has_key(merch_table, key)){
            printf("Name already exists, enter another name:\n");
            // merch_name = ask_question_string("\nEnter name of Merch: ");
            key = ptr_elem(merch_name);
        }
        // char *desc = ask_question_string("\nEnter description of Merch: ");
        // int price = ask_question_int("\nEnter price of Merch: ");
        merch_t *merch = create_merch(merch_name, desc, price);
    
        elem_t value = ptr_elem(merch);
        ioopm_hash_table_insert(merch_table, key, value);
        free(desc);
        free(merch_name);
    }

    // List all merchandise items in alphabetical order

    void list_merch(ioopm_hash_table_t *merch_table, char *listMore){
        ioopm_list_t *list_of_vals = ioopm_hash_table_values(merch_table);
        ioopm_list_iterator_t *all_values = ioopm_list_iterator_create(list_of_vals);

        size_t size = ioopm_linked_list_size(list_of_vals);
        char **merch_array = calloc(size, sizeof(char *));
        int i = 0;

        while (ioopm_iterator_has_current(all_values) && i < size) {
            merch_t *merch = (merch_t *) ioopm_iterator_current(all_values).p; 
            merch_array[i] = merch -> name;
            ioopm_iterator_next(all_values);
            i++;
        }


        qsort(merch_array, size, sizeof(char *), cmpstringp);
        for (int j = 0; j < size; j++) {
            if(j % 20 == 0 && j > 0){
                if (toupper(listMore[0]) == 'N'){
                    return;
                }
            }
            char *merch = merch_array[j];
            printf("\n%d. %s\n", j+1, merch);  // Print merch name
        }
        
        printf("Merch table size: %zu\n", ioopm_hash_table_size(merch_table));
        ioopm_linked_list_destroy(list_of_vals);
        ioopm_iterator_destroy(all_values);
        free(merch_array);
    }





    void remove_merch(ioopm_hash_table_t *merch_table, char *confirmation, char *merch_name) {
        elem_t key = ptr_elem(merch_name);
        elem_t *value = ioopm_hash_table_lookup(merch_table, key);
        
        if (!value || value->p == NULL) {
            return;
        }

        if (toupper(confirmation[0]) == 'Y') {
            value = ioopm_hash_table_remove(merch_table, key);
            merch_t *merch = value->p;
            destroy_merch(merch);
            printf("\nMerchandise removed successfully.\n");
        }
        else if (toupper(confirmation[0]) == 'N') {
            printf("\nMerchandise NOT removed.\n");
        }
        else {
            printf("\nInvalid input.\n");
        }


        free(value);  
    }

    static void edit_helper(ioopm_hash_table_t *merch_table, int new_price, char *new_description, char *new_name, char *old_name){
        elem_t old_key = ptr_elem(old_name);
        elem_t *existing = ioopm_hash_table_lookup(merch_table, old_key);

        merch_t *merch = existing->p;

        
        free(merch->name);  
        merch->name = strdup(new_name);  

        free(merch->description); 
        merch->description = strdup(new_description); 

        merch->price = new_price;  

    
        if (strcmp(old_name, new_name) != 0) {
            free(ioopm_hash_table_remove(merch_table, old_key));  
            elem_t new_key = ptr_elem(new_name);  
            ioopm_hash_table_insert(merch_table, new_key, ptr_elem(merch)); 
        }
    }

    void edit_merch(ioopm_hash_table_t *merch_table, int new_price,char *new_description, char *new_name, char *old_name) {
    
        // char *old_name = ask_question_string("Enter old name: ");

        if (!ioopm_hash_table_has_key(merch_table, ptr_elem(old_name))) {
            printf("Merchandise with name '%s' not found.\n", old_name);
            return; 
        }

        // char *new_name = ask_question_string("Enter new name: ");


        // char *new_description = ask_question_string("Enter new description: ");
        // int new_price = ask_question_int("Enter new price: ");

        edit_helper(merch_table, new_price, new_description, new_name, old_name);
    }

    void show_stock(ioopm_hash_table_t *merch_table, char *name) {
        // char *name = ask_question_string("\nEnter merchandise name (in all caps) to show stock: ");
        elem_t merch_key = ptr_elem((name));
        elem_t *stock_list = ioopm_hash_table_lookup(merch_table, merch_key);

        if (!stock_list) {
            printf("\nNo stock available for %s.\n", name);
            free(name);
            return;
        }
        if(stock_list->p == NULL){
            printf("\nNo stock available for %s.\n", name);
            free(name);
            return;
        }
        merch_t *merch = stock_list->p;
        ioopm_list_t *locations = merch->locStocks;
        if (locations->size == 0) {
            printf("\nNo stock locations found for %s.\n", name);
            free(name);
            return;
        }

        // Allocate memory to sort and store unique location keys
        char **location_keys = calloc(locations->size, sizeof(char *));
        if (!location_keys) {
            printf("\nMemory allocation failed!\n");
            free(name);
            return;
        }

        for (size_t i = 0; i < locations->size; i++) {
            elem_t location_elem = ioopm_linked_list_get(locations, i);
            stock_location_t *stock = location_elem.p;
            location_keys[i] = stock->location;
        }

        // Sort location keys alphabetically
        qsort(location_keys, locations->size, sizeof(char *), cmpstringp);

        // Print stock quantities for each unique location
        for (size_t i = 0; i < locations->size; i++) {
            if (i > 0 && strcmp(location_keys[i], location_keys[i - 1]) == 0) {
                continue;  // Skip duplicate locations
            }
            elem_t location_elem = ioopm_linked_list_get(locations, i);
            stock_location_t *stock = location_elem.p;
            printf("Location: %s, Quantity: %d\n", stock->location, stock->quantity);
        }

        free(location_keys);
        free(name);
    }

    //Helper function for location in replenish stock
    static int is_valid_shelf(const char *shelf) {
        if (strlen(shelf) != 3) {
            return false;
        }
        if (!isalpha(shelf[0]) || !isdigit(shelf[1]) || !isdigit(shelf[2])) {
            return false;
        }
        return true;
    }

    void replenish_stock(ioopm_hash_table_t *merch_table, int quantity, char *location, char *name) {
        // char *name = ask_question_string("\nEnter merchandise name in all caps: ");
        elem_t merch_key = ptr_elem(name);
        elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, merch_key);   
        if(merch_elem == NULL){
            printf("Merchandise not found in inventory:\n");
            free(location);
            free(name);
            return;
        }
        merch_t *merch = merch_elem->p;
        // char *location = ask_question_string("\nEnter location name: ");
        // int quantity = ask_question_int("\nEnter quantity: ");

        if(!is_valid_shelf(location)){
            printf("\n Not a valid location, try with a letter followed by two digits \n");
            free(location);
            free(name);
            return;
        }

        for (size_t i = 0; i < ioopm_linked_list_size(merch->locStocks); i++) {
            elem_t location_elem = ioopm_linked_list_get(merch->locStocks, i);
            stock_location_t *stock = location_elem.p;
            if (strcmp(stock->location, location) == 0) {
                stock->quantity += quantity;
                merch->amountInStock += quantity;
                printf("Updated %d units of %s at location %s\n", stock->quantity, name, location);
                free(location);
                free(name);
                return;
            }
        }

        stock_location_t *new_stock = malloc(sizeof(stock_location_t));
        new_stock->location = strdup(location);
        new_stock->quantity = quantity;
        ioopm_linked_list_append(merch->locStocks, ptr_elem(new_stock));
        merch->amountInStock += quantity;
        printf("\nAdded %d units of %s at location %s\n", quantity, name, location);
        free(location);
        free(name);
    }



    void create_cart(ioopm_hash_table_t *cart_table, char *cart_id) {
        // char *cart_id = ask_question_string("Enter cart ID: ");
        ioopm_hash_table_t *cart = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);  
        ioopm_hash_table_insert(cart_table, ptr_elem(cart_id), ptr_elem(cart));  
        printf("\nCart %s created successfully.\n", cart_id);
        free(cart_id);
    }

    // Remove a user's cart from the cart_table
    void remove_cart(ioopm_hash_table_t *cart_table, char *confirmation, char *cart_id) {
        // char* cart_id = ask_question_string("Enter cart ID to remove: "); 
        elem_t *elem_cart = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id)); 
        if(elem_cart == NULL){
            printf("\nCart id not found.\n");
            free(cart_id);
            free(confirmation);
            return;
        }
        // char *confirmation = ask_question_string("\nType 'Y'/'N' to confirm/deny removal: ");
        if (confirmation[0] == 'Y' || confirmation[0] == 'y') {
            ioopm_hash_table_t *cart = elem_cart -> p; 
            ioopm_hash_table_destroy(cart);
            elem_t *removed_val = ioopm_hash_table_remove(cart_table, ptr_elem(cart_id)); 
            free(removed_val);
            printf("\nCart got removed successfully.\n");
        }
        else{
            printf("\nCart is NOT being removed.\n");
            free(cart_id);
            free(confirmation);
            return;
        }
            free(cart_id);
            free(confirmation);
    }

    // Add an item to a user's cart (increases the quantity if the item already exists)
    void add_to_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, int quantity, char *merch_name, char *cart_id) {
        // char *cart_id = ask_question_string("Enter cart ID: "); 
        elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));  
        if (cart_elem == NULL) {
            printf("\nCart not found!\n");
            free(merch_name);
            free(cart_id);
            return;  
        }
        // char *merch_name = ask_question_string("Enter merchandise name to add: ");
        elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, ptr_elem(merch_name));
        merch_t *merch = merch_elem == NULL ? NULL : merch_elem->p;
        if(merch == NULL || merch->locStocks->size == 0){
            printf("\nMerch is either non-existant or out of stock!\n");
            free(merch_name);
            free(cart_id);
            return;
        }
        // int quantity = ask_question_int("Enter quantity to add: ");
        if(quantity > merch->amountInStock){
            printf("\nThat amount is not currently available in stock. Amount available: %d\n", merch->amountInStock);
            free(merch_name);
            free(cart_id);
            return;
        }

        ioopm_hash_table_t *cart = cart_elem->p;  
        
        elem_t *merch_elem_cart = ioopm_hash_table_lookup(cart, ptr_elem(merch_name));
        if (merch_elem_cart) {
            // Item exists, it will increase the quantity
            merch_elem_cart->i += quantity;
        } else {
            // IF Item doesn't exist, add it with the specified quantity
            ioopm_hash_table_insert(cart, ptr_elem(merch_name), int_elem(quantity));
        }
        printf("Added %d of %s to cart %s.\n", quantity, merch_name, cart_id);
        free(merch_name);
        free(cart_id);
    }

    // Remove an item from a user's cart (decreases the quantity or removes it)
    void remove_from_cart(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, int quantity, char *merch_name, char *cart_id) {
        // char *cart_id = ask_question_string("\nEnter cart ID: ");
        elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));  
        if (cart_elem == NULL) {
            printf("\nCart not found!\n");
            free(cart_id);
            free(merch_name);
            return;  
        }
        // char *merch_name = ask_question_string("Enter merchandise name to remove: ");
        elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, ptr_elem(merch_name));
        merch_t *merch = merch_elem == NULL ? NULL : merch_elem->p;
        if(merch == NULL || merch->locStocks->size == 0){
            printf("\nMerch is either non-existant or out of stock!\n");
            free(cart_id);
            free(merch_name);
            return;
        }
        // int quantity = ask_question_int("Enter quantity to remove: ");

        ioopm_hash_table_t *cart = cart_elem->p;  

        elem_t *item_elem = ioopm_hash_table_lookup(cart, ptr_elem(merch_name));
        if (!item_elem) {
            printf("Item doesn't exist in cart!");
            free(cart_id);
            free(merch_name);
            return;  
        }

        if (item_elem->i > quantity) {
            item_elem->i -= quantity; 
            if(quantity <= 0){
                destroy_merch(merch);
            }
            printf("\n%d of %s removed from the cart!\n", quantity, merch_name);
        } else if(item_elem->i == quantity){
            item_elem->i = 0;
            ioopm_hash_table_remove(cart, ptr_elem(merch_name));
            printf("\nAll of %s removed from the cart", merch_name);
        }
        else{
            printf("\nYou only have %d of %s in the cart", item_elem->i, merch_name);
        }
        free(cart_id);
        free(merch_name);
    }



    void calculate_cost(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id) {
        // char *cart_id = ask_question_string("\nEnter cart ID: ");
        int total_cost = 0;
        elem_t *cart = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
        if(cart == NULL){
            printf("Cart is non existant!");
            free(cart_id);
            return;
        }
        if(ioopm_hash_table_is_empty(cart->p)){
            printf("Cart is empty! Total cost: 0");
            free(cart_id);
            return;
        }
        ioopm_hash_table_t *cart_HT = cart->p;
        ioopm_list_t *cart_list = ioopm_hash_table_keys(cart_HT);
        for (size_t i = 0; i < ioopm_linked_list_size(cart_list); i++) {
            elem_t name = ioopm_linked_list_get(cart_list, i);
            elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, name);
            elem_t *item_elem = ioopm_hash_table_lookup(cart->p, name);
            if (merch_elem != NULL && merch_elem->p != NULL) {
                merch_t *merch_item = merch_elem->p;
                total_cost += merch_item->price*item_elem->i;
            }
        }
        ioopm_linked_list_destroy(cart_list);
        printf("Total cost: %d", total_cost);
        free(cart_id);
    }

    void checkout(ioopm_hash_table_t *cart_table, ioopm_hash_table_t *merch_table, char *cart_id) {
        elem_t *cart_elem = ioopm_hash_table_lookup(cart_table, ptr_elem(cart_id));
        if (!cart_elem || !cart_elem->p) {
            printf("\nCart is either nonexistent or empty. Total cost: 0\n");
            free(cart_id);
            return;
        }

        ioopm_hash_table_t *cart = cart_elem->p;
        if(ioopm_hash_table_is_empty(cart)){
            printf("\nCart is empty. Total cost: 0\n");
            free(cart_id);
            return;
        }
        ioopm_list_t *cart_list = ioopm_hash_table_keys(cart);
        for (size_t i = 0; i < ioopm_linked_list_size(cart_list); i++) {
            elem_t merch_name = ioopm_linked_list_get(cart_list, i);
            elem_t *merch_elem = ioopm_hash_table_lookup(merch_table, merch_name);
            elem_t *item_elem = ioopm_hash_table_lookup(cart, merch_name);
            if (merch_elem && merch_elem->p) {
                merch_t *merch = merch_elem->p;
                merch->amountInStock -= item_elem->i;
                ioopm_list_t *locations = merch->locStocks;
                for (size_t j = 0; j < ioopm_linked_list_size(locations) && item_elem->i > 0; j++) {
                    elem_t loc_elem = ioopm_linked_list_get(locations, j);
                    stock_location_t *stock = loc_elem.p;
                    int to_deduct = stock->quantity >= item_elem->i ? item_elem->i : stock->quantity;
                    stock->quantity -= to_deduct;
                    item_elem->i -= to_deduct;
                    if (stock->quantity == 0) ioopm_linked_list_remove(locations, j);
                }
            }
        }
        ioopm_linked_list_destroy(cart_list);
        cart_table_destroy(cart_table);
        printf("\nChecked out cart %s.\n", cart_id);
        free(cart_id);
    }

    int main() {
        ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
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
                        add_merch(merch_table, ask_question_int("Enter merch price: \n"), ask_question_string("Enter merch description: \n"), ask_question_string("Enter merch name: \n"));
                        free(option);
                        break;
                    }

                case 'L':
                    {
                        list_merch(merch_table, ask_question_string("Enter confirmation or reject (Y/N) to list 20 more items if available: \n"));
                        free(option);
                        break;
                    }
                case 'D':
                    {
                        remove_merch(merch_table, ask_question_string("Enter confirmation (Y) to confirm: \n"), ask_question_string("Enter merch name: \n"));
                        free(option);
                        break;
                    }
                    

                case 'E':
                    {
                        edit_merch(merch_table, ask_question_int("Enter the new price of the merch: \n"), ask_question_string("Enter the new description for the merch: \n"), ask_question_string("Enter the new name for the merch: \n"), ask_question_string("Enter old merch name: \n")); 
                        free(option);
                        break;
                    }

                case 'S':
                    {
                        show_stock(merch_table, ask_question_string("Enter the merchchandise that you wish to see the stock of: \n"));
                        free(option);
                        break;
                    }

                case 'P':
                    {
                        replenish_stock(merch_table, ask_question_int("Enter quanitity: \n"), ask_question_string("Enter location: \n"), ask_question_string("Enter the merchandise name that you wish to replenish the stock of: \n"));
                        free(option);
                        break;                   
                    }


                case 'C':
                    {
                        create_cart(cart_table, ask_question_string("Enter cart ID: \n"));
                        free(option);
                        break;
                    }

                case 'R':
                    {
                        remove_cart(cart_table, ask_question_string("Confirm removal of cart (Y):  \n"), ask_question_string("Enter cart ID: \n"));
                        free(option);
                        break;
                    }

                case '+':
                    {
                        add_to_cart(cart_table, merch_table, ask_question_int("Enter quantity to add:  \n"), ask_question_string("Enter merchandise name to add to cart  \n"),ask_question_string("Enter cart ID: \n"));
                        free(option);
                        break;
                    }

                case '-':
                    {
                        remove_from_cart(cart_table, merch_table, ask_question_int("Enter quantity to remove: \n"), ask_question_string("Enter merchandise name to remove from cart: \n"), ask_question_string("Enter cart ID: \n"));
                        free(option);
                        break;
                    }

                case '=':
                    {

                        calculate_cost(cart_table, merch_table, ask_question_string("Enter cart ID to calculate the cost of: \n"));
                        free(option);
                        break;
                    }

                case 'O':
                    {
                        checkout(cart_table, merch_table, ask_question_string("Enter cart ID that you wish to checkout: \n"));
                        free(option);
                        break;
                    }

                case 'Q':
                    {
                        char confirmation[MAX_INPUT];
                        printf("Are you sure you want to quit? Type 'Y' to confirm: \n");
                        fgets(confirmation, sizeof(confirmation), stdin);
                        if (confirmation[0] == 'Y' || confirmation[0] == 'y') {
                            printf("Exiting...\n");
                            merch_table_destroy(merch_table);
                            cart_table_destroy(cart_table);
                            free(option);
                            return 0;
                        }
                        break;
                    }

                default:
                    printf("Invalid action code. Please try again.\n");
                    break;
                    
            }
        }

        merch_table_destroy(merch_table);
        cart_table_destroy(cart_table);
        return 0;
    }