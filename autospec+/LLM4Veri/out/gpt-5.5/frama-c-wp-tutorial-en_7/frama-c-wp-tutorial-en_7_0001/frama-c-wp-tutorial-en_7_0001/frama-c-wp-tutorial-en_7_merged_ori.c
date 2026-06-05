/*@
requires \valid_read(b);
requires \valid(a);
ensures \old(*b) == 0 ==> *a == \old(*a);
ensures \old(*b) != 0 ==> *a == 0;
assigns *a;
*/
void reset_1st_if_2nd_is_true(int* a, int const* b){
    if(*b)
        *a = 0;
}
int main(){
    int a = 10;
    int b = 1; // true
    reset_1st_if_2nd_is_true(&a, &b);
    // @ assert a == 0;
}