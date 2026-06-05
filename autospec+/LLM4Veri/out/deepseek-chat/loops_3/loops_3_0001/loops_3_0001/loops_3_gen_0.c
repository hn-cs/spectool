#include <stdio.h>
int func(int c) {
    int x = c;
    int y = 0;
    /*@
    loop invariant 0 <= x <= c;
    loop invariant y == c - x;
    loop invariant x >= 0;
    loop assigns x, y;
    */
    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}
void main() {
    int t = func(5);
    // @ assert t == 5;
}