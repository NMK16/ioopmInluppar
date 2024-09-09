#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"
typedef bool is_numberf(char);

int read_string(char *buf, int buf_siz)
{
    int i = 0;
    int c;
    do{
        c = getchar();
        buf[i] = c;
        if ((c != '\n')){
            i++;
        }
    }
    while (i < buf_siz - 1 && (c != '\n') && c != EOF);
    if (i == buf_siz - 1) {
        do{
            (c = getchar());
        }
        while (c != '\n' && c != EOF);
    }

    buf[i] = '\0';

    return i;
}

bool is_number(char *str)
{
    for(int i = 0; i < strlen(str); i++){
        if(!(isdigit(str[i])) || ((strlen(str) <= 1) && str[0] == '-')){
            return false;
        }
    }
    return true;
}

int ask_question_int(char *question)
{

  int result = 0;
  int conversions = 0;
  do
    {
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      int c;
      do
        {
          c = getchar();
        }
      while (c != '\n' && c != EOF);
      putchar('\n');
    }
  while (conversions < 1);
  return result;
}

char *ask_question_string(char *question, char *buf, int buf_siz){
    int read = 0;
    printf("%s", question);
    read = read_string(buf, buf_siz);
    if (read == 0){
        printf("Du svarade inte, testa igen\n");
        ask_question_string(question, buf, buf_siz);
    }
    else{
        return strdup(buf);
    }
    return 0;
}

char *ask_question_string(char *question, is_numberf *f, int buf_siz){
    int read = 0;
    printf("%s", question);
    read = read_string(buf, buf_siz);
    if (read == 0){
        printf("Du svarade inte, testa igen\n");
        ask_question_string(question, buf, buf_siz);
    }
    else{
        return strdup(buf);
    }
    return 0;
}