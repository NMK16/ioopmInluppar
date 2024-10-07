#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdbool.h>
#include "iterator.h" 

// Kör koden i denna fil genom:
// gcc -Wall iterator_tests.c iterator.c -lcunit -o iterator_tests
// ./iterator_tests

//För att köra valgrind
//gcc -Wall iterator_tests.c iterator.c -lcunit -o iterator_tests
//valgrind --leak-check=full --track-origins=yes ./iterator_tests

// Optional setup before tests
int init_suite(void) {
    return 0;
}

// Optional cleanup after tests
int clean_suite(void) {
    return 0;
}

// Helper function to create a linked list with given values
ioopm_list_t* create_test_list(int *values, int size) {
    ioopm_list_t *list = malloc(sizeof(ioopm_list_t));
    list->head = NULL;
    list->size = 0;

    for (int i = 0; i < size; i++) {
        link_t *new_link = malloc(sizeof(link_t));
        new_link->value = values[i];
        new_link->next = list->head;
        list->head = new_link;
        list->size++;
    }

    return list;
}

// Test iterator creation
void test_iterator_creation() {
    int values[] = {1, 2, 3};
    ioopm_list_t *test_list = create_test_list(values, 3);

    // Manually create the iterator
    ioopm_list_iterator_t *iter = malloc(sizeof(ioopm_list_iterator_t)); // Allocate memory for the iterator
    CU_ASSERT_PTR_NOT_NULL(iter); // Ensure the iterator is not NULL
    iter->list = test_list; // Set the list
    iter->current = test_list->head; // Set the current to the head of the list

    CU_ASSERT_PTR_NOT_NULL(iter->current); // Ensure the current pointer is not NULL
    CU_ASSERT_EQUAL(iter->current->value, 3); // Check if the current value is the head of the list

    // Clean up
    free(iter); // Free the iterator
    free(test_list); // Free the test_list here properly
}

// Test iterator has next
void test_iterator_has_next() {
    int values[] = {1, 2, 3};
    ioopm_list_t *test_list = create_test_list(values, 3);

    // Manually create the iterator
    ioopm_list_iterator_t *iter = calloc(1, sizeof(ioopm_list_iterator_t)); // Allocate memory
    iter->list = test_list; // Set the list
    iter->current = test_list->head; // Set current to head

    CU_ASSERT_TRUE(ioopm_iterator_has_next(iter)); // Should return true
    ioopm_iterator_next(iter); // Move to next
    CU_ASSERT_TRUE(ioopm_iterator_has_next(iter)); // Should still be true
    ioopm_iterator_next(iter); // Move to next
    CU_ASSERT_FALSE(ioopm_iterator_has_next(iter)); // Now should be false

    // Clean up
    free(iter);
    free(test_list);
}

// Test iterator next
void test_iterator_next() {
    int values[] = {1, 2, 3};
    ioopm_list_t *test_list = create_test_list(values, 3);

    // Manually create the iterator
    ioopm_list_iterator_t *iter = malloc(sizeof(ioopm_list_iterator_t)); // Allocate memory
    iter->list = test_list; // Set the list
    iter->current = test_list->head; // Set current to head

    CU_ASSERT_EQUAL(ioopm_iterator_next(iter), 3); // First element
    CU_ASSERT_EQUAL(ioopm_iterator_next(iter), 2); // Second element
    CU_ASSERT_EQUAL(ioopm_iterator_next(iter), 1); // Third element

    // Clean up
    free(iter);
    free(test_list);
}

// Test insert (funkar ej, behövs inte implementeras heller)
void test_iterator_insert() {
    int values[] = {1, 3}; // Initial values
    ioopm_list_t *test_list = create_test_list(values, 2);
    ioopm_list_iterator_t *iter = calloc(1, sizeof(ioopm_list_iterator_t)); // Create iterator
    iter->list = test_list;
    iter->current = test_list->head; // Set to first element (1)

    ioopm_iterator_next(iter); // Move to the second element (3)
    ioopm_iterator_insert(iter, 2); // Insert 2 before 3

    // Check that 2 is now between 1 and 3
    CU_ASSERT_EQUAL(test_list->head->next->value, 2); // Check that the next value after 1 is now 2
    CU_ASSERT_EQUAL(test_list->head->next->next->value, 3); // Check that 3 is still present after 2
    CU_ASSERT_EQUAL(test_list->size, 3); // Size should be 3

    // Clean up
    free(iter);
    free(test_list);
}

// Test iterator reset
void test_iterator_reset() {
    int values[] = {1, 2, 3};
    ioopm_list_t *test_list = create_test_list(values, 3);
    ioopm_list_iterator_t *iter = malloc(sizeof(ioopm_list_iterator_t)); // Create iterator
    iter->list = test_list;
    iter->current = test_list->head; // Set current to head

    ioopm_iterator_next(iter); // Move to the first element (1)
    ioopm_iterator_next(iter); // Move to the second element (2)
    
    ioopm_iterator_reset(iter); // Reset to head
    CU_ASSERT_EQUAL(ioopm_iterator_current(iter), 3); // Should be at the head (3)

    // Clean up
    free(iter);
    free(test_list);
}

// Test iterator remove
void test_iterator_remove() {
    int values[] = {1, 2, 3, 4};
    ioopm_list_t *test_list = create_test_list(values, 4);
    ioopm_list_iterator_t *iter = calloc(1, sizeof(ioopm_list_iterator_t)); // Create iterator
    iter->list = test_list;
    iter->current = test_list->head; // Set current to head

    ioopm_iterator_next(iter); // Move to the second element (2)
    ioopm_iterator_remove(iter); // Remove 1

    CU_ASSERT_EQUAL(test_list->head->value, 4); // Now head should be 3
    CU_ASSERT_EQUAL(test_list->size, 3); // Size should be 3

    // Clean up
    free(iter);
    free(test_list);
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
