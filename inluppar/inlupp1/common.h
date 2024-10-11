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
typedef bool (ioopm_eq_function)(elem_t a, elem_t b);
typedef int (ioopm_hash_function)(elem_t element);

// Hash table structure
typedef struct hash_table {
    entry_t *buckets[No_Buckets]; 
    size_t size;
    ioopm_hash_function *hash_fn;
    ioopm_eq_function *key_eq_fn; 
    ioopm_eq_function *value_eq_fn; 
} ioopm_hash_table_t;

// Linked list structure
typedef struct link {
    elem_t value;
    struct link *next;
} link_t;

typedef struct list {
    link_t *head;
    size_t size;
    ioopm_eq_function *eq_fn;  // No need for a pointer here, already a function pointer
} ioopm_list_t;
