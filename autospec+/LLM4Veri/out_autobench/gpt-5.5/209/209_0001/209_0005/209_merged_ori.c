#include <stdio.h>

int factorial(int n) {

  int i = 1;
  int f = 1;

  /*@
  loop invariant n < 1 ==> f == 1;
  loop invariant i >= 3 ==> f % 2 == 0;
  loop invariant i > 1 ==> n >= 1;
  loop invariant i <= n + 1 || n < 1;
  loop invariant i <= 2 ==> f == 1;
  loop invariant f == 1 || i >= 3;
  loop invariant n >= 1 ==> i <= n + 1;
  loop invariant n == \at(n,LoopEntry);
  loop invariant n < i ==> (i == n + 1 || n < 1);
  loop invariant n < 1 ==> i == 1;
  loop invariant n - i + 1;
  loop invariant i == 1 ==> f == 1;
  loop invariant i <= n ==> 1 <= n;
  loop invariant f == \product(integer k; 1 <= k < i; k);
  loop invariant \forall integer k; 1 <= k < i ==> k <= n;
  loop invariant 1 <= i;
  loop assigns i;
  loop assigns f;
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