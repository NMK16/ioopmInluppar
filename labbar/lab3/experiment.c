#include <stdio.h>
#include <stdlib.h>
#include "../lab2/utils.h"

int main(int argc, char *argv[])
{
    int buf_size = 255;
    char answer[buf_size];

    ask_question_string("Mata in ett tal: ");
    if(is_number(atoi(answer))){
        return atoi(answer);
    }
    else{
        main(0, "");
    }
    return 0;
}
