/*@
requires \valid(a) && \valid(b);
requires \separated(a, b);
ensures *b == \min(\old(*a), \old(*b));
ensures *a == \max(\old(*a), \old(*b));
assigns *a, *b;
*/
void max_ptr(int* a, int* b){
    if(*a < *b){
        int tmp = *b;
        *b = *a;
        *a = tmp;
    }
}
int main(){
    int x = 10, y = 20;
    max_ptr(&x, &y);
    //@ assert x == 20 && y == 10;
    return 0;
}