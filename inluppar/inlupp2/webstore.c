#include <stdio.h>
#include "../inlupp1/linked_list.h"
#include "../inlupp1/iterator.h"
#include "../inlupp1/hashtable.h"
#include "../inlupp1/common.h"
#include "../../labbar/lab2/utils.h"
#include <string.h>

typedef struct merch{
    elem_t name;
    elem_t description;
    int id;
    int price;
    ioopm_list_t *locs;
    int stock;
} merch_t;

typedef struct shelf{
    elem_t shelfNumber;
    int quantity;
} shelf_t;

int hash_fn(elem_t key){
    return key.i % 17;
}

bool string_eq(elem_t e1, elem_t e2)
{
    return strcmp(e1.p, e2.p) == 0;
}


shelf_t *makeShelf(char *shelfNumber){
    shelf_t *shelf = calloc(1, sizeof(shelf_t));
    shelf->shelfNumber = (elem_t) {.p = shelfNumber};
    shelf->quantity = 0;

    return shelf;
}

merch_t *addMerch(ioopm_hash_table_t *centralHt){

    merch_t *merch = calloc(1, sizeof(merch_t));
    char *nameOfMerch = ask_question_string("\nEnter name of Merch: ");

    while(ioopm_hash_table_has_key(centralHt, (elem_t){.p = nameOfMerch})){
        printf("Name already exists, enter another name:\n");
        nameOfMerch = ask_question_string("\nEnter name of Merch: ");
    }
    merch->name = (elem_t){.p = nameOfMerch};
    merch->description = (elem_t) {.p = ask_question_string("\nEnter description of Merch: ")};
    merch->id = ask_question_int("\nEnter id of Merch: ");
    merch->price = ask_question_int("\nEnter price of Merch: ");
    merch->locs = ioopm_linked_list_create(string_eq);

    //Insert merch to hashtable name->merch
    ioopm_hash_table_insert(centralHt, merch->name, (elem_t) {.p = merch});

    return merch;

}

void listMerch(ioopm_hash_table_t *centralHt){
    ioopm_list_iterator_t *allValues = calloc(1, sizeof(ioopm_list_iterator_t));
    allValues->list = ioopm_hash_table_values(centralHt);
    allValues->current = ioopm_hash_table_keys(centralHt)->head;
    int i = 1;

    while(ioopm_iterator_has_current(allValues)){
        printf("\n%d. %s\n", i, (char *)(allValues->current->value.p));
        if(ioopm_iterator_has_next(allValues)){
            ioopm_iterator_next(allValues);
            i++;
        }
        else{
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    //Central Hashtable, Merch Name -> Merch
    ioopm_hash_table_t *centralHt = ioopm_hash_table_create(hash_fn, string_eq, string_eq);

    //Central Hashtable Merch Name -> Shelf Number
    ioopm_hash_table_t *centralHtShelf = ioopm_hash_table_create(hash_fn, string_eq, string_eq);
    while(true){
        char *option = ask_question_string("Choose option:\nA - Add Merch\nL- List Merch\n");

        switch(*option){
            case 'A':
                addMerch(centralHt);
                break;
            case 'L':
                listMerch(centralHt);   
                break;     
        }
    }

    // merch_t *merch = makeMerch("egg", "eggs", 4, 4);
    // ioopm_hash_table_t *centralHt = ioopm_hash_table_create(hash_fn, string_eq, string_eq);
    // ioopm_hash_table_t *centralHtShelf = ioopm_hash_table_create(hash_fn, string_eq, string_eq);

    // shelf_t *shelf = makeShelf("A25");
    // addMerch(centralHt, centralHtShelf, merch, shelf);
    
    

    // printf("%d\n", ((shelf_t *)(((merch_t *)(ioopm_hash_table_lookup(centralHt, (elem_t){.p = "egg"})->p))->locs->head->value).p)->quantity);
    return 0;
}
