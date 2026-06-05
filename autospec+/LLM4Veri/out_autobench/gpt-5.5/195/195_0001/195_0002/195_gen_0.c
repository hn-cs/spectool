#include <stdio.h>

/*@
requires INT_MIN <= a + b <= INT_MAX;
requires INT_MIN <= a + c <= INT_MAX;
requires INT_MIN <= b + c <= INT_MAX;
assigns \nothing;
ensures \result == 0 || \result == 1;
ensures \result == 1 <==> (a + b > c && a + c > b && b + c > a);
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
    // @ assert valid == 1;
}