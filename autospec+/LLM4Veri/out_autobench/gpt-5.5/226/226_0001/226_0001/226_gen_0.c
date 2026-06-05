/*@
requires y != 0;
requires \valid(q);
requires \valid(r);
assigns *q, *r;
ensures *q == x / y;
ensures *r == x % y;
ensures x == y * (*q) + (*r);
ensures *r < y;
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r) {
    *q = x / y;
    *r = x % y;
}

// write a test
void main() {
    unsigned q, r;
    div_rem(10, 3, &q, &r);
    // @ assert q == 3;
    // @ assert r == 1;
}