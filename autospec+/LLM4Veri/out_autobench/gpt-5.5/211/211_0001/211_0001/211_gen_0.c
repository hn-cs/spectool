int func(int num) {
    int i = 0;
    int sum = 0;

    /*@
    loop invariant sum >= 0;
    loop invariant 0 <= i <= 9;
    loop invariant num >= 0 || num == \at(num,Pre);
    loop assigns i, sum, num;
    loop variant num;
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