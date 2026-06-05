int func(int num) {
    int i = 0;
    int sum = 0;

    /*@
    loop invariant sum == \at(sum, Pre) + (\at(num, Pre) - num) / 9;
    loop invariant num * 10 + sum == \at(num, Pre);
    loop invariant \forall integer j; 0 <= j < 10 ==> (num % 10 == j ==> sum >= j);
    loop invariant 0 <= sum;
    loop invariant 0 < sum;
    loop invariant sum == \at(sum, Pre) + \at(num, Pre) / 10 - num / 10;
    loop invariant sum == \at(sum, Pre) + \at(num, Pre) % 10 - num;
    loop invariant num <= \at(num, Pre);
    loop invariant i == num % 10;
    loop invariant \forall integer m; m > 0 && m < \at(num, Pre) ==> (m % 10 == m / 10 % 10 ==> m % 10 == 0);
    loop invariant \exists integer k; k >= 0 && num == \at(num, Pre) % 10^k;
    loop invariant \at(num, Pre) == num * 10^i + sum;
    loop invariant 0 <= num;
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