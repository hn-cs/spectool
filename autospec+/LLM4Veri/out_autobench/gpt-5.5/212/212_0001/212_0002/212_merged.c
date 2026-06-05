/*@
requires 0 <= n <= 92681;
assigns \nothing;
*/
int func(int n) {
    int sum = 0;
    int i = 0;

    /*@
    loop invariant sum == i * (i - 1);
    loop invariant 0 <= i;
    loop assigns sum;
    loop assigns i;
    */
    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}

// write a test
void main() {
    int t = func(10);
    //@ assert t == 30;
}