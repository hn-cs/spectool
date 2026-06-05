int func(int num) {
    int i = 0;
    int sum = 0;

    /*@
    loop invariant \at(num,Pre) >= 0 ==> 0 <= num <= \at(num,Pre);
    loop invariant \at(num,Pre) < 0 ==> sum == 0;
    loop invariant \at(num,Pre) < 0 ==> num == \at(num,Pre);
    loop invariant \at(num,Pre) < 0 ==> i == 0;
    loop invariant num >= 0 || num == \at(num,Pre);
    loop invariant i <= 9;
    loop invariant 0 <= sum;
    loop invariant 0 <= i;
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