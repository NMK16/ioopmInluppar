#include "iterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



ioopm_list_iterator_t *ioopm_list_iterator_create(ioopm_list_t *list) {
    // Correct memory allocation for the iterator
    ioopm_list_iterator_t *result = calloc(1, sizeof(ioopm_list_iterator_t));
    result->list = list;
    result->current = list->head; // Initialize current to the head of the list

    return result;
}

/// @brief Checks if there are more elements to iterate over
/// @param iter the iterator
/// @return true if there is at least one more element 
bool ioopm_iterator_has_next(ioopm_list_iterator_t *iter) { 
    return iter->current->next != NULL;
}

bool ioopm_iterator_has_current(ioopm_list_iterator_t *iter) { 
    return iter->current != NULL;
}
/// @brief Step the iterator forward one step
/// @param iter the iterator
/// @return the next element
elem_t ioopm_iterator_next(ioopm_list_iterator_t *iter) {

    if(ioopm_iterator_has_next(iter)){
        iter->current = iter->current-> next; // Goes to the next link in the list
    }
    
    return iter -> current -> value;
     

}

/// NOTE: REMOVE IS OPTIONAL TO IMPLEMENT 
/// @brief Remove the current element from the underlying list
/// @param iter the iterator
/// @return the removed element
elem_t ioopm_iterator_remove(ioopm_list_iterator_t *iter) {
    if (iter->current == NULL) {
        return iter -> current -> value; 
    }

    link_t *current = iter->current;
    link_t *prev = NULL;

    if (iter->list->head == current) {  // If there's only one element
        iter->list->head = current->next;
    } else {
        prev = iter->list->head;  //If it has to traverse multiple elements
        while (prev->next != current) {
            prev = prev->next;
        }
        prev->next = current->next; // Skip the current element
    }

    elem_t result = current->value; // Saves the currents value;

    iter->current = current->next; // Move iterator to the next element
    free(current);
    iter->list->size--; //Decreases the size by one

    return result; //Outputs the value of the removed element
}



/// @brief Insert a new element into the underlying list making the current element its next
/// @param iter the iterator
/// @param element the element to be inserted
void ioopm_iterator_insert(ioopm_list_iterator_t *iter, elem_t element) {
    link_t *new_link = calloc(1, sizeof(link_t));
    new_link->value = element;

    if (iter->list->size == 0) { // If it's an empty list
        iter->list->head = new_link; 
        iter->current = new_link; 
        new_link-> next = NULL; //Since it only one element it points to NULL
    } else if (iter->current == iter->list->head) { // Inserting at the head/beginning
        new_link->next = iter->list->head;
        iter->list->head = new_link;
        iter->current = new_link; 
    } else { // Inserting with multiple elemens and not in the beginning
        link_t *prev = iter->list->head;
        while (prev->next != iter->current) {
            prev = prev->next;
        }
        prev->next = new_link;
        new_link->next = iter->current; // Insert new element before current
        iter->current = new_link; // Update current to the new element
    }

    iter->list->size++; //Increases the size by one
}


/// @brief Reposition the iterator at the start of the underlying list
/// @param iter the iterator
void ioopm_iterator_reset(ioopm_list_iterator_t *iter) {
    iter->current = iter->list->head; // Reset to the head of the list
}

/// @brief Return the current element from the underlying list
/// @param iter the iterator
/// @return the current element
elem_t ioopm_iterator_current(ioopm_list_iterator_t *iter) {

    return iter->current->value; // Return the current value
}

/// @brief Destroy the iterator and return its resources
/// @param iter the iterator
void ioopm_iterator_destroy(ioopm_list_iterator_t *iter) {
    free(iter); // Free the iterator
}
