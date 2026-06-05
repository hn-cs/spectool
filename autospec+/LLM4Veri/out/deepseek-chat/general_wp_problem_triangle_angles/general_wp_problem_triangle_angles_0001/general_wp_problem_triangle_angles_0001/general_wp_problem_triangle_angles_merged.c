/*@
requires a+b+c != 180 ==> \result == 0;
requires a > 0 && b > 0 && c > 0 ==> a+b+c == 180 ==> \result == 1;
requires a <= 0 || b <= 0 || c <= 0 ==> \result == 0;
requires \valid(&a) && \valid(&b) && \valid(&c); // Not needed as they are ints;
ensures \result == 1 <==> (a > 0 && b > 0 && c > 0 && a+b+c == 180);
ensures \result == 0 <==> (a <= 0 || b <= 0 || c <= 0 || a+b+c != 180);
assigns \nothing;
*/
int triangle(int a, int b, int c) {
    if ((a+b+c == 180) && a > 0 && b > 0 && c > 0) {
        return 1;
    } else {
        return 0;
    }
}
void check_validity() {
    int res = triangle(90, 45, 45);
    //@ assert res == 1;
    res = triangle(90, 145, 145);
    //@ assert res == 0;
}