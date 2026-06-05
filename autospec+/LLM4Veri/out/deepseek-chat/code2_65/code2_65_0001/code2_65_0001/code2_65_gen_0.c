int main() {
    int x = 1;
    int y = 0;
    /*@
    loop invariant 0 <= x <= 101;
    loop invariant y == 100 - x + 1;
    loop invariant x >= 1;
    loop assigns x, y;
    */
    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }
    // @ assert y >= 0;
}