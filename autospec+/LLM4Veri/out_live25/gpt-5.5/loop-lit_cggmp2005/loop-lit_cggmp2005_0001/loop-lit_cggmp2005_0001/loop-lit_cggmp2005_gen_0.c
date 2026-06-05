#include "assert.h"
int main() {
    int i,j;
    i = 1;
    j = 10;
    /*@
    loop invariant 2*j + i == 21;
    loop invariant i <= j + 3;
    loop invariant i >= 1;
    loop invariant j <= 10;
    loop assigns i, j;
    loop variant j - i + 1;
    */
    while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }
    // @ assert(j == 6);
    return 0;
}
