#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtable.h"
#include "linked_list.h"
#include "iterator.h"
#include "ctype.h"
#include "common.h"

#define Delimiters "+-#@()[]{}.,:;!? \t\n\r"

static int cmpstringp(const void *p1, const void *p2)
{
    return strcmp(*(char *const *)p1, *(char *const *)p2);
}

void sort_keys(char *keys[], size_t no_keys)
{
    qsort(keys, no_keys, sizeof(char *), cmpstringp);
}

void complete_ioopm_hash_table_destroy(ioopm_hash_table_t *ht) {
    if (!ht) return;

    if (ioopm_hash_table_size(ht) == 0) {
        ioopm_hash_table_destroy(ht);
        return;
    }

    ioopm_list_t *keys_list = ioopm_hash_table_keys(ht);
    if (!keys_list) {
        ioopm_hash_table_destroy(ht);
        return;
    }

    ioopm_list_iterator_t *iter = ioopm_list_iterator_create(keys_list);
    if (!iter) {
        ioopm_linked_list_destroy(keys_list);
        ioopm_hash_table_destroy(ht);
        return;
    }

    while (ioopm_iterator_has_next(iter)) {
        elem_t key = ioopm_iterator_current(iter);
        if (key.p) {
            free(key.p);
        }
        ioopm_iterator_next(iter);
    }

    if (ioopm_iterator_has_current(iter)) {
        elem_t key = ioopm_iterator_current(iter);
        if (key.p) {
            free(key.p);
        }
    }

    ioopm_iterator_destroy(iter);
    ioopm_linked_list_destroy(keys_list);
    ioopm_hash_table_destroy(ht);
}

void process_word(char *word, ioopm_hash_table_t *ht)
{
    if (!word || strlen(word) == 0) return;

    for (char *p = word; *p; ++p) *p = tolower(*p);

    elem_t key = { .p = word };
    elem_t *lookup_result = ioopm_hash_table_lookup(ht, key);

    if (!lookup_result) 
    {
        ioopm_hash_table_insert(ht, (elem_t) { .p = strdup(word) }, (elem_t) { .i = 1 });
    } 
    else  
    {
        lookup_result->i += 1;
    }
}

void process_file(char *filename, ioopm_hash_table_t *ht)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "This file cannot open: %s\n", filename);
        return;
    }

    char *buf = NULL;
    size_t len = 0;

    while (getline(&buf, &len, f) != -1)
    {
        for (char *word = strtok(buf, Delimiters);
             word && *word;
             word = strtok(NULL, Delimiters))
        {
            process_word(word, ht);
        }
    }

    free(buf); 
    fclose(f);
}


int string_sum_hash(elem_t e)
{
    char *str = e.p;
    int result = 0;
    do
        {
        result += *str;
        }
    while (*++str != '\0');
    return abs(result);
}

bool string_eq(elem_t e1, elem_t e2)
{
    return strcmp(e1.p, e2.p) == 0;
}

// Main function
int main(int argc, char *argv[])
{
    ioopm_hash_table_t *ht = ioopm_hash_table_create(string_sum_hash, string_eq, string_eq);

    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            process_file(argv[i], ht);
        }

        // FIXME NOT GIVEN 
        ioopm_list_t *keys_list = ioopm_hash_table_keys(ht);
        ioopm_list_iterator_t *iter = ioopm_list_iterator_create(keys_list);

        int size = ioopm_hash_table_size(ht);
        if (size == 0)
        {
            printf("No keys found in the hash table of the users text file\n");
            ioopm_iterator_destroy(iter);
            ioopm_linked_list_destroy(keys_list);
            complete_ioopm_hash_table_destroy(ht);
            return 0;
        }

        char **keys = calloc(1, size * sizeof(char *));
        if (!keys)
        {
            fprintf(stderr, "It fails to allocate memory for the keys array\n");
            ioopm_iterator_destroy(iter);
            ioopm_linked_list_destroy(keys_list);
            complete_ioopm_hash_table_destroy(ht);
            return 1;
        }

        for (int i = 0; i < size; ++i)
        {
            elem_t key = ioopm_iterator_current(iter);
            keys[i] = key.p; 
            ioopm_iterator_next(iter);
        }

        ioopm_iterator_destroy(iter);
        ioopm_linked_list_destroy(keys_list); 

        sort_keys(keys, size);

        for (int i = 0; i < size; ++i)
        {
            elem_t *lookup_result = ioopm_hash_table_lookup(ht, (elem_t) {.p = keys[i]});
            if (lookup_result)
            {
                printf("%s: %d\n", keys[i], lookup_result->i);
            }
        }

        free(keys); 
    }
    else
    {
        puts("Usage: freq-count file1 ... filen");
    }

    complete_ioopm_hash_table_destroy(ht); 
    return 0;
}

