#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


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



int main(void)
{
    int buf_siz = 255;
    int read = 0;
    char buf[buf_siz];

    puts("Läs in en sträng:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    puts("Läs in en sträng till:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    return 0;
}
