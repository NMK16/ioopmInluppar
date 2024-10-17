#include <CUnit/Basic.h>
#include "hashtable.h"
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"
#include "string.h"

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

int hash_fn(elem_t key){
    return key.i % 17;
}

bool eq_fn(elem_t a, elem_t b){
    return a.i == b.i;
}

bool eq_fn_char(elem_t a, elem_t b){
    return a.p == b.p;
}

int elem_int(elem_t element){
    return element.i;
}

char *elem_char(elem_t element){
    return element.p;
}

void test_create_destroy() {
	ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
	CU_ASSERT_PTR_NOT_NULL(ht);
	ioopm_hash_table_destroy(ht);
}

void test_insert_once() {

	ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);

	// Verify that our chosen key is not in h using lookup
	CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, int_elem(42)));

	// Insert a key-value pair
	ioopm_hash_table_insert(ht, int_elem(42), ptr_elem("Hello"));

	// Lookup the inserted value
	elem_t *value = ioopm_hash_table_lookup(ht, int_elem(42));
	CU_ASSERT_STRING_EQUAL(value -> p, "Hello");


  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    ioopm_hash_table_insert(ht, int_elem(i++), ptr_elem("Filler"));
    }

  	// Tries looking up a non-existent key
  	elem_t *missing = ioopm_hash_table_lookup(ht, int_elem(100));
  	CU_ASSERT_PTR_NULL(missing);

  	ioopm_hash_table_destroy(ht);
}

void test_insert_remove() {
    ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, int_elem(42)));

    // Insert a key-value pair
    ioopm_hash_table_insert(ht, int_elem(42), ptr_elem("Hello"));


    elem_t *value = ioopm_hash_table_lookup(ht, int_elem(42));
    CU_ASSERT_STRING_EQUAL(value->p, "Hello");

    // Remove the element with the key 42
    elem_t *removed_value = ioopm_hash_table_remove(ht, int_elem(42));

    // Verify the removed value
    CU_ASSERT_STRING_EQUAL(removed_value->p, "Hello");  // Compare strings correctly

    // Lookup the removed value
    value = ioopm_hash_table_lookup(ht, int_elem(42));
    CU_ASSERT_PTR_NULL(value);
    free(removed_value);
    ioopm_hash_table_destroy(ht);
}


void test_size() {
    ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure that a hashtable is created

    // Checking if the size of the empty hashtable is 0
    CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 0);

    // Adding an entry to the originally empty hashtable
    ioopm_hash_table_insert(ht, int_elem(16), ptr_elem("Cristiano"));

    // Checking if the size increased to one
    CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 1);

    // Inserting more entries
    for (int i = 1; i < No_Buckets; i++) {
        ioopm_hash_table_insert(ht, int_elem(i), ptr_elem("Filler"));
    }

    // Checking if size increased to Number of Buckets
    CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), (size_t) No_Buckets);

    ioopm_hash_table_destroy(ht);
}


void test_is_empty_clear() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create(*hash_fn, *eq_fn, *eq_fn);
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

void free_linked_list(ioopm_list_t *list) {
    link_t *current = list->head;
    while (current != NULL) {
        link_t *next = current->next;
        free(current); 
        current = next;
    }
    free(list); 
}

void test_keys() {
    
    // Creates a new hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(*hash_fn, *eq_fn, *eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable is created

    int keys[] = {3, 10, 42, 0, 99};
    bool found[] = {false, false, false, false, false};
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
    free_linked_list(hash_table_keys);
    ioopm_hash_table_destroy(ht);
}

// Test for checking if the hashtable has values
void test_values() {
    ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);

    int keys[] = {3, 10, 42, 0, 99};
    char *values[] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    bool found[5] = {false, false, false, false, false};
    int num_keys = 5;

    // Insert key-value pairs into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), ptr_elem(values[i]));
    }

    // Get the values from the hash table
    ioopm_list_t *hash_table_values = ioopm_hash_table_values(ht);
    CU_ASSERT_PTR_NOT_NULL(hash_table_values);

    // Traverse the values and verify
    link_t *current = hash_table_values->head;
    while (current != NULL) {
        bool value_found = false;
        for (int i = 0; i < num_keys; i++) {
            if (strcmp(current->value.p, values[i]) == 0) {
                found[i] = true;
                value_found = true;
                break;
            }
        }
        if (!value_found) {
            CU_FAIL("Found a value that was never inserted");
        }
      
        current = current->next;
    }

    // Ensure that all values were found
    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    free_linked_list(hash_table_values);  // Free the linked list
    ioopm_hash_table_destroy(ht);         // Destroy the hash table
}




// Test for checking if the hashtable has a key
void test_has_keys() {
    // Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

    // Asserts that it's false that an empty hashtable has a key
    CU_ASSERT_FALSE(ioopm_hash_table_has_key(ht, int_elem(1)));

    // Adds an entry to the hashtable
    ioopm_hash_table_insert(ht, int_elem(1), ptr_elem("Filler"));

    // Asserts that it's now true that the hashtable has a key
    CU_ASSERT_TRUE(ioopm_hash_table_has_key(ht, int_elem(1)));
    
    // Cleanup
    ioopm_hash_table_destroy(ht);
}

