#include <stdio.h>
/*@
requires -2147483648 <= b + c <= 2147483647;
requires -2147483648 <= a + c <= 2147483647;
requires -2147483648 <= a + b <= 2147483647;
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