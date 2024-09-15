#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* void print(char *str)
{
   for (int i = 0; i < strlen(str); i++){
      putchar(str[i]);
   }
   
} */

void print(char *str)
{
  char *start = str;
  char *end = start + strlen(str)-1;
   for (; start <= end; start++){
      putchar(*start);
   }
   
}

int main(void)
{
  char *str = "hello";
  print(str);
/*   int x = 7;
  int y = 42;
  swap(&x, &y);
  printf("%d, %d\n", x, y);
  return 0; */
}   