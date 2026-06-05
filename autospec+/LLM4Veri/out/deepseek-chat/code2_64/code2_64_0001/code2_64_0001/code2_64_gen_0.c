int main() {
    int x = 1;
    int y = 0;
    /*@
    loop invariant 0 <= x <= 11;
    loop invariant y == 10 - (x - 1);
    loop invariant x >= 1;
    loop assigns x, y;
    */
    while (x <= 10) {
        y = 10 - x;
        x = x +1;
    }
    // @ assert y < 10;
}