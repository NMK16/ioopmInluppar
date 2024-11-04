#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <ctype.h>

struct item {
    char *name;
    char *desc;
    int price;
    char *shelf;
};

typedef struct item item_t;

void print_item(item_t *item) {
    printf("Name: %s\n", item->name);
    printf("Description: %s\n", item->desc);
    printf("Cost: %d.%02d\n", item->price / 100, item->price % 100);
    printf("Shelf/Aisle: %s\n", item->shelf);
}

item_t make_item(char *name, char *desc, int price, char *shelf) {
    item_t item;
    item.name = strdup(name);
    item.desc = strdup(desc);
    item.price = price;
    item.shelf = strdup(shelf);
    return item;
}

int is_valid_shelf(const char *shelf) {
    if (strlen(shelf) != 3) {
        return false;
    }
    if (!isalpha(shelf[0]) || !isdigit(shelf[1]) || !isdigit(shelf[2])) {
        return false;
    }
    return true;
}

char *ask_question_shelf(const char *question) {
    char *shelf;
    do {
        shelf = ask_question_string(question);
        if (!is_valid_shelf(shelf)) {
            printf("Invalid shelf format. Try again.\n");
            free(shelf);
        }
    } while (!is_valid_shelf(shelf));
    return shelf;
}

item_t input_item() {
    char *name = ask_question_string("Enter item name: ");
    char *desc = ask_question_string("Enter item description: ");
    int price = ask_question_int("Enter item price in cents (e.g. 715 for $7.15): ");
    char *shelf = ask_question_shelf("Enter shelf location (e.g. A25): ");
    return make_item(name, desc, price, shelf);
}

char *magick(char *array1[], char *array2[], char *array3[], int len) {
    char buf[225];
    snprintf(buf, sizeof(buf), "%s-%s %s", array1[rand() % len], array2[rand() % len], array3[rand() % len]);
    return strdup(buf);
}

void list_db(item_t *items, int no_items) {
    for (int i = 0; i < no_items; ++i) {
        printf("%d. %s\n", i + 1, items[i].name);
    }
}

void edit_db(item_t *items, int no_items) {
    int index = ask_question_int("Enter the number of an item that you want to edit: ") - 1;
    if (index < 0 || index >= no_items) {
        printf("Invalid number.\n");
        return;
    }
    printf("Editing item:\n");
    print_item(&items[index]);

    free(items[index].name);
    free(items[index].desc);
    free(items[index].shelf);

    items[index] = input_item();
}

void print_menu(){

    printf("[L]ägga till en vara \n"
    "[T]a bort en vara \n"
    "[R]edigera en vara \n"
    "Ån[g]ra senaste ändringen \n"
    "Lista [h]ela varukatalogen \n"
    "[A]vsluta\n");
}

char ask_question_menu() {
    char choice;
    while (1) {
        print_menu();
        printf("Your choice: ");
        if (scanf(" %c", &choice) == 1) {
            choice = tolower(choice);
            if (strchr("ltrgha", choice)) {
                return choice;
            } else {
                
            }
        } else {
            while (getchar() != '\n'); 
        }
    }
}

void add_item_to_db(item_t *items, int *no_items) {
    if (*no_items >= 16) {
        printf("Database is full. Cannot add more items.\n");
        return;
    }
    item_t new_item = input_item();
    items[*no_items] = new_item;
    (*no_items)++;
}

void remove_item_from_db(item_t *items, int *no_items) {
    if (*no_items == 0) {
        return; 
    }

    int index = ask_question_int("Enter the number of the item that you want to remove: ") - 1;

    if (index < 0 || index >= *no_items) {
        return; 
    }

    free(items[index].name);
    free(items[index].desc);
    free(items[index].shelf);


    for (int i = index; i < (*no_items) - 1; i++) {
        items[i] = items[i + 1];
    }

    (*no_items)--;
}

void event_loop(item_t *db, int *db_siz) {
    while (true) {
        char choice = ask_question_menu();
        switch (choice) {
            case 'g': 
                printf("Not yet implemented!\n");
                break;
            case 'l': 
                add_item_to_db(db, db_siz);
                break;
            case 'r': 
                edit_db(db, *db_siz);
                break;
            case 't': 
                remove_item_from_db(db, db_siz);
                break;
            case 'h': 
                list_db(db, *db_siz);
                break;
            
            default:
                printf("Not an allowed option :( \n");
        }
    }
}

int main(int argc, char *argv[]) {
    char *array1[] = { "Laser", "Polka", "Extra" };
    char *array2[] = { "förnicklad", "smakande", "ordinär" };
    char *array3[] = { "skruvdragare", "kola", "uppgift" };

    item_t db[16];  
    int db_siz = 0;

    
    


    for (int i = db_siz; i < 16; i++) {
        char *name = magick(array1, array2, array3, 3);
        char *desc = magick(array1, array2, array3, 3);
        int price = rand() % 200000;
        char shelf[] = { (char)(rand() % 26 + 'A'), (char)(rand() % 10 + '0'), (char)(rand() % 10 + '0'), '\0' };
        db[db_siz] = make_item(name, desc, price, shelf);
        ++db_siz;
    }

    event_loop(db, &db_siz);

    for (int i = 0; i < db_siz; i++) {
        free(db[i].name);
        free(db[i].desc);
        free(db[i].shelf);
    }

    return 0;
}
