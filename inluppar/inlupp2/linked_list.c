#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @file simple_linked_list.c
 * @author Elias Castegren
 * @date 1 Sep 2021
 * @brief A simple linked list that implements parts of the interface
 * of `linked_list.h`. The functions that are not implemented will fail
 * at runtime with an assertion error, printing a message to stderr.
 */

// This is a macro that is used in the functions that are not implemented,
// to have them fail at runtime. You do not have to understand it to use
// this file!

#define NOT_SUPPORTED()                                                            \
    do                                                                             \
    {                                                                              \
        fprintf(stderr, "The simple linked list does not support %s\n", __func__); \
        assert(false);                                                             \
    } while (0)

link_t *link_create(elem_t value, link_t *next)
{
    link_t *link = calloc(1, sizeof(link_t));
    link->value = value;
    link->next = next;
    return link;
}

/// @brief Creates a new empty list
/// @return an empty linked list
ioopm_list_t *ioopm_linked_list_create(ioopm_equal_function *eq_fun)
{
    ioopm_list_t *empty = calloc(1, sizeof(struct list));
    empty->eq_fn = eq_fun;
    return empty;
}


/// @brief Tear down the linked list and return all its memory (but not the memory of the elements)
/// @param list the list to be destroyed
void ioopm_linked_list_destroy(ioopm_list_t *list)
{
    assert(list);
    
    link_t *current = list->head;
    while (current)
    {
        link_t *tmp = current -> next;
        free(current);
        current = tmp;
        
    }
    free(list);
}

/// @brief Insert at the end of a linked list in O(1) time
/// @param list the linked list that will be appended
/// @param value the value to be appended
void ioopm_linked_list_append(ioopm_list_t *list, elem_t value)
{
    assert(list);  

    link_t *new_entry = link_create(value, NULL);  

    if (list->head == NULL)  
    {
        list->head = new_entry;
    }
    else
    {
        link_t *current = list->head;


        while (current->next != NULL)
        {
            current = current->next;
        }
        

        current->next = new_entry;
    }

    list->size++;  
}


/// @brief Insert at the front of a linked list in O(1) time
/// @param list the linked list that will be prepended to
/// @param value the value to be prepended
void ioopm_linked_list_prepend(ioopm_list_t *list, elem_t value)
{
    assert(list);
    list->head = link_create(value, list->head);
    list->size++;
}

/// @brief Insert an element into a linked list in O(n) time.
/// The valid values of index are [0,n] for a list of n elements,
/// where 0 means before the first element and n means after
/// the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @param value the value to be inserted 
void ioopm_linked_list_insert(ioopm_list_t *list, int index, elem_t value)
{
    if (index > list->size)
    {
        printf("Sorry, the index is out of the linked list's bounds.\n");
        return;  
    }

    if (index == 0)
    {
        ioopm_linked_list_prepend(list, value);  
        return;
    }

    link_t *current = list->head;
    

    for (int i = 0; i < index - 1 && current != NULL; i++)
    {
        current = current->next;
    }

   
    link_t *new_node = link_create(value, current->next);

 
    current->next = new_node;

    list->size++;
}

/// @brief Remove an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list
/// @param index the position in the list
/// @return the value removed
elem_t ioopm_linked_list_remove(ioopm_list_t *list, int index)
{
    assert(list);
    assert(list->head);

    if (index == 0)
    {
        link_t *tmp = list->head;
        elem_t value = tmp->value;
        list->head = tmp->next;
        free(tmp);
        list->size--;
        return value;
    }

    // index > 0
    assert(list->head);
    link_t *prev = list->head;
    link_t *current = prev->next;
    for (int i = 1; i < index; i++)
    {
        assert(current);
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    elem_t value = current->value;
    free(current);
    list->size--;
    return value;
}

/// @brief Retrieve an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @return the value at the given position
elem_t ioopm_linked_list_get(ioopm_list_t *list, int index)
{
    assert(list);
    assert(list->head);
    link_t *current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
        assert(current);
    }
    return current->value;
}

/// @brief Test if an element is in the list
/// @param list the linked list
/// @param element the element sought
/// @return true if element is in the list, else false
bool ioopm_linked_list_contains(ioopm_list_t *list, elem_t element)
{
    assert(list);
    link_t *cursor = list->head;
    while (cursor)
    {
        if(list->eq_fn(cursor->value, element))
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/// @brief Lookup the number of elements in the linked list in O(1) time
/// @param list the linked list
/// @return the number of elements in the list
size_t ioopm_linked_list_size(ioopm_list_t *list)
{
    assert(list);
    return list->size;
}

bool ioopm_linked_list_is_empty(ioopm_list_t *list)
{
    if(list->size == 0){
        return true;
    }
    
    return false;
}


/// @brief Remove all elements from a linked list
/// @param list the linked list
void ioopm_linked_list_clear(ioopm_list_t *list)
{
    assert(list);
    
    link_t *current = list->head;

    while (current != NULL)
    {
        link_t *tmp = current;  
        current = current->next;  
        free(tmp); 
    }

    list->head = NULL;  
    list->size = 0;  
}


/// @brief Test if a supplied property holds for all elements in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested (function pointer)
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for all elements in the list, else false
bool ioopm_linked_list_all(ioopm_list_t *list, ioopm_int_predicate *prop, elem_t *extra)
{
    link_t *current = list -> head;
    while(current != NULL){

        if(!prop(current -> value, extra)){
            return false;
        }

        current = current -> next;
    }
    return true;
}


/// @brief Test if a supplied property holds for any element in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for any elements in the list, else false
bool ioopm_linked_list_any(ioopm_list_t *list, ioopm_int_predicate *prop, elem_t *extra)
{
    link_t *current = list -> head;
    while(current != NULL){
        if(prop(current -> value, extra)){
            return true;
        }
        current = current -> next;
    }
    return false; 
}


/// @brief Apply a supplied function to all elements in a list.
/// @param list the linked list
/// @param fun the function to be applied
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of fun
void ioopm_linked_list_apply_to_all(ioopm_list_t *list, ioopm_apply_int_function *fun, elem_t *extra)
{
    link_t *current= list -> head;

    while(current){
        fun(&(current -> value), extra);
        current = current -> next;
    }
}

// int main(void)
// {
//     // Create a new list
//     ioopm_list_t *list = ioopm_linked_list_create();


//     ioopm_linked_list_append(list, 10);
//     ioopm_linked_list_append(list, 20);
//     ioopm_linked_list_append(list, 30);

 
//     ioopm_linked_list_prepend(list, 5);

//     ioopm_linked_list_insert(list, 6, 10101010);

//     ioopm_linked_list_insert(list, 2, 15);
  
//     link_t *current = list->head;
//     while (current != NULL)
//     {
//         printf("%d -> ", current->value);
//         current = current->next;
//     }
 

//     ioopm_linked_list_clear(list);
    
//     if(ioopm_linked_list_is_empty(list)){
//         printf(" \n Empty list, should prob be cleared if im right\n");
//     }
 
//     return 0;
// }
