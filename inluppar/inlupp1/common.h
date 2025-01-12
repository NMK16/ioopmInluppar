#pragma once
#define No_Buckets 17
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef union elem elem_t;

union elem
{
    int i;
    unsigned int u;
    bool b;
    float f;
    void *p;
};

// Entry for each bucket
typedef struct entry {
    elem_t key;                
    elem_t value;         
    struct entry *next;    
} entry_t;

// Function pointers for hash and equality functions
typedef int ioopm_hash_function(elem_t key);
typedef bool ioopm_equal_function(elem_t a, elem_t b);


// Hash table structure
typedef struct hash_table {
    entry_t **buckets; 
    size_t size;
    ioopm_hash_function *hash_fn;
    size_t capacity;            // Number of buckets
    float load_factor;          // Load factor threshold
    ioopm_equal_function *key_eq_fn; 
    ioopm_equal_function *value_eq_fn; 
} ioopm_hash_table_t;

/// @brief Create a new hash table
/// @param hash_fn hash function
/// @param key_eq_fn function that checks if keys are equal
/// @param value_eq_fn function that checks if keys are equal
/// @return A new empty hash table
ioopm_hash_table_t *ioopm_hash_table_create(ioopm_hash_function *hash_fn, ioopm_equal_function key_eq_fn, ioopm_equal_function value_eq_fn);

// Linked list structure
typedef struct link {
    elem_t value;
    struct link *next;
} link_t;

typedef struct list {
    link_t *head;
    size_t size;
    ioopm_equal_function *eq_fn;  
} ioopm_list_t;
