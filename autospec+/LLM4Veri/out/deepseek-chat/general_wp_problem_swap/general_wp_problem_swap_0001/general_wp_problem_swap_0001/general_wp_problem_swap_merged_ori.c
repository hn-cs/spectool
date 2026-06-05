/*@
requires \valid(b);
requires \valid(a);
ensures *b == \old(*a);
ensures *a == \old(*b);
assigns *a, *b;
*/
 void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }
 int main(){
 int a = 42;
 int b = 37;
 swap(&a, &b);
 // @ assert a == 37 && b == 42;
 return 0;
 }