#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "utils.h"

int read_string(char *buf, int buf_siz) {
    int i = 0;
    int c = 0;

    while (i < buf_siz - 1 && (c = getchar()) != '\n' && c != EOF) {
        buf[i++] = c;
    }

    buf[i] = '\0';

    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    return i;
}

bool not_empty(const char *str) {
    return strlen(str) > 0;
}

bool always_true(const char *str) {
    return true;
}

bool is_number(const char *str) {
    if (*str == '\0') {
        return false;
    }

    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool is_float(const char *str) {
    if (*str == '\0') {
        return false;  
    }

    bool has_digit = false;
    bool has_dot = false;
    int i = 0;

   

    for (i; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (has_dot) {
                return false;  
            }
            has_dot = true;
        } else if (!isdigit(str[i])) {
            return false;  
        } else {
            has_digit = true;
        }
    }

    return has_digit;
}

answer_t ask_question(const char *question, check_func check, convert_func convert) {
    char buffer[100];
    answer_t converted_val;

    while (true) {
        printf("%s", question);

        read_string(buffer, sizeof(buffer));

        if (check(buffer)) {
            converted_val = convert(buffer);
            return converted_val;
        } else {
        }
    }
}

answer_t make_float(const char *str) {
    answer_t result;
    result.float_value = atof(str);
    return result;
}

answer_t convert_int(const char *str) {
    answer_t result;
    result.int_value = atoi(str);
    return result;
}


answer_t convert_string(const char *str) {
    answer_t result;
    result.string_value = strdup(str);
    return result;
}

int ask_question_int(const char *question) {
    answer_t answer = ask_question(question, is_number, convert_int);
    return answer.int_value;
}

double ask_question_float(const char *question) {
    return ask_question(question, is_float, make_float).float_value;
}

char *ask_question_string(const char *question) {
    return ask_question(question, not_empty, convert_string).string_value;
}

char *ask_question_string_empty(const char *question) {
    return ask_question(question, always_true, convert_string).string_value;
}

