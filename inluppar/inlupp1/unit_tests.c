#include <CUnit/Basic.h>
#include "hashtable.h"
#include <stdlib.h>

int init_suite(void) {
  // Change this function if you want to do something *before* you
  // run a test suite
  return 0;
}

int clean_suite(void) {
  // Change this function if you want to do something *after* you
  // run a test suite
  return 0;
}

void test_create_destroy() {
   ioopm_hash_table_t *ht = ioopm_hash_table_create();
   CU_ASSERT_PTR_NOT_NULL(ht);
   ioopm_hash_table_destroy(ht);
}

void test_insert_once() {
  ioopm_hash_table_t *ht = ioopm_hash_table_create();
  
  //Verify that key k is not in h using lookup
  ioopm_hash_table_lookup(ht, 42);

  // Insert a key-value pair
  ioopm_hash_table_insert(ht, 42, "Hello");
  
  // Lookup the inserted value
  char *value = ioopm_hash_table_lookup(ht, 42);
  CU_ASSERT_STRING_EQUAL(value, "Hello");

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
  char* removed_value = ioopm_hash_table_remove(ht, 42);
  
  // Verify the removed value
  CU_ASSERT_STRING_EQUAL(removed_value, "Hello");
  free(removed_value);
  
  // Lookup the removed value
  value = ioopm_hash_table_lookup(ht, 42);
  CU_ASSERT_PTR_NULL(value);

  ioopm_hash_table_destroy(ht);
}

int main() {
  // First we try to set up CUnit, and exit if we fail
  if (CU_initialize_registry() != CUE_SUCCESS)
    return CU_get_error();

  // We then create an empty test suite and specify the name and
  // the init and cleanup functions
  CU_pSuite my_test_suite = CU_add_suite("My awesome test suite", init_suite, clean_suite);
  if (my_test_suite == NULL) {
      // If the test suite could not be added, tear down CUnit and exit
      CU_cleanup_registry();
      return CU_get_error();
  }

  // This is where we add the test functions to our test suite.
  // For each call to CU_add_test we specify the test suite, the
  // name or description of the test, and the function that runs
  // the test in question. If you want to add another test, just
  // copy a line below and change the information
  // Adding the test to the test suite
  if (CU_add_test(my_test_suite, "test_create_destroy", test_create_destroy) == NULL) {
    // If adding the test fails, tear down CUnit and exit
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(my_test_suite, "test_insert_lookup", test_insert_once) == NULL) {
    // If adding the test fails, tear down CUnit and exit
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (CU_add_test(my_test_suite, "test_insert_remove", test_insert_remove) == NULL) {
    // If adding the test fails, tear down CUnit and exit
    CU_cleanup_registry();
    return CU_get_error();
  }  
    {
      // If adding any of the tests fails, we tear down CUnit and exit
      CU_cleanup_registry();
      return CU_get_error();
    }

  // Set the running mode. Use CU_BRM_VERBOSE for maximum output.
  // Use CU_BRM_NORMAL to only print errors and a summary
  CU_basic_set_mode(CU_BRM_NORMAL);

  // This is where the tests are actually run!
  CU_basic_run_tests();

  // Tear down CUnit before exiting
  CU_cleanup_registry();
  return CU_get_error();
}
