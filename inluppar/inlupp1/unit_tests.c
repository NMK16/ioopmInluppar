#include <CUnit/Basic.h>
#include "hashtable.h"
#include <stdlib.h>
#include "hashtable.h"
#include "common.h"

#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }


// Kör koden i denna fil genom:
// gcc -Wall unit_tests.c hashtable.c -lcunit -o unit_tests
// ./unit_tests


int init_suite(void) {
	// Optional setup before tests, return 0 on success
	return 0;
}

int clean_suite(void) {
	// Optional cleanup after tests, return 0 on success
	return 0;
}


int ioopm_hash_function(elem_t key){
    return key.i % 17;
};

bool ioopm_eq_function(elem_t a, elem_t b){
    return a.i == b.i;
};

void test_create_destroy() {
	ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
	CU_ASSERT_PTR_NOT_NULL(ht);
	ioopm_hash_table_destroy(ht);
}

void test_insert_once() {

	ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);

	// Verify that our chosen key is not in h using lookup
	CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, int_elem(42)));

	// Insert a key-value pair
	ioopm_hash_table_insert(ht, int_elem(42), ptr_elem("Hello"));

	// Lookup the inserted value
	char *value = ioopm_hash_table_lookup(ht, int_elem(42));
	CU_ASSERT_STRING_EQUAL(value, "Hello");


  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    ioopm_hash_table_insert(ht, int_elem(i++), ptr_elem("Filler"));
}

  	// Tries looking up a non-existent key
  	char *missing = ioopm_hash_table_lookup(ht, int_elem(100));
  	CU_ASSERT_PTR_NULL(missing);

  	ioopm_hash_table_destroy(ht);
}

void test_insert_remove() {
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
  	CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, int_elem(42)));

  	// Insert a key-value pair
  	ioopm_hash_table_insert(ht, int_elem(42), ptr_elem("Hello"));

  	// Lookup the inserted value
  	char *value = ioopm_hash_table_lookup(ht, int_elem(42));
  	CU_ASSERT_STRING_EQUAL(value, "Hello");

  	// Try looking up a non-existent key
  	char *missing = ioopm_hash_table_lookup(ht, int_elem(100));
  	CU_ASSERT_PTR_NULL(missing);

  	// Remove the elements with the key 42
  	char *removed_value = ioopm_hash_table_remove(ht, int_elem(42));

  	// Verify the removed value
  	CU_ASSERT_STRING_EQUAL(removed_value, "Hello");
  	free(removed_value);

  	// Lookup the removed value
  	value = ioopm_hash_table_lookup(ht, int_elem(42));
  	CU_ASSERT_PTR_NULL(value);

  	ioopm_hash_table_destroy(ht);
}

void test_size() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
  	CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure that a hashtable is created

  	// Checking if the size of the empty hashtable is 0
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 0);

  	// Adding an entry to the originally empty hashtable
  	ioopm_hash_table_insert(ht, int_elem(16), ptr_elem("Cristiano"));

  	// Checking if the size increased to one
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 1);

  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    ioopm_hash_table_insert(ht, int_elem(i), ptr_elem("Filler"));
  }
  	// Checking if size increased to No_Buckets (16 + 1)
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), No_Buckets);

  	ioopm_hash_table_destroy(ht);
}

void test_is_empty_clear() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
  	CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure sthat a hashtable is created

  	// Checking that the empty hashtable function returns true for an empty hashtable
  	CU_ASSERT_EQUAL(ioopm_hash_table_is_empty(ht), true);

  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    	ioopm_hash_table_insert(ht, int_elem(i++), ptr_elem("Filler"));
}

  	// Removing all entries
  	ioopm_hash_table_clear(ht);

  	// Checking that hash table has been erased
  	CU_ASSERT_EQUAL(ioopm_hash_table_is_empty(ht), true);

  	ioopm_hash_table_destroy(ht);
}


