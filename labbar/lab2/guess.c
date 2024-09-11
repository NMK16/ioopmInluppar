#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main(void)
{
    srandom(time(NULL));
    int tal = random()%1000+1;
    printf("%d\n", tal);
    int answerN;
    char* namn = ask_question_string("Skriv in ditt namn: ");
    printf("Du %s, jag tänker på ett tal ... kan du gissa vilket?\n", namn);
    for(int i = 1; i <= 15; i++){
        answerN = ask_question_int("");
        if (i == 15){
            printf("Nu har du slut på gissningar! Jag tänkte på %d!\n", tal);
            break;
        }
        if (answerN == tal){
            printf("%s", "Bingo!\n");
            printf("Det tog %s %d gissningar att komma fram till %d\n", namn, i, tal);
            break;
        }
        else if (answerN < tal){
            printf("%s", "För litet!\n");
        }
        else if (answerN > tal){
            printf("%s", "För stort!\n");
        }
    }

    return 0;
}
