#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ){
  int aa [N]; 
  int a = 0;
	/*@
	loop invariant i == 0 || aa[i-1] >= 0;
	loop invariant \forall integer k; 0 <= k < i ==> aa[k] >= 0;
	loop invariant i == 0 || aa[i-1] < 0;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= aa[k] < INT_MAX;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns aa[0..N-1];
	*/
	for(int i = 0; i < N; i++)
	{
	  aa[i] = unknown();
	}
  /*@
  loop invariant a <= N;
  loop invariant \forall integer k; 0 <= k < a ==> aa[k] >= 0;
  loop invariant N - a;
  loop invariant 0 <= a;
  loop assigns a;
  */
  while( aa[a] >= 0 ) {
    a++;
  }
  int x;
  /*@
  loop invariant x <= a;
  loop invariant \forall integer k; 0 <= k < x ==> aa[k] >= 0;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < a ; x++ ) {
    // @ assert(aa[x] >= 0  );
  }
  return 0;
}
