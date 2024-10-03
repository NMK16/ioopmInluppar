#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct link {
    int element;
    struct link *next;
} ioopm_link_t;

typedef struct list {
    ioopm_link_t *head;
    struct list *tail;
    int size;
} ioopm_list_t;


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
    ioopm_list_t *end = list;
    if (end == NULL){
        end = ioopm_linked_list_create();
    }
    if(end->head == NULL){
        end->head = ioopm_link_create();
        end->head->element = value;
    }
    else{
        ioopm_linked_list_append(end->tail, value);
    }

}


/// @brief Insert at the front of a linked list in O(1) time
/// @param list the linked list that will be prepended to
/// @param value the value to be prepended
void ioopm_linked_list_prepend(ioopm_list_t *list, int value){
    if(list->head != NULL){
        list->head->element = value;
    }
    else{
        list->head = ioopm_link_create();
        list->head->element = value;
    }
}

int main(int argc, char *argv[])
{
    ioopm_list_t *list = ioopm_linked_list_create();
    ioopm_linked_list_append(list, 2);
    printf("%d\n", list->head->element);
    ioopm_linked_list_append(list->tail, 3);
    printf("%d\n", list->tail->head->element);
    ioopm_linked_list_prepend(list, 1);
    printf("%d\n", list->head->element);
    return 0;
}
