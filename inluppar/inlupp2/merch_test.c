#include "product.h"
#include "hashtable.h"
#include "linked_list.h"
#include "utils.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Används typ inte, kolla hellre på main i merch.c

//Kompilera: gcc merch_test.c hashtable.c linked_list.c  merch.c utils.c  -o merch_test -lcunit

#define int_elem(x) (elem_t) { .i = (x) }
#define ptr_elem(x) (elem_t) { .p = (x) }

static int hash_fn(elem_t key){
     return key.i % 17;
}

// bool eq_fn(elem_t a, elem_t b){
//     return a.i == b.i;
// }

bool eq_fn_char(elem_t a, elem_t b){
    return a.p == b.p;
}

void test_add_merch() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    CU_ASSERT_TRUE(add_merch(merch_table, "Widget", "A simple widget", 10));
    CU_ASSERT_FALSE(add_merch(merch_table, "Widget", "Another widget", 15)); // Duplicate name
    ioopm_hash_table_destroy(merch_table);
}

void test_list_merch() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, "Widget", "A simple widget", 10);
    add_merch(merch_table, "Gadget", "A useful gadget", 20);
    add_merch(merch_table, "Thingamajig", "An odd device", 15);

    // Capture output
    FILE *output = fopen("test_output.txt", "w");
    if (output) {
        // Redirect stdout to a file
        FILE *original_stdout = stdout;
        stdout = output;

        list_merch(merch_table);

        // Restore stdout
        stdout = original_stdout;
        fclose(output);
    }

    // Verify output
    FILE *result = fopen("test_output.txt", "r");
    char line[256];
    int line_count = 0;
    while (fgets(line, sizeof(line), result)) {
        line_count++;
    }
    fclose(result);
    CU_ASSERT(line_count == 3); 
    ioopm_hash_table_destroy(merch_table);
}

void test_remove_merch() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, "Widget", "A simple widget", 10);
    CU_ASSERT_TRUE(remove_merch(merch_table, "Widget"));
    CU_ASSERT_FALSE(remove_merch(merch_table, "Widget")); 
    ioopm_hash_table_destroy(merch_table);
}

void test_edit_merch() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, "Widget", "A simple widget", 10);
    CU_ASSERT_TRUE(edit_merch(merch_table, "Widget", "Widget Pro", "An advanced widget", 15));
    CU_ASSERT_FALSE(edit_merch(merch_table, "Nonexistent", "Widget Pro", "An advanced widget", 15));
    elem_t *updated = ioopm_hash_table_lookup(merch_table, ptr_elem("Widget Pro"));
    CU_ASSERT_STRING_EQUAL(((merch_t *)updated->p)->description, "An advanced widget");
    ioopm_hash_table_destroy(merch_table);
}

void test_replenish_stock() {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *stock_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, "Widget", "A simple widget", 10);
    CU_ASSERT_TRUE(replenish_stock(merch_table, stock_table, "Widget", "Warehouse A", 50));
    CU_ASSERT_FALSE(replenish_stock(merch_table, stock_table, "Nonexistent", "Warehouse A", 50)); 
    ioopm_hash_table_destroy(merch_table);
    ioopm_hash_table_destroy(stock_table);
}

void test_cart_functions() {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, "Widget", "A simple widget", 10);
    create_cart(cart_table, 1);
    
    add_to_cart(cart_table, 1, "Widget", 2);
    CU_ASSERT_EQUAL(calculate_cost(cart_table, merch_table, 1), 20); 

    remove_cart(cart_table, 1);
    CU_ASSERT_FALSE(ioopm_hash_table_has_key(cart_table, int_elem(1))); 

    ioopm_hash_table_destroy(cart_table);
    ioopm_hash_table_destroy(merch_table);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Merchandise Test Suite", 0, 0);
    CU_add_test(suite, "Test Add Merchandise", test_add_merch);
    CU_add_test(suite, "Test List Merchandise", test_list_merch);
    CU_add_test(suite, "Test Remove Merchandise", test_remove_merch);
    CU_add_test(suite, "Test Edit Merchandise", test_edit_merch);
    CU_add_test(suite, "Test Replenish Stock", test_replenish_stock);
    CU_add_test(suite, "Test Cart Functions", test_cart_functions);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