void test_keys() {
    
    // Creates a new hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable is created

    int keys[5] = {3, 10, 42, 0, 99};
    bool found[5] = {false, false, false, false, false};
    int num_keys = 5;  // Number of keys

    // Inserts all keys into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), ptr_elem("Value not needed"));
    }

    // Get all the keys back from the hash table
    ioopm_list_t *hash_table_keys = ioopm_hash_table_keys(ht);
    CU_ASSERT_PTR_NOT_NULL(hash_table_keys);  // Ensure that we got keys back

    // Iterate over the returned keys from the hash table
    link_t *current = hash_table_keys->head;
    while (current != NULL) {
        bool key_found = false;
        for (int i = 0; i < num_keys; i++) {
            if ((current->value).i == keys[i]) {
                found[i] = true;  
                key_found = true;
                break;
            }
        }
        
        if (!key_found){
            CU_FAIL("Found a key/value that was never inserted");
        }

        current = current->next;  // Move to the next key in the list
    }

    // Assert that all keys were found
    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    // Cleanup
    free(hash_table_keys);
    ioopm_hash_table_destroy(ht);
}

// Test for checking if the hashtable has values
void test_values() {

    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht); 

    int keys[5] = {3, 10, 42, 0, 99};
    char *values[5] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    bool found[5] = {false, false, false, false, false};
    int num_keys = 5; 

    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), int_elem(values[i]));
    }


    ioopm_list_t *hash_table_keys = ioopm_hash_table_keys(ht);
    CU_ASSERT_PTR_NOT_NULL(hash_table_keys);   

    link_t *current = hash_table_keys->head;
    while (current != NULL) {
        bool key_found = false;
        for (int i = 0; i < num_keys; i++) {
            if ((current->value).i == keys[i]) {
                char *hash_table_value = ioopm_hash_table_lookup(ht, int_elem(keys[i]));
                CU_ASSERT_STRING_EQUAL(hash_table_value, values[i]);
                found[i] = true;
                key_found = true;
                break;
            }
        }

        if (!key_found){
            CU_FAIL("Found a key/value that was never inserted");
        }

        current = current->next;
    }

    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    // Cleanup
    free(hash_table_keys);
    ioopm_hash_table_destroy(ht);
}

// Test for checking if the hashtable has a key
void test_has_keys() {
    // Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

    // Asserts that it's false that an empty hashtable has a key
    CU_ASSERT_FALSE(ioopm_hash_table_has_key(ht, int_elem(1)));

    // Adds an entry to the hashtable
    ioopm_hash_table_insert(ht, int_elem(1), int_elem("Filler"));

    // Asserts that it's now true that the hashtable has a key
    CU_ASSERT_TRUE(ioopm_hash_table_has_key(ht, int_elem(1)));
    
    // Cleanup
    ioopm_hash_table_destroy(ht);
}

// Test for checking if the hashtable has a value
void test_has_values() {
    // Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

    // Asserts that it's false that an empty hashtable has a value
    CU_ASSERT_FALSE(ioopm_hash_table_has_value(ht, int_elem("Filler")));

    // Adds an entry to the hashtable
    ioopm_hash_table_insert(ht, 1, "Filler");

    // Lookup the inserted value
    char *value = ioopm_hash_table_lookup(ht, 1);
    CU_ASSERT_STRING_EQUAL(value, "Filler");
    
    // Asserts that it's now true that the hashtable has a value    
    CU_ASSERT_TRUE(ioopm_hash_table_has_value(ht, "Filler"));
    
    // Check if a different value is not found
    CU_ASSERT_FALSE(ioopm_hash_table_has_value(ht, "Not Filler"));

    // Cleanup
    ioopm_hash_table_destroy(ht);
}

static bool all_keys_bigger_than_10(int key, char *value, void *x) {
    return key >= 10;
}

void test_all() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures the hash table is created

    int keys[] = {11, 10, 42, 30, 99};
    char *values[] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    int num_keys = 5;

    // Insert entries into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);
    }

    // Test if all keys in the hash table are positive or zero
    CU_ASSERT_TRUE(ioopm_hash_table_all(ht, all_keys_bigger_than_10, NULL));  
    
	// Add a small key
    ioopm_hash_table_insert(ht, 3, "key smaller than 10");

    // Test again after adding a small key
    CU_ASSERT_FALSE(ioopm_hash_table_all(ht, all_keys_bigger_than_10, NULL));  

    ioopm_hash_table_destroy(ht);
}

