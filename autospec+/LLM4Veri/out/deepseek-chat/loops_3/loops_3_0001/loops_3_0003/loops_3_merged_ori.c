#include <stdio.h>
int func(int c) {
    int x = c;
    int y = 0;
    /*@
    loop invariant y + x == c;
    loop invariant 0 <= x;
    loop invariant y == c - x;
    loop invariant x <= c;
    loop assigns y;
    loop assigns x;
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