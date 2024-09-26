#include <stdlib.h>
#include "hashtable.h"
#include <string.h>
#define No_Buckets 17

typedef struct entry {
    int key;          // Holds the key
    char *value;      // Holds the value
    struct entry *next; // Points to the next entry (possibly NULL)
} entry_t;

typedef struct hash_table {
    entry_t *buckets[No_Buckets]; // Fixed number of buckets
} ioopm_hash_table_t;

/// @brief Create a new empty hash table
/// @return Pointer to the created hash table
ioopm_hash_table_t *ioopm_hash_table_create() {
  /// Allocate memory for the hash table and initialize buckets to NULL
  ioopm_hash_table_t *result = calloc(1, sizeof(ioopm_hash_table_t));
  return result;
}

/// @brief Destroy the hash table and free the allocated memory
/// @param ht the hash table to destroy
void ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
  ioopm_hash_table_clear(ht); // Clear all entries first
  free(ht); // Free the hash table itself
}

static int hash_function(int key) {
  return key % No_Buckets;
}

static entry_t *entry_create(int key, char *value, entry_t *next_value) {
    // Allocate memory for the new entry
    entry_t *new_entry = calloc(1, sizeof(entry_t));

    if (new_entry == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Initialize the new entry
    new_entry->key = key;
    new_entry->value = strdup(value);  // Make a copy of the value string
    new_entry->next = next_value;      // Set the next entry pointer

    return new_entry;
}

// Helper function for insert function
entry_t *find_previous_entry_for_key(entry_t **bucket_head, int key) {
    entry_t *current = *bucket_head;
    entry_t *prev = NULL;

    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    return prev; // Return the previous entry (or return NULL if the bucket is empty)
}

/// @brief Inserting entry into the hash table 
/// @param ht the hash table being used
/// @param key the key being inserted
/// @param value the value being inserted
void ioopm_hash_table_insert(ioopm_hash_table_t *ht, int key, char *value)
{
	/// Calculate the bucket for the entry
	int bucket = hash_function(key);
	/// Search for an existing entry for a key
	entry_t *entry = find_previous_entry_for_key(&ht->buckets[bucket], key);
	entry_t *next = entry ? entry->next : ht->buckets[bucket];

	/// Check if the next entry should be updated or not
	if (next != NULL && next->key == key)
    {
    	free(next->value);  // Free the old value
    	next->value = strdup(value); // Replace with a new value
    }
  	else
    {
    	entry_t *new_entry = entry_create(key, value, next);
    	if (entry) {
        	entry->next = new_entry;
      	}
     	else {
        	ht->buckets[bucket] = new_entry;
      	}
    }
}

/// Helper function for recursive lookup
static void *recursive_lookup(entry_t *searching_entry, int key) {
    if (searching_entry == NULL) {
        return NULL; // Base case: key not found
    }
    if (searching_entry->key == key) {
    	return searching_entry->value; // Key found, return the value
    }
    
	return recursive_lookup(searching_entry->next, key); // Recursive call
}

/// @brief Lookup the value for a key in the hash table
/// @param ht the hash table being used
/// @param key the key to lookup
/// @return the value mapped to by key, or NULL if not found
char *ioopm_hash_table_lookup(ioopm_hash_table_t *ht, int key) {
    int bucket = hash_function(key);
    return recursive_lookup(ht->buckets[bucket], key);
}

/// @brief Remove any mapping from key to a value
/// @param ht hash table operated upon
/// @param key key to remove
/// @return the value mapped to by key
char *ioopm_hash_table_remove(ioopm_hash_table_t *ht, int key) {
    int bucket = hash_function(key);
    entry_t *prev_entry = find_previous_entry_for_key(&ht->buckets[bucket], key);
    entry_t *entry_to_remove = prev_entry ? prev_entry->next : ht->buckets[bucket];

    if (!entry_to_remove || entry_to_remove->key != key) 
        return NULL;

    char *removed_val = strdup(entry_to_remove->value); // Copy the value to return it
    if (prev_entry) prev_entry->next = entry_to_remove->next;
    else ht->buckets[bucket] = entry_to_remove->next;

    free(entry_to_remove->value); // Free the value
    free(entry_to_remove);        // Free the entry itself
    return removed_val;
}

/// @brief Returns the number of key => value entries in the hash table
/// @param ht hash table operated upon
/// @return the number of key => value entries in the hash table
int ioopm_hash_table_size(ioopm_hash_table_t *ht) {
    int size = 0;
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        while (entry)
		{
			size++;
        	entry = entry->next;
		}	
    }
    return size;
}

