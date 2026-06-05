#include "assert.h"
int main() {
    int x,y;
    x = 0;
    y = 0;
    /*@
    loop invariant y == 0 || y == -1;
    loop invariant x <= 100;
    loop invariant 0 <= x;
    loop invariant -1 <= y;
    loop assigns y;
    loop assigns x;
    */
    while (1) {
        if (x < 50) {
            y++;
        } else {
            y--;
        }
        if (y < 0) break;
        x++;
    }
    // @ assert(x == 100);
    return 0;
}