// Helper function that checks if the key is equal to a given value
static bool key_is_equal(int key, char *value, void *x) {
    int *target_key = (int *)x;
    return key == *target_key;
}

void test_any() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures the hash table is created

    int keys[] = {3, 10, 42, 0, 99};
    char *values[] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    int num_keys = 5;

    // Insert entries into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);
    }

    // Test if any key in the hash table equals 42
    int target_key = 42;
    CU_ASSERT_TRUE(ioopm_hash_table_any(ht, key_is_equal, &target_key));

    // Test with a non existing key
    int non_existing_key = 100;
    CU_ASSERT_FALSE(ioopm_hash_table_any(ht, key_is_equal, &non_existing_key));

    ioopm_hash_table_destroy(ht);
}


void append_suffix(int key, char **value, void *arg) {
    if (value && *value) {
        char *suffix = (char *)arg; // Cast arg to char*
        size_t new_length = strlen(*value) + strlen(suffix) + 1; // +1 due to null terminator
        char *new_value = malloc(new_length); // Allocate memory for new value
        if (new_value) {
            strcpy(new_value, *value); // Copys suffix
            strcat(new_value, suffix); // Appends suffix
            free(*value); // Frees old value
            *value = new_value; // Updates the pointer
        }
    }
}

// Test function for ioopm_hash_table_apply_to_all
void test_apply() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(ioopm_hash_function, ioopm_eq_function, ioopm_eq_function);
    CU_ASSERT_PTR_NOT_NULL(ht); // Ensures a hash table is created

    // Create keys and values
    int keys[] = {1, 2, 3};
    char *values[] = {"value1", "value2", "value3"};
    const char *suffix = "_suffix";

    // Insert entries into the hash table
    for (int i = 0; i < 3; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);
    }

    // Apply the function to all entries in the hash table
    ioopm_hash_table_apply_to_all(ht, append_suffix, (void *)suffix);

    // Check if the values have been modified correctly
    for (int i = 0; i < 3; i++) {
        char expected_value[20]; // Make sure it has enough memory
        snprintf(expected_value, sizeof(expected_value), "value%d_suffix", i + 1);
        char *actual_value = ioopm_hash_table_lookup(ht, keys[i]); // Find the actual value
        CU_ASSERT_STRING_EQUAL(actual_value, expected_value); 
    }

    // Clean up
    ioopm_hash_table_destroy(ht);
}

int main() {
  if (CU_initialize_registry() != CUE_SUCCESS)
    return CU_get_error();

  CU_pSuite my_test_suite = CU_add_suite("My awesome test suite", init_suite, clean_suite);
  if (my_test_suite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Adding all our tests to the suite
  	CU_add_test(my_test_suite, "test_create_destroy", test_create_destroy);
  	CU_add_test(my_test_suite, "test_insert_lookup", test_insert_once);
  	CU_add_test(my_test_suite, "test_insert_remove", test_insert_remove);
  	CU_add_test(my_test_suite, "test_size", test_size);
  	CU_add_test(my_test_suite, "test_is_empty_clear", test_is_empty_clear);
  	CU_add_test(my_test_suite, "test_keys", test_keys);
  	CU_add_test(my_test_suite, "test_values", test_values);
	CU_add_test(my_test_suite, "test_has_key", test_has_keys);
	CU_add_test(my_test_suite, "test_has_val", test_has_values);
	CU_add_test(my_test_suite, "test_all", test_all);
	CU_add_test(my_test_suite, "test_any", test_any);
	CU_add_test(my_test_suite, "test_apply", test_apply);

	

  	// Set the running mode to verbose for detailed output
  	CU_basic_set_mode(CU_BRM_VERBOSE);

  	// Run all the tests
  	CU_basic_run_tests();

  	// Tear down CUnit before exiting
  	CU_cleanup_registry();
  	return CU_get_error();
}
