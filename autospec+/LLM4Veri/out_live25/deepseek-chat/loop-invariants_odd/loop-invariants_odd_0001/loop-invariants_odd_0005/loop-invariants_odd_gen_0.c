#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  unsigned int x = 1;
  /*@
  loop invariant x >= 1;
  loop invariant x % 2 == 1;
  loop invariant x % 2 == 1 || x == 2;
  loop invariant x == 1 + 2 * (count - 1); // where count can be introduced via ghost code
  loop invariant 0 <= x;
  loop assigns x;
  */
  while (unknown()) {
    x += 2;
  }
  // @ assert(x % 2);
  return 0;
}
