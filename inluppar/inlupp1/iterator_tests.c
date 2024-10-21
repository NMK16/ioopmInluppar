#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdbool.h>
#include "iterator.h" 
#include "common.h"
#include "linked_list.h"

#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

// Kör koden i denna fil genom:
// gcc -g -Wall iterator_tests.c iterator.c linked_list.c -lcunit -o iterator_tests
// ./iterator_tests

//För att köra valgrind
//gcc -g -Wall iterator_tests.c iterator.c linked_list.c -lcunit -o iterator_tests
//valgrind --leak-check=full --track-origins=yes ./iterator_tests

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

int elem_int(elem_t element){
    return element.i;
}

// Test iterator creation
void test_iterator_creation() {

    //Setup
    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);


    CU_ASSERT_PTR_NOT_NULL(iter->current); // Ensure the current pointer is not NULL
    CU_ASSERT_EQUAL(elem_int(iter->current->value), 1); // Check if the current value is the head of the list

    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter); // Free the iterator

}

// Test iterator has next
void test_iterator_has_next() {
    
    
    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);

    
    CU_ASSERT_TRUE(ioopm_iterator_has_next(iter)); // Should return true
    ioopm_iterator_next(iter); // Move to next
    CU_ASSERT_FALSE(ioopm_iterator_has_next(iter)); // Now should be false

    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter);
}

// Test iterator next
void test_iterator_next() {
    
    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(2));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);

    CU_ASSERT_EQUAL(elem_int(ioopm_iterator_next(iter)), 2); // Second element
    CU_ASSERT_EQUAL(elem_int(ioopm_iterator_next(iter)), 3); // Third elementq

    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter);

}

// Test insert 
void test_iterator_insert() {

    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);

    
    ioopm_iterator_next(iter); // Move to the second element (3)
    CU_ASSERT_EQUAL(elem_int(iter -> current -> value), 3);
    ioopm_iterator_insert(iter, int_elem(2)); // Insert 2 before 3

    // Check that 2 is now between 1 and 3
    CU_ASSERT_EQUAL(elem_int(test_list->head->next->value), 2); // Check that the next value after 1 is now 2
    CU_ASSERT_EQUAL(elem_int(test_list->head->next->next->value), 3); // Check that 3 is still present after 2
    CU_ASSERT_EQUAL(test_list->size, 3); // Size should be 3

    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter);

}

// Test iterator reset
void test_iterator_reset() {

    //Setup
    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(2));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);

    ioopm_iterator_next(iter); // Move to the second element, which should now be 2
    ioopm_iterator_next(iter); // Move to the third element, which should now be 3
    
    ioopm_iterator_reset(iter); // Makes 3 the current list head
    CU_ASSERT_EQUAL(elem_int(ioopm_iterator_current(iter)), elem_int(test_list -> head -> value)); // Asserts that the value from the current is the same as lists head
    CU_ASSERT_EQUAL(elem_int(test_list -> head -> value), 1); // Asserts that three is now the lists head
    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter);

}

void test_iterator_remove() {
    
    //Setup
    ioopm_list_t *test_list = ioopm_linked_list_create(eq_fn);
    ioopm_linked_list_append(test_list, int_elem(1));
    ioopm_linked_list_append(test_list, int_elem(2));
    ioopm_linked_list_append(test_list, int_elem(3));
    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(test_list);

    ioopm_iterator_next(iter); // Move to the second element (2)
    ioopm_iterator_remove(iter); // Remove 2

    CU_ASSERT_EQUAL(elem_int(test_list->head->value), 1); // Head should still be 1
    CU_ASSERT_EQUAL(elem_int(test_list->head->next->value), 3); // Now 3 should be after the head
    CU_ASSERT_EQUAL((test_list->size), 2); // Size should be 3
    
    // Clean up
    ioopm_linked_list_destroy(test_list);
    ioopm_iterator_destroy(iter);
}

// Main function to run the tests
int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Iterator Tests", init_suite, clean_suite);
    CU_add_test(suite, "test iterator creation", test_iterator_creation);
    CU_add_test(suite, "test iterator has next", test_iterator_has_next);
    CU_add_test(suite, "test iterator next", test_iterator_next);
    CU_add_test(suite, "test iterator insert", test_iterator_insert);
    CU_add_test(suite, "test iterator reset", test_iterator_reset);
    CU_add_test(suite, "test iterator remove", test_iterator_remove);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
