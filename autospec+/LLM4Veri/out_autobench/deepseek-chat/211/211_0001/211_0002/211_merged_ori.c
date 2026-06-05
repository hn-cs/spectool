/*@
requires num >= 0;
ensures \result == \sum(0, num, 0);
ensures \result == (num == 0 ? 0 : (num % 10) + \old(func(num / 10)));
*/
int func(int num) {
    int i = 0;
    int sum = 0;

    /*@
    loop invariant num <= \at(num, Pre);
    loop assigns sum;
    loop assigns num;
    loop assigns i;
    */
    while(num>0) {
        i = num%10;
        sum += i;
        num /= 10;
    }
    return sum;
}

// write a test
void main() {
    int t = func(123);
    // @ assert t == 6;
}