// Test for checking if the hashtable has a value
void test_has_values() {
    // Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn_char);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

    // Asserts that it's false that an empty hashtable has a value
    CU_ASSERT_FALSE(ioopm_hash_table_has_value(ht, ptr_elem("Filler")));

    // Adds an entry to the hashtable
    ioopm_hash_table_insert(ht, int_elem(1), ptr_elem("Filler"));

    // Lookup the inserted value
    elem_t value = *ioopm_hash_table_lookup(ht, int_elem(1));

    CU_ASSERT_STRING_EQUAL(value.p, "Filler");
    
    // Asserts that it's now true that the hashtable has a value  

    CU_ASSERT_TRUE(ioopm_hash_table_has_value(ht, value));
    
    // Check if a different value is not found
    CU_ASSERT_FALSE(ioopm_hash_table_has_value(ht, ptr_elem("Not Filler")));

    // Cleanup
    ioopm_hash_table_destroy(ht);
}

static bool all_keys_bigger_than_10(elem_t key, elem_t value, void *x) {
    return key.i >= 10;
}

void test_all() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(*hash_fn, *eq_fn, *eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures the hash table is created

    int keys[] = {11, 10, 42, 30, 99};
    char *values[] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    int num_keys = 5;

    // Insert entries into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), ptr_elem(values[i]));
    }

    // Test if all keys in the hash table are positive or zero
    CU_ASSERT_TRUE(ioopm_hash_table_all(ht, all_keys_bigger_than_10, NULL));  
    
	// Add a small key
    ioopm_hash_table_insert(ht, int_elem(3), ptr_elem("key smaller than 10"));

    // Test again after adding a small key
    CU_ASSERT_FALSE(ioopm_hash_table_all(ht, all_keys_bigger_than_10, NULL));  

    ioopm_hash_table_destroy(ht);
}

// Helper function that checks if the key is equal to a given value
static bool key_is_equal(elem_t key, elem_t value, void *x) {
    int *target_key = (int *)x;
    return key.i == *target_key;
}

void test_any() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(*hash_fn, *eq_fn, *eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures the hash table is created

    int keys[] = {3, 10, 42, 0, 99};
    char *values[] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    int num_keys = 5;

    // Insert entries into the hash table
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), ptr_elem(values[i]));
    }

    // Test if any key in the hash table equals 42
    int target_key = 42;
    CU_ASSERT_TRUE(ioopm_hash_table_any(ht, key_is_equal, &target_key));

    // Test with a non existing key
    int non_existing_key = 100;
    CU_ASSERT_FALSE(ioopm_hash_table_any(ht, key_is_equal, &non_existing_key));

    ioopm_hash_table_destroy(ht);
}

elem_t square_int_val(elem_t key, elem_t value, void *arg){
    value.i = value.i * value.i;
    return value;
}

// elem_t *append_suffix(elem_t key, elem_t value, void *arg) {
//     char *suffix = (char *)arg;  // Cast arg to char*
//     size_t original_length = strlen((char *)value.p);
//     size_t new_length = original_length + strlen(suffix) + 1;  // +1 for null terminator
    
//     // Allocate memory for the new value
//     char *new_value = malloc(new_length);
//     if (new_value) {
//         // Copy the original value and append the suffix
//         strcpy(new_value, (char *)value.p);  // Fix missing closing parenthesis
//         strcat(new_value, suffix);
        
//         // Free the old value's memory and update it with the new value
//         free(value.p);
//         value.p = new_value;  // Update the pointer in elem_t to the new value
//     }

//     return value;  // Return the updated value
// }


// Test function for ioopm_hash_table_apply_to_all
void test_apply() {
    // Creates a new hash table
    ioopm_hash_table_t *ht = ioopm_hash_table_create(*hash_fn, *eq_fn, *eq_fn);
    CU_ASSERT_PTR_NOT_NULL(ht); // Ensures a hash table is created

    // Create keys and values
    int keys[3] = {1, 2, 3};
    int values[3] = {1, 2, 3};

    // Insert entries into the hash table using elem_t
    for (int i = 0; i < 3; i++) {
        ioopm_hash_table_insert(ht, int_elem(keys[i]), int_elem(values[i]));
    }

    // Apply the square_int_val function to all entries in the hash table
    ioopm_hash_table_apply_to_all(ht, square_int_val, NULL);  // No extra argument needed

    // Check if the values have been squared correctly
    int expected_values[3] = {1, 4, 9};  // The squared values

    for (int i = 0; i < 3; i++) {
        elem_t *actual_value = ioopm_hash_table_lookup(ht, int_elem(keys[i]));  // Find the actual value
        CU_ASSERT_PTR_NOT_NULL(actual_value);  // Ensure the value was found
        CU_ASSERT_EQUAL(actual_value->i, expected_values[i]);  // Compare the squared value with expected
    }

    // Clean up
    ioopm_hash_table_destroy(ht);  // Ensure hash table is properly destroyed
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
  	CU_add_test(my_test_suite, "test_insert_once", test_insert_once);
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
