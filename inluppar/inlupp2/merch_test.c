#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "product.h"
#include "common.h"
#include "hashtable.h"
#include "linked_list.h"
#include "utils.h"
#include "iterator.h"

// Compile command: gcc merch_test.c hashtable.c linked_list.c merch.c utils.c iterator.c -o merch_test -lcunit
// valgrind ./merch_test

static int hash_fn(elem_t key) {
    int *hash = (int *) key.p;
    return *hash % 17;  
}

// Test suite setup
int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }


void test_create_merch(void) {
    merch_t *merch = create_merch("Vara1", "Test Vara", 100);
    CU_ASSERT_PTR_NOT_NULL(merch);
    CU_ASSERT_STRING_EQUAL(merch->name, "Vara1");
    CU_ASSERT_STRING_EQUAL(merch->description, "Test Vara");
    CU_ASSERT_EQUAL(merch->price, 100);
    destroy_merch(merch);
}

void test_add_merch(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 200, "Ny Vara", "Vara2");
    CU_ASSERT_TRUE(ioopm_hash_table_has_key(merch_table, ptr_elem("Vara2")));
    //ioopm_hash_table_destroy(merch_table);
    merch_table_destroy(merch_table);
}

void test_remove_merch(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 300, "Vara to remove", "Vara3");
    remove_merch(merch_table, "Y", "Vara3");
    CU_ASSERT_FALSE(ioopm_hash_table_has_key(merch_table, ptr_elem("Vara3")));
    //ioopm_hash_table_destroy(merch_table);
    merch_table_destroy(merch_table);
}

void test_list_merch(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 400, "Test Vara", "Vara4");
    add_merch(merch_table, 500, "Ny Vara", "Vara5");
    // Output check to be manually verified in this test context
    list_merch(merch_table, "Y");
    //ioopm_hash_table_destroy(merch_table);
    merch_table_destroy(merch_table);}

void test_edit_merch(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 600, "Original Vara", "Vara6");
    edit_merch(merch_table, 650, "Updaterad Vara", "TidigareVara6", "Vara6");
    elem_t *result = ioopm_hash_table_lookup(merch_table, ptr_elem("TidigareVara6"));
    merch_t *merch = result->p;
    CU_ASSERT_STRING_EQUAL(merch->description, "Updaterad Vara");
    CU_ASSERT_STRING_EQUAL(merch->name, "TidigareVara6");
    CU_ASSERT_EQUAL(merch->price, 650);
    //ioopm_hash_table_destroy(merch_table);
    merch_table_destroy(merch_table);
    }

void test_show_stock(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 700, "Test Vara", "Vara7");
    replenish_stock(merch_table, 10, "A10", "Vara7");
    show_stock(merch_table, "Vara7");
    merch_table_destroy(merch_table);
}

void test_replenish_stock(void) {
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 800, "Vara med stock", "Vara8");
    replenish_stock(merch_table, 20, "B20", "Vara8");
    merch_t *merch = ioopm_hash_table_lookup(merch_table, ptr_elem("Vara8"))->p;
    CU_ASSERT_EQUAL(merch->amountInStock, 20);
    //ioopm_hash_table_destroy(merch_table);
    merch_table_destroy(merch_table);}

void test_create_cart(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    create_cart(cart_table, "Vagn1");
    CU_ASSERT_TRUE(ioopm_hash_table_has_key(cart_table, ptr_elem("Vagn1")));
    cart_table_destroy(cart_table);
}

void test_remove_cart(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    create_cart(cart_table, "Vagn2");
    remove_cart(cart_table, "Y", "Vagn2");
    CU_ASSERT_FALSE(ioopm_hash_table_has_key(cart_table, ptr_elem("Vagn2")));
    ioopm_hash_table_destroy(cart_table);
}



void test_add_to_cart(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 900, "Vara to add to Vagn", "Vara9");
    replenish_stock(merch_table, 50, "C50", "Vara9");
    create_cart(cart_table, "Vagn3");
    add_to_cart(cart_table, merch_table, 5, "Vara9", "Vagn3");
    merch_table_destroy(merch_table);
    cart_table_destroy(cart_table);

}

void test_remove_from_cart(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table,1000, "Vara in Vagn", "Vara10");
    replenish_stock(merch_table, 100, "V50", "Vara10");
    create_cart(cart_table, "Vagn4");
    add_to_cart(cart_table, merch_table, 10, "Vara10", "Vagn4");
    remove_from_cart(cart_table, merch_table, 5, "Vara10", "Vagn4");
    merch_table_destroy(merch_table);
    cart_table_destroy(cart_table);
}

void test_calculate_cost(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 1100, "Vara to calculate", "Vara11");
    create_cart(cart_table, "Vagn5");
    add_to_cart(cart_table, merch_table, 3, "Vara11", "Vagn5");
    calculate_cost(cart_table, merch_table, "Vagn5");
    merch_table_destroy(merch_table);
    cart_table_destroy(cart_table);
}

void test_checkout(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    add_merch(merch_table, 1200, "Vara to checkout", "Vara12");
    replenish_stock(merch_table, 40, "E40", "Vara12");
    create_cart(cart_table, "Vagn6");
    add_to_cart(cart_table, merch_table, 5, "Vara12", "Vagn6");
    checkout(cart_table, merch_table, "Vagn6");
    merch_table_destroy(merch_table);
}

void test_empty_checkout(void) {
    ioopm_hash_table_t *cart_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    ioopm_hash_table_t *merch_table = ioopm_hash_table_create(hash_fn, eq_fn, eq_fn);
    create_cart(cart_table, "Vagn6");
    checkout(cart_table, merch_table, "Vagn6");
    merch_table_destroy(merch_table);
    cart_table_destroy(cart_table);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Merch Tests", init_suite, clean_suite);
    CU_add_test(suite, "Create Merch", test_create_merch);
    CU_add_test(suite, "Add Merch", test_add_merch);
    CU_add_test(suite, "Remove Merch", test_remove_merch);
    CU_add_test(suite, "List Merch", test_list_merch);
    CU_add_test(suite, "Edit Merch", test_edit_merch);
    CU_add_test(suite, "Show Stock", test_show_stock);
    CU_add_test(suite, "Replenish Stock", test_replenish_stock);
    CU_add_test(suite, "Create Cart", test_create_cart);
    CU_add_test(suite, "Remove CArt", test_remove_cart);
    CU_add_test(suite, "Add to Cart", test_add_to_cart);
    CU_add_test(suite, "Remove from Cart", test_remove_from_cart);
    CU_add_test(suite, "Calculate Cost", test_calculate_cost);
    CU_add_test(suite, "Checkout", test_checkout);
    CU_add_test(suite, "Empty Checkout", test_empty_checkout);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
