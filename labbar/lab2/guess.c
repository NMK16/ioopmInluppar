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
    int buf_siz = 255;
    char namn[buf_siz];
    int answerN;
    ask_question_string("Skriv in ditt namn: ", namn, buf_siz);
    printf("Du %s, jag tänker på ett tal ... ", namn);
    answerN = ask_question_int("kan du gissa vilket?");
    for(int i = 1; i <= 15; i++){
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
            answerN = ask_question_int("För litet!");
        }
        else if (answerN > tal){
            answerN = ask_question_int("För stort!");
        }
    }

    return 0;
}
