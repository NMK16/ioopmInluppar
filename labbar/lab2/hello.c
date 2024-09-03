#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_number(char *str)
{
    for(int i = 0; i < strlen(str); i++){
        if(!(isdigit(str[i])) || ((strlen(str) <= 1) && str[0] == '-')){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);
     if(is_number(argv[1])){
         for(int i = 1; i <= input; i++){
            if (i % 3 == 0 && i % 5 == 0){
                printf("%s, ", "Fizz Buzz");
            }
            else if(i % 3 == 0){
                printf("%s, ", "Fizz");
            }
            else if (i % 5 == 0){
                printf("%s, ", "Buzz");
            }
            else {
                printf("%d, ", i);
            }
        }
     }

    return 0;
}

