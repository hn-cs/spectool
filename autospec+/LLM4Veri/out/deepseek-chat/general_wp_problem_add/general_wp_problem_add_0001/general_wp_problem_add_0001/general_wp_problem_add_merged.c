#include <limits.h>
/*@
requires x + y >= INT_MIN;
requires x + y <= INT_MAX;
ensures \result == x + y;
assigns \nothing;
*/
int add(int x, int y) {
    return x+y;
}
void foo() {
    int a = add(1, 43);
    //@ assert a == 44;
    int b = add(INT_MAX, INT_MAX);
}