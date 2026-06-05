#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  unsigned int s = 0;
  /*@
  loop invariant s == 0 ==> s != 0 || s == 0;
  loop invariant s <= UINT_MAX - (unknown() ? 1 : 0);
  loop invariant s < UINT_MAX - (unknown() ? 1 : 0);
  loop invariant s % 2 == 0 || s % 2 == 1;
  loop invariant s > 0 ==> \at(s, Here) > 0;
  loop invariant s == 0 || s >= 1;
  loop invariant s == 0 || s != 0;
  loop invariant s == 0 ==> \at(s, Pre) == 0;
  loop invariant s <= UINT_MAX;
  loop invariant \valid(&s);
  loop invariant \at(s, Pre) == 0;
  loop invariant 0 <= s;
  loop assigns s;
  */
  while (unknown()) {
    if (s != 0) {
      ++s;
    }
    if (unknown()) {
      //@ assert(s == 0);
    }
  }
  return 0;
}
