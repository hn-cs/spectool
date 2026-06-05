#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int xa = unknown();
  int ya = unknown();
  if (!(xa + ya > 0)) return 0;
  /*@
  loop invariant xa + ya == \at(xa + ya, Pre);
  loop invariant xa <= \at(xa, Pre);
  loop invariant ya >= \at(ya, Pre);
  loop invariant xa + ya > 0;
  loop invariant xa;
  loop invariant xa + ya == \at(xa + ya, Pre);
  loop invariant \old(ya) - \old(xa) + xa <= ya;
  loop invariant 0 <= xa;
  loop assigns ya;
  loop assigns xa;
  */
  while (xa > 0) {
    xa--;
    ya++;
  }
  // @ assert(ya >= 0);
  return 0;
}
