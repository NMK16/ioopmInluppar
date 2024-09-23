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

    // Get all the keys from the hash table
    int *hash_table_keys = ioopm_hash_table_keys(ht);
    CU_ASSERT_PTR_NOT_NULL(hash_table_keys);  // Ensure that we got keys back

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

    // Assert that all elements in 'found' are now true
    for (int i = 0; i < num_keys; i++) {
        CU_ASSERT_TRUE(found[i]);
    }

    // Cleanup
    free(hash_table_keys);
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

  // Set the running mode to verbose for detailed output
  CU_basic_set_mode(CU_BRM_VERBOSE);

  // Run all the tests
  CU_basic_run_tests();

  // Tear down CUnit before exiting
  CU_cleanup_registry();
  return CU_get_error();
}
