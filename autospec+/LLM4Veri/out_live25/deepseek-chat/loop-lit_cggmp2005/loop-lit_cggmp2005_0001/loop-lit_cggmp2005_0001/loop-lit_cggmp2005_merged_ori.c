#include "assert.h"
int main() {
    int i,j;
    i = 1;
    j = 10;
    /*@
    loop invariant i - j == 2 * (j == 10 ? 1 : 0) + 1; // Actually simpler:;
    loop invariant i + j == 11;
    loop invariant 1 <= j;
    loop invariant 1 <= i;
    loop invariant 1 <= i - j;
    loop invariant 0 <= j - i + 2;
    loop assigns j;
    loop assigns i;
    */
    while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }
    // @ assert(j == 6);
    return 0;
}
