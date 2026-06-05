#include <assert.h>

int unknown1();
int unknown2();
int unknown3();

/*
 * "fragtest_simple" from InvGen benchmark suite
 */

int main(){
  int i, pvlen;
  int t;
  int k = 0;
  int n;
  i = 0;

  //  pkt = pktq->tqh_first;
  /*@
  loop invariant 0 <= i;
  loop assigns i;
  */
  while (unknown1())
    i = i + 1;
  
  if (i > pvlen) {
    pvlen = i;
  } else {

  }
  i = 0;

  /*@
  loop invariant i == k;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns t;
  loop assigns k;
  loop assigns i;
  */
  while (unknown2()) {
    t = i;
    i = i + 1;
    k = k + 1;
  }
  /*@
  loop invariant i == k;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns \nothing;
  */
  while (unknown3());

  int j = 0;
  n = i;
  while (1) {
    // @ assert(k >= 0);
    k = k - 1;
    i = i - 1;
    j = j + 1;
    if (j < n) {
    } else {
      break;
    }
  }
  return 0;
}
