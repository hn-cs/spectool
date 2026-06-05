#include <limits.h>
/*@
requires \valid(p) && \valid(q) && \valid(r);
requires *p + *q >= INT_MIN;
requires *p + *q <= INT_MAX;
ensures *r == \old(*p) + \old(*q);
assigns *r;
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
  //@ assert x == a + b ;
  //@ assert x == 66 ;
  x = add(&a, &a, &res) ;
  //@ assert x == a + a ;
  //@ assert x == 48 ;
}