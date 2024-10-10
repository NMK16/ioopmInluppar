#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"
#include "hashtable.h"

#define No_Buckets 17



/// @brief Create a new empty hash table
/// @return Pointer to the created hash table
ioopm_hash_table_t *ioopm_hash_table_create(ioopm_hash_function *hash_fn, ioopm_eq_function *key_eq_fn, ioopm_eq_function *value_eq_fn) {
    ioopm_hash_table_t *result = calloc(No_Buckets, sizeof(ioopm_hash_table_t));
    result->hash_fn = hash_fn;
    result->key_eq_fn = key_eq_fn;
    result->value_eq_fn = value_eq_fn;
    return result;
}

/// @brief Destroy the hash table and free the allocated memory
/// @param ht the hash table to destroy
void ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
    if (ht != NULL) {
        ioopm_hash_table_clear(ht); // Clear all entries first
        free(ht);                   // Free the hash table itself
    }
}


static entry_t *entry_create(elem_t key, elem_t *value, entry_t *next_value) {
    entry_t *new_entry = calloc(1, sizeof(entry_t));
    if (new_entry == NULL) {
        return NULL;
    }
    new_entry->key = key;
    new_entry->value = *value; 
    new_entry->next = next_value;

    return new_entry;
}

// Helper function to find previous entry for a key
static entry_t *find_previous_entry_for_key(entry_t **bucket_head, elem_t key, ioopm_eq_function *key_eq_fn) {
    entry_t *current = *bucket_head;
    entry_t *prev = NULL;

    while (current != NULL && key_eq_fn(current->key, key)) {
        prev = current;
        current = current->next;
    }

    return prev;
}

/// @brief Inserting entry into the hash table 
/// @param ht the hash table being used
/// @param key the key being inserted
/// @param value the value being inserted
void ioopm_hash_table_insert(ioopm_hash_table_t *ht, elem_t key, elem_t value) {
    int bucket = ht -> hash_fn(key);
    entry_t *prev_entry = find_previous_entry_for_key(&ht->buckets[bucket], key, ht -> key_eq_fn);
    entry_t *next = prev_entry ? prev_entry->next : ht->buckets[bucket];

    if (next != NULL && ht -> key_eq_fn(next->key,key)) {
        next->value = value; // Replace with a new value
    } else {
        entry_t *new_entry = entry_create(key, value.p, next);
        if (prev_entry) {
            prev_entry->next = new_entry;
        } else {
            ht->buckets[bucket] = new_entry;
        }
    }
}

// Helper function for recursive lookup (F14)
static elem_t *recursive_lookup(ioopm_hash_table_t *ht, entry_t *searching_entry, elem_t key) {
    if (searching_entry == NULL) {
        return NULL; 
    }

    if (ht -> key_eq_fn(searching_entry->key, key)) {
        return &searching_entry -> value; 
    }

    // The recursive call is now the last operation.
    return recursive_lookup(ht, searching_entry->next, key); 
}

/// @brief Lookup the value for a key in the hash table
/// @param ht the hash table being used
/// @param key the key to lookup
/// @return the value mapped to by key, or NULL if not found
elem_t *ioopm_hash_table_lookup(ioopm_hash_table_t *ht, elem_t key) {
    int bucket = ht ->hash_fn(key);
    return recursive_lookup(ht, ht->buckets[bucket], key);
}


/// @brief Remove any mapping from key to a value
/// @param ht hash table operated upon
/// @param key key to remove
/// @return the value mapped to by key
elem_t *ioopm_hash_table_remove(ioopm_hash_table_t *ht, elem_t key) {
    int bucket = ht -> hash_fn(key);
    entry_t *prev_entry = find_previous_entry_for_key(&ht->buckets[bucket], key, ht -> key_eq_fn);
    entry_t *entry_to_remove = prev_entry ? prev_entry->next : ht->buckets[bucket];

    elem_t *removed_val = calloc(1, sizeof(ht));

    *removed_val = entry_to_remove->value; 
    
    if (prev_entry) {
        prev_entry->next = entry_to_remove->next;
    } else {
        ht->buckets[bucket] = entry_to_remove->next;
    }

    free(entry_to_remove);       
    return removed_val;            
}

/// @brief Returns the number of key => value entries in the hash table
/// @param ht hash table operated upon
/// @return the number of key => value entries in the hash table
size_t ioopm_hash_table_size(ioopm_hash_table_t *ht) {
    size_t size = 0;
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry) {
            size++;
            entry = entry->next;
        }
    }
    return size;
}

/// @brief Checks if the hash table is empty
/// @param ht hash table operated upon
bool ioopm_hash_table_is_empty(ioopm_hash_table_t *ht) {
    return ioopm_hash_table_size(ht) == 0;
}

