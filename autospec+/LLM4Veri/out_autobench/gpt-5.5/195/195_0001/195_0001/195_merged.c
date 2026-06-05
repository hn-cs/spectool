#include <stdio.h>

/*@
requires b + c <= INT_MAX;
requires a + c <= INT_MAX;
requires a + b <= INT_MAX;
ensures \result == 1 <==> (a + b > c && a + c > b && b + c > a);
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
int validts(int a, int b, int c) {
    int valid = 0;
    if ((a+b>c) && (a+c>b) && (b+c>a) && 1) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}

void test() {
    int valid = validts(2,3,4);
    //@ assert valid == 1;
}