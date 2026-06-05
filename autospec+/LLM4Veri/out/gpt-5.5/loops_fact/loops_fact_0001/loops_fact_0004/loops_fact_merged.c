#include <stdio.h>
/*@
  axiomatic Factorial {
  logic integer fact(integer n);
  axiom case_n:
    \forall integer n;
    n >= 1 ==> fact(n) == n*fact(n-1);
  axiom case_0:
    fact(0) == 1;
  }
*/
/*@
requires 0 <= n <= 12;
ensures n == 5 ==> \result == 120;
ensures \result >= 1;
ensures \result == fact(n);
assigns \nothing;
*/
int factorial(int n) {
  int i = 1;
  int f = 1;
  /*@
  loop invariant i > 1 ==> f == fact(i - 1);
  loop invariant i == 1 || i <= n + 1;
  loop invariant i == 1 ==> f == 1;
  loop invariant f == fact(i - 1);
  loop invariant \forall integer k; 1 <= k < i ==> fact(k) >= 1;
  loop invariant 1 <= i;
  loop invariant 1 <= f;
  loop assigns i;
  loop assigns f;
  */
  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}
void main() {
  int t = factorial(5);
  //@ assert t == 120;
}