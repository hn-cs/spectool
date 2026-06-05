/*@
   predicate is_periodic(char* x, unsigned int p, unsigned int l) =
      (\forall unsigned int i; 0 <= i < (l-p-1) ==>  x[i] == x[i+p]) && (l%p == 0) || (p == l);
*/
/*@ 
    requires \valid(x+(0..l-1));
    requires l > 0;
    requires p > 0;
    assigns \nothing;
    ensures is_periodic(x,p,l) ==> \result == 1;
    ensures !is_periodic(x,p,l) ==> \result == 0;
*/
/*@
requires p > 0;
requires l > 0;
requires \valid_read(x+(0..l-1));
ensures \result == 1 <==> is_periodic((char*)x,p,l);
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
unsigned has_period(const char x[], unsigned int p, unsigned l) {
    if (p == l) return 1;
    if ((l % p) != 0) return 0;
        /*@
            loop assigns i;
            loop invariant \forall unsigned int j; 0 <= j < i ==> (x[j] == x[j+p]);
            loop invariant i <= l-p-1;
            loop invariant i >= 0;
        */
        /*@
        loop invariant l - p - 1 - i;
        loop invariant i <= l - p - 1;
        loop invariant \forall unsigned int j; 0 <= j < i ==> x[j] == x[j+p];
        loop invariant 0 <= i;
        loop assigns i;
        */
        for (unsigned i = 0 ; i < l-p-1 ; ++i) {
            if (x[i] != x[i + p])
                return 0;
        }     
    return 1; 
}
unsigned per(const char x[], unsigned l) {
    unsigned int p;
    /*@
    loop invariant 1 <= p <= l;
    loop invariant \forall unsigned int q; 1 <= q < p ==> !is_periodic((char*)x,q,l);
    loop assigns p;
    loop variant l - p;
    */
    for(p = 1; p < l; ++p) {
        if(has_period(x,p,l))
            return p;
    }
    // @ assert is_periodic(x,p,l);
    return p;
}