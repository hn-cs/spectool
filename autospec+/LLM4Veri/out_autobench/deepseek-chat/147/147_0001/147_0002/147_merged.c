#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


int main() {
  int a = 0;
  int j;
  int m;
  if(m<=0)
    return 0;
  /*@
  loop invariant \abs(a) <= j;
  loop invariant j <= m + 1;
  loop invariant a <= j;
  loop invariant 0 <= j;
  loop invariant -j <= a;
  loop assigns j;
  loop assigns a;
  */
  for(j = 1; j <= m ; j++){
    if(unknown1()) 
       a++;
    else
       a--; 
  }
  //@ assert(a>=-m);
  //@ assert(a<=m);
}
