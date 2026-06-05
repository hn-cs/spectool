/*@
requires base >= 0;
requires height >= 0;
requires (integer)base * (integer)height <= 2147483647;
assigns \nothing;
ensures \result == ((integer)base * height) / 2;
*/
int area(int base, int height){
    int res = (base *  height)/2;
    return res;
}
int main() {
    int a = area(4, 5);
    // @ assert a == 10;
}