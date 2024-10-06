#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct link {
    int value;
    struct link *next;
} ioopm_link_t;

typedef struct list {
    ioopm_link_t *head;
    ioopm_link_t *tail;
    int size;
} ioopm_list_t;

typedef bool ioopm_int_predicate(int value, void *extra);
typedef void ioopm_apply_int_function(int value, void *extra);


ioopm_link_t *ioopm_link_create(void)
{
    ioopm_link_t *link = calloc(1, sizeof(ioopm_link_t));
    return link;
}

/// @brief Creates a new empty list
/// @return an empty linked list
ioopm_list_t *ioopm_linked_list_create(void){
    ioopm_list_t *result = calloc(1, sizeof(ioopm_list_t));
    return result;
}

/// @brief Tear down the linked list and return all its memory (but not the memory of the elements)
/// @param list the list to be destroyed
void ioopm_linked_list_destroy(ioopm_list_t *list){
    if(list != NULL){
        free(list);
    }
}

/// @brief Insert at the end of a linked list in O(1) time
/// @param list the linked list that will be appended
/// @param value the value to be appended
void ioopm_linked_list_append(ioopm_list_t *list, int value){
    if (list->size == 0){
        list->tail = ioopm_link_create();
        list->tail->value = value;

        list->head = ioopm_link_create();
        list->head->value = value;
        list->head->next = list->tail;
    }
    else {
        ioopm_link_t *new = ioopm_link_create();
        new->value = value;
        list->tail->next = new;
        if (list->size > 1){
            list->tail = new;
        }
        else if(list->size == 1){
            list->tail = new;
            list->head->next = list->tail;
        }
    }
    list->size++;
}


/// @brief Insert at the front of a linked list in O(1) time
/// @param list the linked list that will be prepended to
/// @param value the value to be prepended
void ioopm_linked_list_prepend(ioopm_list_t *list, int value){
    if (list->head == NULL){
        list->head = ioopm_link_create();
        list->head->value = value;
        list->head->next =list->tail;
    }
    else{
        ioopm_link_t *new = ioopm_link_create();
        new->next = list->head;
        new->value = value;

        list->head = new;
    }
    list->size++;
}

/// @brief Insert an element into a linked list in O(n) time.
/// The valid values of index are [0,n] for a list of n elements,
/// where 0 means before the first element and n means after
/// the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @param value the value to be inserted 
void ioopm_linked_list_insert(ioopm_list_t *list, int index, int value){
    if (index == 0) {
        ioopm_linked_list_prepend(list, value);
    }

    else if (index == list->size) {
        ioopm_linked_list_append(list, value);
    }

    else {

        ioopm_link_t *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }


        ioopm_link_t *new = ioopm_link_create();
        new->value = value;

        new->next = current->next;  
        current->next = new;        

        list->size++;
    }
}

/// @brief Remove an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list
/// @param index the position in the list
/// @return the value removed
int ioopm_linked_list_remove(ioopm_list_t *list, int index){
    ioopm_link_t *current = list->head;
    int value;
    if (index == 0){
        value = current->value;
        list->head = current->next;
    }
    else {
        for (int i = 0; i < index - 1; i++){
            current = current->next;
        }
        int value = current->next->value;
        current->next = current->next->next;
        if (index == list->size - 1){
            list->tail = current;
        }
    }
    list->size--;
    return value;
}

/// @brief Retrieve an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @return the value at the given position
int ioopm_linked_list_get(ioopm_list_t *list, int index){
    ioopm_link_t *current = list->head;
    for (int i = 0; i < index; i++){
        current = current->next;
    }
    return current->value;
}

/// @brief Test if an element is in the list
/// @param list the linked list
/// @param element the element sought
/// @return true if element is in the list, else false
bool ioopm_linked_list_contains(ioopm_list_t *list, int element){
    ioopm_link_t *current = list->head;
    for (int i = 0; i < list->size-1; i++){
        if(current->value == element){
            return true;
        }
        current = current->next;
    }
    return false;
}

/// @brief Lookup the number of elements in the linked list in O(1) time
/// @param list the linked list
/// @return the number of elements in the list
int ioopm_linked_list_size(ioopm_list_t *list){
    return list->size;
}

/// @brief Test whether a list is empty or not
/// @param list the linked list
/// @return true if the number of elements int the list is 0, else false
bool ioopm_linked_list_is_empty(ioopm_list_t *list){
    return list->size == 0;
}

/// @brief Remove all elements from a linked list
/// @param list the linked list
void ioopm_linked_list_clear(ioopm_list_t *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list->head);
    free(list->tail);
    free(&list->size);
}

bool test(int test, void *extra){
    return true;
}

/// @brief Test if a supplied property holds for all elements in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested (function pointer)
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for all elements in the list, else false
bool ioopm_linked_list_all(ioopm_list_t *list, ioopm_int_predicate *prop, void *extra){
    ioopm_link_t *current = list->head;
    for (int i = 0; i < list->size - 1; i++){
        if(!prop(current->value, extra)){
            return false;
        }
        current = current->next;
    }
    return true;
}

/// @brief Test if a supplied property holds for any element in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for any elements in the list, else false
bool ioopm_linked_list_any(ioopm_list_t *list, ioopm_int_predicate *prop, void *extra){
    ioopm_link_t *current = list->head;
    for (int i = 0; i < list->size - 1; i++){
        if(prop(current->value, extra)){
            return true;
        }
        current = current->next;
    }
    return false;
}

/// @brief Apply a supplied function to all elements in a list.
/// @param list the linked list
/// @param fun the function to be applied
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of fun
void ioopm_linked_list_apply_to_all(ioopm_list_t *list, ioopm_apply_int_function *fun, void *extra){
    ioopm_link_t *current = list->head;
    for (int i = 0; i < list->size - 1; i++){
        fun(current->value, extra);
        current = current->next;
    }  
}

void print_list(ioopm_list_t *list) {
    ioopm_link_t *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[])
{
    ioopm_list_t *list = ioopm_linked_list_create();
    ioopm_linked_list_append(list, 2);
    ioopm_linked_list_append(list, 3);
    ioopm_linked_list_append(list, 4);
    ioopm_linked_list_prepend(list, 1);
    ioopm_linked_list_prepend(list, 0);
    ioopm_linked_list_append(list, 5);
    ioopm_linked_list_insert(list, 0, 6);
    ioopm_linked_list_remove(list, 6);
    printf("\n%d\n", ioopm_linked_list_all(list, test, NULL));
    print_list(list);

    return 0;
}
