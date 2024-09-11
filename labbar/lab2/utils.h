#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"
typedef bool check_func(char *);
typedef union { 
  int   int_value;
  float float_value;
  char *string_value;
} answer_t;
typedef answer_t convert_func(char *);
extern char *strdup(const char *);

int read_string(char *buf, int buf_siz);

bool is_number(char *str);

bool is_float(char *str);

answer_t make_float(char *);

bool not_empty(char *str);

answer_t ask_question(char *question, check_func *check, convert_func *convert);

int ask_question_int(char *question);

char *ask_question_string(char *question);

double ask_question_float(char *question);

#endif