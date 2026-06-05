#include <limits.h>
/*@
requires \valid_read(p);
requires \valid_read(q);
requires \valid(r);
requires *p + *q <= INT_MAX;
requires *p + *q >= INT_MIN;
assigns *r;
ensures *r == *p + *q;
ensures \result == *p + *q;
*/
int add(int* p, int* q, int* r){
  int result = *p + *q; 
  *r = result;
  return result;
}
int main(){
  int a = 24 ;
  int b = 42 ;
  int res; 
  int x;
  x = add(&a, &b, &res) ;
  // @ assert x == a + b ;
  // @ assert x == 66 ;
  x = add(&a, &a, &res) ;
  // @ assert x == a + a ;
  // @ assert x == 48 ;
}