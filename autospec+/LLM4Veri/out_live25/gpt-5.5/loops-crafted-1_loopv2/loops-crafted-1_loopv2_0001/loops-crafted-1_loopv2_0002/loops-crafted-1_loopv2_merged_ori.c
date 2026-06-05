#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int SIZE = 50000001;
int main() {
  int n,i,j,k;
  n = unknown();
  if (!(n <= SIZE)) return 0;
  i = 0; j=0;
  /*@
  loop invariant n > 0 ==> i <= n + 3;
  loop invariant j % 2 == 0;
  loop invariant i > 0 ==> j == i + 2;
  loop invariant i == 0 ==> j == 0;
  loop invariant i % 4 == 0;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while(i<n){ 
    i = i + 4;
    j = i +2;    
  }
  k =i;
  /*@
  loop invariant k % 4 == 0;
  loop invariant k % 2 == 0;
  loop invariant j - k == 0 || j - k == 2;
  loop invariant j % 2 == 0;
  loop assigns k;
  loop assigns j;
  */
  while( (j%2) == 0){
   j-=4;
   k -=4; 
  }
  // @ assert( (k%2) == 0 );
  return 0;
}
