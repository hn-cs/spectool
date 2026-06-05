/*@
requires y > 0;
requires \valid(r);
ensures x == \old(*r) + \result * y;
ensures \result == x / y;
ensures *r == x % y;
*/
int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant x == *r + d * y;
    loop invariant 0 <= d;
    loop assigns d;
    loop assigns *r;
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}
int main() {
    int a = 3;
    int num = fun(1, 2, &a);
    // @ assert a == 1;
    // @ assert num == 0;
    return 0;
}