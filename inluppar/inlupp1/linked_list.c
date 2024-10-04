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


struct link
{
    int value;
    struct link *next;
};

typedef struct link link_t; 

struct list
{
    link_t *head;
    int size;
};

typedef struct list ioopm_list_t;



link_t *link_create(int value, link_t *next)
{
    link_t *link = calloc(1, sizeof(link_t));
    link->value = value;
    link->next = next;
    return link;
}

/// @brief Creates a new empty list
/// @return an empty linked list
ioopm_list_t *ioopm_linked_list_create()
{
    return calloc(1, sizeof(struct list));
}


/// @brief Tear down the linked list and return all its memory (but not the memory of the elements)
/// @param list the list to be destroyed
void ioopm_linked_list_destroy(ioopm_list_t *list)
{
    assert(list);
    link_t *current = list->head;
    while (current)
    {
        link_t *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(list);
}

/// @brief Insert at the end of a linked list in O(1) time
/// @param list the linked list that will be appended
/// @param value the value to be appended
void ioopm_linked_list_append(ioopm_list_t *list, int value)
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
void ioopm_linked_list_prepend(ioopm_list_t *list, int value)
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
void ioopm_linked_list_insert(ioopm_list_t *list, int index, int value)
{
    ioopm_list_t *new_list = list;
    
    if(index > (list -> size)){
        printf("Sorry the index is out of the linked lists bound \n");
        return;
    }
    
    
    if(index == 0){
        ioopm_linked_list_prepend(list, value);
    }
    
    else{
        link_t *current = new_list->head;
        link_t *next_entry = new_list -> head -> next;

        int i = 0;
        while (i <= index && current -> next != NULL )
        {
            
            if(i < index){ 
            current = current->next;
            }

            if(i == index){
                current -> value = value;
            }
            
            else if (i > index){    
            current = next_entry;
            }
            
            i++;
        }
    }   
    
    list->size++;  
}

/// @brief Remove an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list
/// @param index the position in the list
/// @return the value removed
int ioopm_linked_list_remove(ioopm_list_t *list, int index)
{
    assert(list);
    assert(list->head);

    if (index == 0)
    {
        link_t *tmp = list->head;
        int value = tmp->value;
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
    int value = current->value;
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
int ioopm_linked_list_get(ioopm_list_t *list, int index)
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
bool ioopm_linked_list_contains(ioopm_list_t *list, int element)
{
    assert(list);
    link_t *cursor = list->head;
    while (cursor)
    {
        if(cursor->value == element)
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
int ioopm_linked_list_size(ioopm_list_t *list)
{
    assert(list);
    return list->size;
}

bool ioopm_linked_list_is_empty(ioopm_list_t *list)
{
    NOT_SUPPORTED();
}

void ioopm_linked_list_clear(ioopm_list_t *list)
{
    NOT_SUPPORTED();
}

bool ioopm_linked_list_all(ioopm_list_t *list, ioopm_int_predicate prop, void *extra)
{
    NOT_SUPPORTED();
}

bool ioopm_linked_list_any(ioopm_list_t *list, ioopm_int_predicate prop, void *extra)
{
    NOT_SUPPORTED();
}

void ioopm_linked_list_apply_to_all(ioopm_list_t *list, ioopm_apply_int_function fun, void *extra)
{
    NOT_SUPPORTED();
}

int main(void)
{
    // Create a new list
    ioopm_list_t *list = ioopm_linked_list_create();


    ioopm_linked_list_append(list, 10);
    ioopm_linked_list_append(list, 20);
    ioopm_linked_list_append(list, 30);

 
    ioopm_linked_list_prepend(list, 5);

    ioopm_linked_list_insert(list, 6, 10101010);

     ioopm_linked_list_insert(list, 2, 25);
  
    link_t *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
 

    ioopm_linked_list_destroy(list);

    return 0;
}
