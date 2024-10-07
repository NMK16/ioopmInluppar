#include "iterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



ioopm_list_iterator_t *ioopm_list_iterator(ioopm_list_t *list) {
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
    return iter->current -> next != NULL; // Check if there are more elements
}

/// @brief Step the iterator forward one step
/// @param iter the iterator
/// @return the next element
int ioopm_iterator_next(ioopm_list_iterator_t *iter) {

    int value = iter->current->value; // Get the current value
    iter->current = iter->current->next; // Move to the next link
    return value;
}

/// NOTE: REMOVE IS OPTIONAL TO IMPLEMENT 
/// @brief Remove the current element from the underlying list
/// @param iter the iterator
/// @return the removed element
int ioopm_iterator_remove(ioopm_list_iterator_t *iter) {
  
    link_t *prev = NULL;
    link_t *current = iter->list->head;

     if (iter->current == NULL) {
    
        return false;
    }
   
    while (current && current != iter->current) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
   
        return false;
    }

    
    int result = current->value;

 
    if (prev) {
        prev->next = current->next; 
    } else {
     
        iter->list->head = current->next; 
    }


    iter->current = current->next; 

    free(current); 
    iter->list->size--; 

    return result;
}


/// @brief Insert a new element into the underlying list making the current element its next
/// @param iter the iterator
/// @param element the element to be inserted
void ioopm_iterator_insert(ioopm_list_iterator_t *iter, int element) {
    link_t *new_link = calloc(1, sizeof(link_t)); // Allocate new link
    new_link->value = element; // Set its value

    // Inserting when the list is empty
    if (iter->list->size == 0) {
        iter->list->head = new_link; // Update head
        new_link->next = NULL; // New link is the only element
    } 
    else if (iter->current == iter->list->head) {
        // Inserting before the current (which is the head)
        new_link->next = iter->list->head; // Set the new link's next to current head
        iter->list->head = new_link; // Update head to the new link
    } 
    else {
        // Otherwise, find the previous link
        link_t *prev = iter->list->head;
        while (prev->next != iter->current) {
            prev = prev -> next; // Move to the next link
        }
        prev->next = new_link; // Insert new link before current
        new_link->next = iter->current; // Set new link's next to current
    }
    
    iter->list->size++; // Increment the size
}

/// @brief Reposition the iterator at the start of the underlying list
/// @param iter the iterator
void ioopm_iterator_reset(ioopm_list_iterator_t *iter) {
    iter->current = iter->list->head; // Reset to the head of the list
}

/// @brief Return the current element from the underlying list
/// @param iter the iterator
/// @return the current element
int ioopm_iterator_current(ioopm_list_iterator_t *iter) {

    return iter->current->value; // Return the current value
}

/// @brief Destroy the iterator and return its resources
/// @param iter the iterator
void ioopm_iterator_destroy(ioopm_list_iterator_t *iter) {
    free(iter); // Free the iterator
}
