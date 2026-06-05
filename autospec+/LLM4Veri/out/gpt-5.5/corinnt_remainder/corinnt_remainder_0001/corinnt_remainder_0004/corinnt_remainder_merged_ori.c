/*@
requires y != 0;
requires \valid(r);
requires \valid(q);
ensures x == y * (*q) + (*r);
ensures *r == x % y;
ensures *r < y;
ensures *q == x / y;
assigns *q, *r;
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