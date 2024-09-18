#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lab2/utils.h"

struct item
{
  char *namn;
  char *desc;
  int pris;
  char *lager;
};

typedef struct item item_t;

void print_item(item_t *item){
  char *namn = item->namn;
  char *desc = item->desc;
  int pris = item->pris;
  char *lager = item->lager;

  printf("Name: %s\nDesc: %s\nPrice: %d.%d\nShelf: %s\n", namn, desc, pris/100, pris%100, lager);
}

item_t make_item(char *namn, char *desc, int pris, char *lager){
  item_t item = {namn, desc, pris, lager};
  return item;
}

bool is_validShelf(char *str)
{
    for(int i = 0; i < strlen(str); i++){
      if (!isdigit(str[0]) && isdigit(str[1])){
        continue;
      }
      else if (isdigit(str[0])){
        return false;
      }
      if(!(isdigit(str[i])) || ((strlen(str) <= 1) && str[0] == '-')){
            return false;
      }
    }
    return true;
}

char *magick(char *ary1[], char *ary2[], char *ary3[], int size){
  char buf[255];
  char *first = ary1[rand()%2];
  strcpy(buf, first);
  char *second = ary2[rand()%2];
  strcat(buf, "-");
  strcat(buf, second);
  char *third = ary3[rand()%2];
  strcat(buf, " ");
  strcat(buf, third);
  strcat(buf, "\0");
  return strdup(buf);
}

char *ask_question_shelf(char *question){
  return ask_question(question, is_validShelf, (convert_func *) strdup).string_value;
}

item_t input_item(){
  char *name = ask_question_string("Put name: \n");
  char *desc = ask_question_string("Put desc: \n");
  int price = ask_question_int("Put price: \n");
  char *lager = ask_question_shelf("Put lager: \n");
  return make_item(name, desc, price, lager);
}

void list_db(item_t *items, int no_items){
  for (int i = 0; i < no_items; i++)
    {
      printf("%d. ", i+1);
      print_item(&items[i]);
    }
}

void edit_db(item_t *items){
  int num = ask_question_int("Which item do you want to edit?");
  print_item(&items[num-1]);
  items[num-1] = input_item();
}

void print_menu(){
    printf("\n[L]ägga till en vara\n[T]a bort en vara\n[R]edigera en vara\nÅn[g]ra senaste ändringen\nLista [h]ela varukatalogen\n[A]vsluta\n");
}


char ask_question_menu(){
  print_menu();
  char *choice = ask_question_string("Choice: ");
  printf("\n");
  char *valid = "LlTtRrGgHhAa";
  for (int i = 0; i < strlen(valid); i++){
    if (*choice == valid[i] && strlen(choice) == 1){
      break;
    }
    else if (i == strlen(valid) - 1){
      printf("Answer is invalid!\n");
      ask_question_menu();
    }
  }
  return toupper(*choice);
}

item_t *add_item_to_db(item_t *items, int *no_items){
  items[*no_items] = input_item();
  (*no_items)++;
  return items;
}

item_t *remove_item_from_db(item_t *items, int *no_items){
  list_db(items, *no_items);
  int num = ask_question_int("Which item do you want to remove?");
  print_item(&items[num-1]);
  for (int i = num; i < *no_items; i++){
    items[i-1] = items[i];
  }
  (*no_items)--;
  return items;
}

void event_loop(item_t *items, int *no_items){
  char choice = ask_question_menu();
  if (choice == 'L' || choice == 'l'){
    add_item_to_db(items, no_items);
  }
  else if(choice == 'T' || choice == 't'){
    remove_item_from_db(items, no_items);
  }
  else if(choice == 'R' || choice == 'r'){
    edit_db(items);
  }
  else if(choice == 'G' || choice == 'g'){
    printf("Not yet implemented!\n");
  }
  else if(choice == 'H' || choice == 'h'){
    list_db(items, *no_items);
  }
  else if(choice == 'A' || choice == 'a'){
    exit(1);
  }
  event_loop(items, no_items);
}


int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0; // Antalet varor i arrayen just nu
    
    int items = atoi(argv[1]); // Antalet varor som skall skapas

    srand(time(NULL));
    if (items > 0 && items <= 16)
    {
      for (int i = 0; i < items; ++i)
      {
        // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
        item_t item = input_item();
        db[db_siz] = item;
        ++db_siz;
      }
    }
    else
    {
      puts("Sorry, must have [1-16] items in database.");
      return 1; // Avslutar programmet!
    }

    event_loop(db, &db_siz);
  }
  return 0;
}