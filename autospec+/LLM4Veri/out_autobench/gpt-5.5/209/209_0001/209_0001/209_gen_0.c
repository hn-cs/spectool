#include <stdio.h>

int factorial(int n) {

  int i = 1;
  int f = 1;

  /*@
  loop invariant i >= 1;
  loop invariant n >= 1 ==> i <= n + 1;
  loop invariant n < 1 ==> i == 1;
  loop invariant f == \product(integer k; 1 <= k < i; k);
  loop assigns i, f;
  loop variant n - i + 1;
  */
  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}

// write a test
void main() {
  int t = factorial(5);
  // @ assert t == 120;
}