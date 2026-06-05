int main() {
    int x = 1;
    int y = 0;
    /*@
    loop invariant y == 100 - x + 1;
    loop invariant x + y == 101;
    loop invariant 0 <= y <= 100;
    loop invariant y <= 100 - x;
    loop invariant x <= 101;
    loop invariant 1 <= x;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }
    // @ assert y >= 0;
}