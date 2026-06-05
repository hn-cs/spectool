/*@
requires \valid(a);
requires \valid_read(b);
requires -2147483648 <= *a + *b <= 2147483647;
assigns *a;
ensures *a == \old(*a) + \old(*b);
ensures \result == *a;
ensures *b == \old(*b);
*/
int incr_a_by_b(int* a, int const* b){
    *a += *b;
    return *a;
}

// write a test
void main() {
    int a = 10;
    int b = 20;
    incr_a_by_b(&a, &b);
    // @ assert a == 30;
    // @ assert b == 20;
}