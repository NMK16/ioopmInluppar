#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>

typedef union {
    int   int_value;
    float float_value;
    char *string_value;
} answer_t;

typedef bool (*check_func)(const char *);     
typedef answer_t (*convert_func)(const char *); 

extern char *strdup(const char *);
int read_string(char *buf, int buf_siz);
bool is_number(const char *str);
bool is_float(const char *str);
answer_t make_float(const char *str); 
bool not_empty(const char *str);
answer_t ask_question(const char *question, check_func check, convert_func convert);
char *ask_question_string(const char *question);
int ask_question_int(const char *question);
double ask_question_float(const char *question);

#endif /* __UTILS_H__ */