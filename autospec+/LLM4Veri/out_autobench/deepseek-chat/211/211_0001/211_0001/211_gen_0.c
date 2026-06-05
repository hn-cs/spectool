int func(int num) {
    int i = 0;
    int sum = 0;

    /*@
    loop invariant 0 <= num <= \at(num, Pre);
    loop invariant sum == (\at(num, Pre) - num) / 9 * 9 + (\at(num, Pre) % 9 - num % 9 + 9) % 9;
    loop invariant sum == (\at(num, Pre) - num) % 9;
    loop invariant sum + num % 10 == (\at(num, Pre) % 9);
    loop invariant \forall integer k; 0 <= k < 10 ==> sum == (\at(num, Pre) - num) % 9;
    loop assigns i, sum, num;
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