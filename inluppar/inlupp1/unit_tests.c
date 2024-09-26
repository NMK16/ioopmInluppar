#include <CUnit/Basic.h>
#include "hashtable.h"
#include <stdlib.h>
#define No_Buckets 17

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

void test_create_destroy() {
	ioopm_hash_table_t *ht = ioopm_hash_table_create();
	CU_ASSERT_PTR_NOT_NULL(ht);
	ioopm_hash_table_destroy(ht);
}

void test_insert_once() {
	ioopm_hash_table_t *ht = ioopm_hash_table_create();

	// Verify that our chosen key is not in h using lookup
	CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, 42));

	// Insert a key-value pair
	ioopm_hash_table_insert(ht, 42, "Hello");

	// Lookup the inserted value
	char *value = ioopm_hash_table_lookup(ht, 42);
	CU_ASSERT_STRING_EQUAL(value, "Hello");


  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    ioopm_hash_table_insert(ht, i % 17, "Filler");
}

  	// Try looking up a non-existent key
  	char *missing = ioopm_hash_table_lookup(ht, 100);
  	CU_ASSERT_PTR_NULL(missing);

  	ioopm_hash_table_destroy(ht);
}

void test_insert_remove() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create();
  	CU_ASSERT_PTR_NULL(ioopm_hash_table_lookup(ht, 42));

  	// Insert a key-value pair
  	ioopm_hash_table_insert(ht, 42, "Hello");

  	// Lookup the inserted value
  	char *value = ioopm_hash_table_lookup(ht, 42);
  	CU_ASSERT_STRING_EQUAL(value, "Hello");

  	// Try looking up a non-existent key
  	char *missing = ioopm_hash_table_lookup(ht, 100);
  	CU_ASSERT_PTR_NULL(missing);

  	// Remove the elements with the key 42
  	char *removed_value = ioopm_hash_table_remove(ht, 42);

  	// Verify the removed value
  	CU_ASSERT_STRING_EQUAL(removed_value, "Hello");
  	free(removed_value);

  	// Lookup the removed value
  	value = ioopm_hash_table_lookup(ht, 42);
  	CU_ASSERT_PTR_NULL(value);

  	ioopm_hash_table_destroy(ht);
}

void test_size() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create();
  	CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure that a hashtable is created

  	// Checking if the size of the empty hashtable is 0
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 0);

  	// Adding an entry to the originally empty hashtable
  	ioopm_hash_table_insert(ht, 16, "Cristiano");

  	// Checking if the size increased to one
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), 1);

  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    ioopm_hash_table_insert(ht, i, "Filler");
  }
  	// Checking if size increased to No_Buckets (16 + 1)
  	CU_ASSERT_EQUAL(ioopm_hash_table_size(ht), No_Buckets);

  	ioopm_hash_table_destroy(ht);
}

void test_is_empty_clear() {
  	ioopm_hash_table_t *ht = ioopm_hash_table_create();
  	CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure that a hashtable is created

  	// Checking that the empty hashtable function returns true for an empty hashtable
  	CU_ASSERT_EQUAL(ioopm_hash_table_is_empty(ht), true);

  	// Inserting more entries
  	for (int i = 0; i < No_Buckets; i++) {
    	ioopm_hash_table_insert(ht, i % 17, "Filler");
}

  	// Removing all entries
  	ioopm_hash_table_clear(ht);

  	// Checking that hash table has been erased
  	CU_ASSERT_EQUAL(ioopm_hash_table_is_empty(ht), true);

  	ioopm_hash_table_destroy(ht);
}


void test_keys() {
    // Creates a new hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensure sthat a hashtable is created


    int keys[5] = {3, 10, 42, 0, 99};
    bool found[5] = {false, false, false, false, false};
    int num_keys = 5;  // Number of keys

    // Insert all keys into the hash table ( the values are not important for this test)
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], "Value not needed");
    }

    // Get all the keys back from the hash table
    int *hash_table_keys = ioopm_hash_table_keys(ht);
    CU_ASSERT_PTR_NOT_NULL(hash_table_keys);  // Ensures that we got keys back

    // Iterate over the returned keys from the hash table
    for (int i = 0; i < num_keys; i++) {
        bool key_found = false;
        for (int j = 0; j < num_keys; j++) {
            if (hash_table_keys[i] == keys[j]) {
                found[j] = true;  // Mark the index in 'found' as true
                key_found = true;
                break;
            }
        }
        if (!key_found) {
            CU_FAIL("Found a key that was never inserted!");
        }
    }

    // Asserts that all elements are found
    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    // Cleanup
    free(hash_table_keys);
    ioopm_hash_table_destroy(ht);
}

