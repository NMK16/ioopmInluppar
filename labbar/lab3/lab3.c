#include <stdio.h>
#include <stdlib.h>
typedef int int_fold_func(int, int);

/// Den intressanta delen av programmet
int fib(int num)
{
  if (num == 1 || num == 2){
    return 1;
  }
  else{
    return fib(num-1) + fib(num-2);
  }

  return 0;
}

int fib2(int num)
{
  int ppf = 0; // the two given fib values
  int pf  = 1;

  for (int i = 1; i < num; ++i)
  {
    int tmp = pf;
    pf = ppf + pf;
    ppf = tmp;
  }

  return pf;
}

int foldl_int_int(int numbers[], int numbers_siz, int_fold_func *f)
{
  int result = 0;

  // Loopa över arrayen och för varje element e utför result = f(result, e)
  for (int i = 0; i < numbers_siz; ++i)
  {
    result = f(result, numbers[i]);
  }

  return result;
}

int add(int a, int b)
{
  return a + b;
}



long sum(int numbers[], int numbers_siz)
{
  return foldl_int_int(numbers, numbers_siz, add);
}
  /// Den ointressanta main()-funktionen
int main(int argc, char *argv[])
{ 
  int test[] = {2, 2, 2, 2, 3};
    printf("%d", sum(test, 5));
  
  return 0;
}