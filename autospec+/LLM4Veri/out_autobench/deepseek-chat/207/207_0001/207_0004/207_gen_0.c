#include <stdio.h>

/*@
ensures c >= 0 ==> \result == c;
ensures c < 0 ==> \result == 0;
ensures \result >= 0;
assigns \nothing;
*/
int func(int c) {
    int x = c;
    int y = 0;

    /*@
    loop invariant x == c - y;
    loop invariant x <= c;
    loop invariant x + y == c;
    loop invariant 0 <= y;
    loop assigns y;
    loop assigns x;
    */
    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}

// write a test
void main() {
    int t = func(5);
    // @ assert t == 5;
}