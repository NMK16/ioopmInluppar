#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"

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

bool is_float(char *str)
{
    int pointCount = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!(isdigit(str[i])) || ((strlen(str) <= 1) && str[0] == '-')){
            if (i == '.' && pointCount == 0){
                pointCount++;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool not_empty(char *str)
{
  return strlen(str) > 0;
}

char *ask_question_string(char *question)
{
  return ask_question(question, not_empty, (convert_func *) strdup).string_value;
}

int ask_question_int(char *question)
{
  answer_t answer = ask_question(question, is_number, (convert_func *) atoi);
  return answer.int_value; // svaret som ett heltal
}

answer_t make_float(char *str)
{
  return (answer_t) { .float_value = atof(str) };
}

double ask_question_float(char *question)
{
  return ask_question(question, is_float, make_float).float_value;
}

answer_t make_number(char *str)
{
    answer_t answ;
    answ.int_value = atoi(str);
    answ.string_value = str;
    return answ;
}

answer_t ask_question(char *question, check_func *check, convert_func *convert){
    int read = 0;
    int buf_siz = 255;
    char buf[buf_siz];
    printf("%s", question);
    read = read_string(buf, buf_siz);
    if (read == 0){
        printf("Du svarade inte, testa igen\n");
        return ask_question(question, is_number, convert);
    }
    else{
        if (check(buf)){
            return convert(buf);
        }
        else{
            return ask_question(question, is_number, convert);
        }
    }
}