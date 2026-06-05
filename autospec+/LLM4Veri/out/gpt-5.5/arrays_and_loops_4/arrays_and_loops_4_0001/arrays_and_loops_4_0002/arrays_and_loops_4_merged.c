#include<limits.h>
/*@
requires 0 <= x;
ensures \result == x;
assigns \nothing;
*/
int test(int x) {
    int a = x;
    int y = 0;
    /*@
    loop invariant y == x - a;
    loop invariant x >= 0 ==> a == x - y;
    loop invariant x >= 0 ==> 0 <= y <= x;
    loop assigns y;
    loop assigns a;
    */
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
    return y;
}
int main() {
    int num = test(3);
    //@ assert num == 3;
    return 0;
}