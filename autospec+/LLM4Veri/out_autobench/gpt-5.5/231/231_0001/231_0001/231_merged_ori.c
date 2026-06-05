/*@
requires \valid(b);
requires \valid(a);
requires \separated(a, b);
ensures *b == \old(*a);
ensures *a == \old(*b);
assigns *a, *b;
*/
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 37;
    int b = 91;
    swap(&a, &b);
    // @ assert a == 91;
    // @ assert b == 37;
}