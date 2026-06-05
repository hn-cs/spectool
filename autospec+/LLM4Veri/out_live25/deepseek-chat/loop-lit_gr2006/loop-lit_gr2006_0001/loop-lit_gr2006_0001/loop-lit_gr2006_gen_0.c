#include "assert.h"
int main() {
    int x,y;
    x = 0;
    y = 0;
    /*@
    loop invariant 0 <= x <= 100;
    loop invariant y == 0 || y == -1;
    loop invariant y >= -1;
    loop assigns x, y;
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
