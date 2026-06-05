#include "assert.h"
int main() {
    int i,j;
    i = 1;
    j = 10;
    /*@
    loop invariant j < 10 || i == 11 - j;
    loop invariant j <= i;
    loop invariant j <= 10;
    loop invariant j <= 10 || j < i;
    loop invariant j < i;
    loop invariant j < 10;
    loop invariant i == 11 - j;
    loop invariant i - j == 0;
    loop invariant i + j == 11;
    loop invariant i + 2*j == 3;
    loop invariant i % 2 == 1;
    loop invariant i % 2 == 1 || j == -1;
    loop invariant \at(i, Pre) + 2*(10 - j) == i;
    loop invariant 1 <= j;
    loop invariant 1 <= i;
    loop invariant 1 < j;
    loop assigns j;
    loop assigns i;
    */
    while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }
    //@ assert(j == 6);
    return 0;
}
