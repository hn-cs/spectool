#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int x = unknown();
  int y = unknown();
  if (!(x<y)) return 0;
  /*@
  loop invariant x <= y + 25;
  loop invariant x - y <= 24;
  loop invariant x < y || x - y <= 16 + 7;
  loop invariant x < y ==> x - y <= -1;
  loop invariant x < y ==> y >= x + 1;
  loop invariant x >= y ==> y <= x;
  loop invariant x >= y ==> 0 <= x - y;
  loop invariant x >= y ==> x - y < 24;
  loop invariant y - x >= -23;
  loop invariant y >= x - 24;
  loop invariant y <= INT_MAX;
  loop invariant y <= INT_MAX || x <= INT_MAX;
  loop invariant x >= y ==> y >= x - 23;
  loop invariant x >= y ==> x <= y + 23;
  loop invariant x >= y ==> x - y <= 23;
  loop invariant x <= y || x <= y + 23;
  loop invariant x <= y + 24;
  loop invariant x <= y + 23;
  loop invariant x <= INT_MAX;
  loop invariant x < y || (x >= y && x <= y + 23);
  loop invariant x < y ==> y - x >= 1;
  loop invariant x < y ==> x <= y;
  loop invariant x < y ==> x + 1 <= y;
  loop invariant x - y <= 23;
  loop invariant x - y < 24;
  loop invariant x - 23 <= y;
  loop invariant INT_MIN <= y;
  loop invariant INT_MIN <= y || y <= INT_MAX;
  loop invariant INT_MIN <= y || x <= INT_MAX;
  loop invariant INT_MIN <= y && y <= INT_MAX;
  loop invariant INT_MIN <= x;
  loop invariant INT_MIN <= x || y <= INT_MAX;
  loop invariant INT_MIN <= x || x <= INT_MAX;
  loop invariant INT_MIN <= x || INT_MIN <= y;
  loop invariant INT_MIN <= x && x <= INT_MAX;
  loop invariant INT_MIN < y;
  loop invariant -23 <= y - x;
  loop assigns y;
  loop assigns x;
  */
  while (x<y) {
    if ((x<0 && y<0)) {
      x=x+7; y=y-10;
    }
    if ((x<0 && y>=0)) {
      x=x+7; y=y+3;
    } else {
      x=x+10; y=y+3;
    }
  }
  // @ assert(x >= y && x <= y + 16);
  return 0;
}
