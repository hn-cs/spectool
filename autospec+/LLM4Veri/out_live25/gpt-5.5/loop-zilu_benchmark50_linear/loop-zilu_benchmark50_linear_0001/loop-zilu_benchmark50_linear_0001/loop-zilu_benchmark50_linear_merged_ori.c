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
  loop invariant xa;
  loop invariant xa >= 0 ==> ya < \at(xa,LoopEntry) + \at(ya,LoopEntry);
  loop invariant xa + ya == \at(xa,LoopEntry) + \at(ya,LoopEntry);
  loop invariant 0 < \at(xa,LoopEntry) + \at(ya,LoopEntry);
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
