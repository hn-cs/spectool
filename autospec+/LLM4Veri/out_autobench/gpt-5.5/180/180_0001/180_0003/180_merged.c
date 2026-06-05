/*@
requires -2147483648 <= (integer)base * height <= 2147483647;
ensures \result == (base * height) / 2;
assigns \nothing;
*/
int area(int base, int height){
    int res = (base *  height)/2;
    return res;
}

int main() {
    int a = area(4, 5);
    //@ assert a == 10;
    return 0;
}
