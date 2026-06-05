#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  unsigned int x = 5;
  /*@
  loop assigns x;
  */
  while (unknown()) {
    x += 8;
  }
  return 0;
}
