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
  srandom(time(NULL));
  int tal = random()%2;
  char buf[255];
  char *first = ary1[random()%2];
  char *second = ary2[random()%2];
  char *third = ary3[random()%2];
  int i = 0;
  while(i < )
  buf[strlen(first)] = '-';
  char *second = ary2[random()%2];
  for (int i = strlen(first)+1; i < strlen(second) + strlen(first)+1; i++){
    buf[i] = first[i];
  }
  buf[strlen(second)] = ' ';
  char *third = ary3[random()%2];
  for (int i = strlen(second)+1; i < strlen(third)+ strlen(second)+1; i++){
    buf[i] = first[i];
  }
  buf[strlen(third)] = '\0';
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

  char *str = magick(array1, array2, array3, 3); // 3 = längden på arrayerna

  puts(str); // Polka-ordinär skruvdragare
  return 0;
}
