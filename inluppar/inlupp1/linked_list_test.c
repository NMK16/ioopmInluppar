#include <CUnit/Basic.h>
#include "linked_list.h"
#include <assert.h>
#include <stdlib.h>
#include "common.h"

#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

// Kör koden i denna fil genom:
// gcc -Wall linked_list_test.c linked_list.c -lcunit -o linked_list_test
// ./linked_list_test

//För att köra valgrind
//gcc -g -Wall linked_list_test.c linked_list.c -lcunit -o linked_list_test
//valgrind --leak-check=full --track-origins=yes ./linked_list_test





// Optional setup before tests
int init_suite(void) {
    return 0;
}

// Optional cleanup after tests
int clean_suite(void) {
    return 0;
}

bool eq_fn(elem_t a, elem_t b){
    return a.i == b.i;
}
// Test list creation and destruction
void test_create_destroy() {
    
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    CU_ASSERT_PTR_NOT_NULL(list);
    ioopm_linked_list_destroy(list);
}

// Test list get

void test_get() {
    // Create an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);

    // Append the values 10, 20, 30 and 40 to the list
    ioopm_linked_list_append(list, int_elem(10));
    ioopm_linked_list_append(list, int_elem(20));
    ioopm_linked_list_append(list, int_elem(30));
    ioopm_linked_list_append(list, int_elem(40));


    // Checks that the value you get from using the function is the same as the one we set earlier
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 0).i, 10); 
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 1).i, 20); 
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 2).i, 30); 
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 3).i, 40); 

    // Clean up

    ioopm_linked_list_destroy(list);
}



// Test list append
void test_append() {

    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);

    //Appends the value 42 into the list
    ioopm_linked_list_append(list, int_elem(42));

    //Checks the the value you get from appending is 42
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 0).i, 42);
    ioopm_linked_list_destroy(list);
}

// Test list prepend
void test_prepend() {

    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    //Appends the value 10 and 20 into the list
    ioopm_linked_list_append(list, int_elem(10));
    ioopm_linked_list_append(list, int_elem(20));
    
    //Prepends the value 42 into the list
    ioopm_linked_list_prepend(list, int_elem(42));

    //Checks that the value in index 0 is 42 (because prepending inserst the value in the first index)
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 0).i, 42);

    //Clean up
    ioopm_linked_list_destroy(list);
}

// Test list insert
void test_insert() {

    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    //Appends the value 42 and then 10 into the list
    ioopm_linked_list_append(list, int_elem(10));
    ioopm_linked_list_append(list, int_elem(20));

    //Inserts the value 15 into the list's index 1
    ioopm_linked_list_insert(list, 1, int_elem(15));  

    //Asserts that value you get from index 1 is 15 (because we inserted it in earlier)
    CU_ASSERT_EQUAL(ioopm_linked_list_get(list, 1).i, 15);

    //Clean up
    ioopm_linked_list_destroy(list);
}

// Test list remove
void test_remove() {
    
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    //Appends the value 42 into the list
    ioopm_linked_list_append(list, int_elem(42));
   
    // Asserts that the value in the removed list is 42
    CU_ASSERT_EQUAL(ioopm_linked_list_remove(list, 0).i, 42);
   
    // Cleanup
    ioopm_linked_list_destroy(list);
}

// Test list clear and is_empty
void test_clear_is_empty() {

    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);

    //Appends the value 42 into the list
    ioopm_linked_list_append(list, int_elem(42));
    
    // Clears the linked list
    ioopm_linked_list_clear(list);

    // Asserts that the list is empty
    CU_ASSERT_TRUE(ioopm_linked_list_is_empty(list));
    
    // Cleanup
    ioopm_linked_list_destroy(list);
}

// Test list size
void test_size() {
    
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);

    //Asserst that the empty list has the size of 0
    CU_ASSERT_EQUAL(ioopm_linked_list_size(list), 0);
    
    // Appends a value to the list
    ioopm_linked_list_append(list, int_elem(42));

    // Asserts that it's true that the list now has a size of 1
    CU_ASSERT_EQUAL(ioopm_linked_list_size(list), 1);
    
    // Cleanup
    ioopm_linked_list_destroy(list);
}

// Test list contains
void test_contains() {
    
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    
    // Appends the value 42 into the list
    ioopm_linked_list_append(list, int_elem(42));

    // Asserts that the lists contains the value 42
    CU_ASSERT_TRUE(ioopm_linked_list_contains(list, int_elem(42)));

    // Asserst that it's false that the list contains 100
    CU_ASSERT_FALSE(ioopm_linked_list_contains(list, int_elem(100)));
    
    // Cleanup
    ioopm_linked_list_destroy(list);
}

bool is_positive(elem_t value, elem_t *extra)
{
    return (value.i) > 0;
}

void test_all()
{
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    
    for(int i = 0; i < 3; i++){ 
        ioopm_linked_list_insert(list, i, int_elem(i+1));
    }

    // Test if all elements are positive
    assert(ioopm_linked_list_all(list, *is_positive, NULL));

    // Insert a negative value
    ioopm_linked_list_insert(list, 3, int_elem(-1));

    // Test again (should return false now)
    assert(!ioopm_linked_list_all(list, *is_positive, NULL));

    // Cleanup
    ioopm_linked_list_destroy(list);
}

bool is_negative(elem_t value, elem_t *extra)
{
    return (value.i) < 0;
}

void test_any()
{
    //Creates an empty list
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);
    
    // Inserts values into the list    
    for(int i = 0; i < 3; i++){ 
        ioopm_linked_list_insert(list, i, int_elem(i+1));
    }

    // Assserts that no elements are negative (should return false if programs runs as intended)
    assert(!ioopm_linked_list_any(list, *is_negative, NULL));

    // Inserts a negative value
    ioopm_linked_list_insert(list, 3, int_elem(-1));

    // Asserts that there is a negativ element (should return true now)
    assert(ioopm_linked_list_any(list, *is_negative, NULL));

    // Cleanup
    ioopm_linked_list_destroy(list);
}

// Helper function
void increment(elem_t value, elem_t *extra)
{
    value.i++;
}

void test_apply()
{
    ioopm_list_t *list = ioopm_linked_list_create(eq_fn);

    // Inserts values into the list
    for(int i = 0; i < 3; i++){ 
        ioopm_linked_list_insert(list, i, int_elem(i));
    }

    // Applies the increment function to all elements in the list
    ioopm_linked_list_apply_to_all(list, *increment, NULL);

    // Checks that all values have been incremented by 1
    assert(ioopm_linked_list_get(list, 0).i == 1);
    assert(ioopm_linked_list_get(list, 1).i == 2);
    assert(ioopm_linked_list_get(list, 2).i == 3);

    // Cleanup
    ioopm_linked_list_destroy(list);
}
// Main function to run the tests
int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Linked List Tests", init_suite, clean_suite);
    CU_add_test(suite, "test create and destroy", test_create_destroy);
    CU_add_test(suite, "test get", test_get);
    CU_add_test(suite, "test append", test_append);
    CU_add_test(suite, "test prepend", test_prepend);
    CU_add_test(suite, "test insert", test_insert);
    CU_add_test(suite, "test remove", test_remove);
    CU_add_test(suite, "test clear and is_empty", test_clear_is_empty);
    CU_add_test(suite, "test size", test_size);
    CU_add_test(suite, "test contains", test_contains);
    CU_add_test(suite, "test all", test_all);
    CU_add_test(suite, "test any", test_any);
    CU_add_test(suite, "test apply", test_apply);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
