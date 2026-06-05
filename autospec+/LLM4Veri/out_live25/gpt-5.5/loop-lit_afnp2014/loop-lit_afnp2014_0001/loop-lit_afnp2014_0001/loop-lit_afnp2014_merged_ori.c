#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int x = 1;
    int y = 0;
    /*@
    loop invariant y <= x;
    loop invariant y <= 1000;
    loop invariant x == 1 + (y * (y - 1)) / 2;
    loop invariant 1000 - y;
    loop invariant 0 <= y;
    loop assigns y;
    loop assigns x;
    */
    while (y < 1000 && unknown()) {
        x = x + y;
        y = y + 1;
    }
    // @ assert(x >= y);
    return 0;
}
