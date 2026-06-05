/*@
requires y != 0u;
requires \valid(q) && \valid(r);
ensures x == (*q) * y + (*r);
ensures *r == x % y;
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