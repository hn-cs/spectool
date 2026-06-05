/*@
requires y > 0;
requires \valid(r);
requires \valid(q);
ensures x == y * (*q) + (*r);
ensures *r == x % y;
ensures *r < y;
ensures *q == x / y;
assigns *q, *r;
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r) {
    *q = x / y;
    *r = x % y;
}
void main() {
    unsigned q, r;
    div_rem(10, 3, &q, &r);
    // @ assert q == 3;
    // @ assert r == 1;
}