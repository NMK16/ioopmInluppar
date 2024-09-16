#include <stdio.h>
#include <stdbool.h>
#include <time.h>
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


int main(int argc, char *argv[])
{
  char *array1[] = { "Laser",        "Polka",    "Extra" };
  char *array2[] = { "förnicklad",   "smakande", "ordinär" };
  char *array3[] = { "skruvdragare", "kola",     "uppgift" };

  if (argc < 2)
  {
    printf("Usage: %s number\n", argv[0]);
  }
  else
  {
    item_t db[16]; // Array med plats för 16 varor
    int db_siz = 0; // Antalet varor i arrayen just nu

    int items = atoi(argv[1]); // Antalet varor som skall skapas

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

    for (int i = db_siz; i < 16; ++i)
      {
        char *name = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        char *desc = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
        int price = rand() % 200000;
        char shelf[] = { rand() % ('Z'-'A') + 'A',
                         rand() % 10 + '0',
                         rand() % 10 + '0',
                         '\0' };
        item_t item = make_item(name, desc, price, shelf);

        db[db_siz] = item;
        ++db_siz;
      }

     // Skriv ut innehållet
     for (int i = 0; i < db_siz; ++i)
     {
       print_item(&db[i]);
     }

  }
  return 0;
}