/// @brief Clear all the entries in a hash table
/// @param ht hash table operated upon
void ioopm_hash_table_clear(ioopm_hash_table_t *ht) {
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            entry_t *next = entry->next;
            free(entry);          // Free the entry itself
            entry = next;
        }
        ht->buckets[i] = NULL; // Set bucket to NULL after clearing
    }
}

/// @brief return the keys for all entries in a hash map 
/// @param ht hash table operated upon
/// @return a list of keys for hash table ht
ioopm_list_t *ioopm_hash_table_keys(ioopm_hash_table_t *ht) {
    ioopm_list_t *keys = calloc(1, sizeof(ioopm_list_t)); 
    if (!keys){
        return NULL;
    }  
    
    keys->head = NULL;  
    keys->size = 0; 

    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            link_t *new_link = calloc(1, sizeof(link_t));
            if (!new_link) {
        
                while (keys-> head) {
                    link_t *temp = keys-> head;
                    keys->head = keys->head->next;
                    free(temp); 
                }
                free(keys); 
                return NULL;
            }  
            new_link->value = entry->key; 
            new_link->next = keys->head; 
            keys->head = new_link;      
            keys->size++;                

            entry = entry->next;  
        }
    }
    return keys;
}

/// @brief return the values for all entries in a hash map 
/// @param ht hash table operated upon
/// @return an array of values for hash table ht
/// @brief return the values for all entries in a hash map 
/// @param ht hash table operated upon
/// @return a linked list of values for hash table ht
ioopm_list_t *ioopm_hash_table_values(ioopm_hash_table_t *ht) {
    ioopm_list_t *values = calloc(1, sizeof(ioopm_list_t)); 
    if (!values) {
        return NULL; // Check for allocation failure
    }

    values->head = NULL;  
    values->size = 0; // Initialize the list size to 0

    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
        
            link_t *new_link = calloc(1, sizeof(link_t));
            if (!new_link) {

                while (values->head) {
                    link_t *temp = values->head;
                    values->head = values->head->next;
                    free(temp);
                }
                free(values);
                return NULL;
            }

            new_link->value = entry->value;

      
            new_link->next = values->head;
            values->head = new_link;

            values->size++; 
            entry = entry->next; 
        }
    }
    return values;
}

/// @brief return the values for all entries in a hash map 
/// @param ht hash table operated upon
/// @param key the key sought
/// @return the boolean value of the given key in the hash table
bool ioopm_hash_table_has_key(ioopm_hash_table_t *ht, elem_t key) {
    return ioopm_hash_table_lookup(ht, key) != NULL;
}

/// @brief check if a hash table has an entry with a given value
/// @param ht hash table operated upon
/// @param value the value sought
/// @return the boolean value of the given value in the hash table
bool ioopm_hash_table_has_value(ioopm_hash_table_t *ht, elem_t value) {
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            if (ht -> value_eq_fn(value, entry->value)) { // Compares the values
                return true;
            }
            entry = entry->next; 
        }
    }
    return false; // Value not found
}

/// @brief Check if a predicate is satisfied by all entries in a hash table
/// @param ht Hash table operated upon
/// @param pred The predicate function pointer
/// @param arg Extra argument to pass to the predicate
/// @return True if the predicate holds for all entries, otherwise false
bool ioopm_hash_table_all(ioopm_hash_table_t *ht, ioopm_predicate pred, void *arg) {
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            // Use the predicate on current key, value, and additional arg
            if (!pred(entry->key, entry->value, arg)) {
                return false; // Found a value that does not satisfy the predicate
            }
            entry = entry->next;
        }
    }
    return true; // All values satisfied the predicate
}

/// @brief Check if a predicate is satisfied by any entry in a hash table
/// @param ht Hash table operated upon
/// @param pred The predicate function pointer
/// @param arg Extra argument to pass to the predicate
/// @return True if any entry satisfies the predicate, otherwise false
bool ioopm_hash_table_any(ioopm_hash_table_t *ht, ioopm_predicate pred, void *arg) {
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            if (pred(entry->key, entry->value, arg)) {
                return true; // Found a satisfying value
            }
            entry = entry->next;
        }
    }
    return false; // No values satisfied the predicate
}


/// @brief Apply a function to all entries in a hash table
/// @param ht Hash table operated upon
/// @param apply_fun The function to be applied to all elements
/// @param arg Extra argument to pass to apply_fun
void ioopm_hash_table_apply_to_all(ioopm_hash_table_t *ht, ioopm_apply_function apply_fun, void *arg) {
    if (!ht || !apply_fun) {
        return;
    }
    
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry != NULL) {
            apply_fun(entry->key, entry->value, arg);
            entry = entry->next;
        }
    }
}
