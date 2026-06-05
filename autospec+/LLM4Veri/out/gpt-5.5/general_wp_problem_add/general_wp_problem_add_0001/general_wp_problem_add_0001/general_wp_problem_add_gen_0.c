#include <limits.h>
/*@
requires INT_MIN <= x + y <= INT_MAX;
ensures \result == x + y;
assigns \nothing;
*/
int add(int x, int y) {
    return x+y;
}
void foo() {
    int a = add(1, 43);
    // @ assert a == 44;
    int b = add(INT_MAX, INT_MAX);
}