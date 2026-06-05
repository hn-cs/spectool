/*@
requires y > 0 && x < UINT_MAX / y; // Prevent overflow issues, but for ACSL we want basic correctness
requires y != 0;
requires \valid(q) && \valid(r);
ensures *q == x / y;
ensures *r == x % y;
ensures *q * y + *r == x;
ensures 0 <= *r < y;
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r){
     *q = x / y ;
     *r = x % y ;
}
int main() {
    unsigned x = 10, y = 3;
    unsigned q, r;
    div_rem(x, y, &q, &r);
    // @ assert q == 3 && r == 1;
    return 0;
}