/// @brief Checks if the hash table is empty
/// @param ht hash table operated upon
/// @return true if size == 0, else false
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
            free(entry->value); 
            free(entry);        
            entry = next;
        }
        ht->buckets[i] = NULL; // Set bucket to NULL after clearing the memory 
    }
}

/// @brief return the keys for all entries in a hash map (in no particular order, but same as ioopm_hash_table_values)
/// @param h hash table operated upon
/// @return an array of keys for hash table h
int *ioopm_hash_table_keys(ioopm_hash_table_t *ht) {
    int size = ioopm_hash_table_size(ht);
    
    int *keys = calloc(size, sizeof(ioopm_hash_table_t));;
    int counter = 0;
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        if (entry != NULL){
            keys[counter] = entry->key;
            entry = entry->next;
            counter++;
        }
    }
    return keys;
}


/// @brief return the values for all entries in a hash map (in no particular order, but same as ioopm_hash_table_keys)
/// @param h hash table operated upon
/// @return an array of values for hash table h
char **ioopm_hash_table_values(ioopm_hash_table_t *ht){
    int size = ioopm_hash_table_size(ht);
    
    char **values = calloc(size, sizeof(ioopm_hash_table_t));
    int counter = 0;
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        if (entry != NULL){
            values[counter] = entry->value;
            entry = entry->next;
            counter++;
        }
    }
    return values;
}

bool ioopm_hash_table_has_key(ioopm_hash_table_t *ht, int key) {
    return ioopm_hash_table_lookup(ht, key) != NULL;
}

// bool ioopm_hash_table_has_key2(ioopm_hash_table_t *ht, int key){
//     bool found = false;
//     int *allKeys = ioopm_hash_table_keys(ht);
//     for (int i = 0; i < 5; i++){
//         if (key == allKeys[i]){
//             found = true;
//         }
//     }

//     return found;
    
// }


/// @brief check if a hash table has an entry with a given value
/// @param h hash table operated upon
/// @param value the value sought
bool ioopm_hash_table_has_value(ioopm_hash_table_t *ht, char *value){
    for (int i = 0; i < No_Buckets; i++) {
        entry_t *entry = ht->buckets[i];
        if (entry != NULL){
            char *entry_val = ht->buckets[i]->value;
            if(strcmp(value, entry_val) == 0){ //strcmp returns 0 if strings are equal
                return true;
            }
        }
    }
    return false;
}    


// /// @brief Check if a predicate is satisfied by all entries in a hash table
// /// @param ht Hash table operated upon
// /// @param pred The predicate function pointer
// /// @param arg Extra argument to pass to the predicate
// /// @return True if the predicate holds for all entries, otherwise false
// bool ioopm_hash_table_all(ioopm_hash_table_t *ht, ioopm_predicate *pred, void *arg) {
//     for (int i = 0; i < No_Buckets; i++) {
//         entry_t *entry = ht->buckets[i];
        
//         // Goes through all entries in the hashtable
//         while (entry != NULL) {
//             if (!pred(entry->key, entry->value, arg)) {
//                 return false;  // Predicate was false for the current entry
//             }
//             entry = entry->next; //Go to the next entry in the hashtable
//         }
//     }
//     return true;  // All the entries satisfied the predicate
// }

// /// @brief check if a predicate is satisfied by any entry in a hash table
// /// @param ht hash table operated upon
// /// @param pred the predicate
// /// @param arg extra argument to pred
// bool ioopm_hash_table_any(ioopm_hash_table_t *ht, ioopm_predicate *pred, void *arg){
//     for (int i = 0; i < No_Buckets; i++) {
//         entry_t *entry = ht->buckets[i];
        
//         // Goes through all entries in the hashtable
//         while (entry != NULL) {
//             if (pred(entry->key, entry->value, arg)) {
//                 return true;  // Predicate proved false for an entry
//             }
//             entry = entry->next;  // Go to the next entry in the hashtable
//         }
    
//     return false;  // None of the entries satisfied the predicate
//     }
// }

// / @brief apply a function to all entries in a hash table
// / @param h hash table operated upon
// / @param apply_fun the function to be applied to all elements
// / @param arg extra argument to apply_fun
// void ioopm_hash_table_apply_to_all(ioopm_hash_table_t *ht, ioopm_apply_function *apply_fun, void *arg){
//     entry_t *entry = ht->buckets[No_Buckets];
//     for (int i = 0; i < No_Buckets; i++) {
//         entry = ht->buckets[i];
        
//         // Goes through all entries in the hashtable
//         while (entry != NULL) {
//             apply_fun(entry->key, entry->value, arg); //Apply function to the current entry
        
//             entry = entry->next; // Go to the next entry in the hashtable
        
//         }
//     }
//     return entry;  // None of the entries satisfied the predicate   

// }