void test_values() {
    // Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

    int keys[5] = {3, 10, 42, 0, 99};
    char *values[5] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
    bool found[5] = {false, false, false, false, false};
    int num_keys = 5;  // Number of keys

    // Adding entries to the hashtable with the keys-value pairs from above
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);  
    }

    // Get all keys and values from the hashtable
    int *hash_table_keys = ioopm_hash_table_keys(ht);
    char **hash_table_values = ioopm_hash_table_values(ht);  
    CU_ASSERT_PTR_NOT_NULL(hash_table_keys);   // Ensures we got keys from the hashtable
    CU_ASSERT_PTR_NOT_NULL(hash_table_values); // Ensures we got values from the hashtable

    // Goes through each key in the hashtables
    for (int i = 0; i < num_keys; i++) {
        bool key_found = false;
        for (int j = 0; j < num_keys; j++) {
            if (hash_table_keys[i] == keys[j]) {
                // Checks that values in the hashtables are the same as the given array of values
                CU_ASSERT_STRING_EQUAL(hash_table_values[i], values[j]);
                found[j] = true;  
                key_found = true;
                break;
            }
        }
        if (!key_found) {
            CU_FAIL("Found a key/value that was never inserted!");
        }
    }

    // Asserts that all elements are found
    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    // Cleanup
    free(hash_table_keys);
    free(hash_table_values); 
    ioopm_hash_table_destroy(ht);
}

void test_has_keys(){
	
	// Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created
	
	// Asserts that it's false that an empty hashtable hashtable has a key
	CU_ASSERT_FALSE(ioopm_hash_table_has_key(ht, 1));

	// Adds an entry to the hashtable
	ioopm_hash_table_insert(ht, 1, "Filler");

	// Asserts that it's now true that the hashtable has a key
	CU_ASSERT_TRUE(ioopm_hash_table_has_key(ht, 1));
	
	// Cleanup
	ioopm_hash_table_destroy(ht);
}

void test_has_values(){

	// Create an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created
	
	// Asserts that it's false that an empty hashtable hashtable has a value
	CU_ASSERT_FALSE(ioopm_hash_table_has_value(ht, "Filler"));

	// Adds an entry to the hashtable
	ioopm_hash_table_insert(ht, 1, "Filler");

	// Lookup the inserted value
	char *value = ioopm_hash_table_lookup(ht, 1);
	CU_ASSERT_STRING_EQUAL(value, "Filler");
	
	// Asserts that it's now true that the hashtable has a value	
	CU_ASSERT_TRUE(ioopm_hash_table_has_value(ht, "Filler"));
	
	// Cleanup
	ioopm_hash_table_destroy(ht);
}

// Helper function used for testing function

// static bool key_equiv(int key, char *value_ignored, void *x)
// {
//   int *other_key_ptr = x;
//   int other_key = *other_key_ptr;
//   return key == other_key;
// }
bool predFun(int key, char *value, void *arg){
	return true;
}
void test_all(){
	// Creates an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

	// Creates keys and values
	int keys[5] = {3, 10, 42, 0, 99};
    char *values[5] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
	int num_keys = 5;

	// Adding entries to the hashtable with the keys-value pairs from above
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);  
    }
	CU_ASSERT_TRUE(ioopm_hash_table_all(ht, predFun, &num_keys));
	// Asserts that it's true that all keys in the hashtable has a 

	// Cleanup
	ioopm_hash_table_destroy(ht);
}

void test_any(){
	// Creates an empty hashtable
    ioopm_hash_table_t *ht = ioopm_hash_table_create();
    CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

	// Creates keys and values
	int keys[5] = {3, 10, 42, 0, 99};
    char *values[5] = {"three", "ten", "fortytwo", "zero", "ninetynine"};
	int num_keys = 5;

	// Adding entries to the hashtable with the keys-value pairs from above
    for (int i = 0; i < num_keys; i++) {
        ioopm_hash_table_insert(ht, keys[i], values[i]);  
    }


	// Asserts that it's true that all keys in the hashtable has a 
	CU_ASSERT_EQUAL(ioopm_hash_table_has_key(ht, 3), ioopm_hash_table_has_key2(ht, 3));


	// Cleanup
	ioopm_hash_table_destroy(ht);
}

// void test_apply_all(){
// 	// Create an empty hashtable
//     ioopm_hash_table_t *ht = ioopm_hash_table_create();
//     CU_ASSERT_PTR_NOT_NULL(ht);  // Ensures that a hashtable was created

// }


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

	

  	// Set the running mode to verbose for detailed output
  	CU_basic_set_mode(CU_BRM_VERBOSE);

  	// Run all the tests
  	CU_basic_run_tests();

  	// Tear down CUnit before exiting
  	CU_cleanup_registry();
  	return CU_get_error();
}
