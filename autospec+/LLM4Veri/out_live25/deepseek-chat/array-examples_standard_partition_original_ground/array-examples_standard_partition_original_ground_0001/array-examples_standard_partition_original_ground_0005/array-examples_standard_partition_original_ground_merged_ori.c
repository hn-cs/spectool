#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ) {
  int aa[N];
  int a = 0;
  int b = 0;
  int c = 0;
  int bb[N];
  int cc[N];
	/*@
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= aa[k] < INT_MAX;
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns aa[0..N-1];
	*/
	for(int i = 0; i < N; i++) 
	{
	    aa[i] = unknown();
	}
  /*@
  loop invariant c <= a;
  loop invariant b <= a;
  loop invariant b + c == a;
  loop invariant a <= N;
  loop invariant \forall integer k; 0 <= k < c ==> cc[k] < 0;
  loop invariant \forall integer k; 0 <= k < b ==> bb[k] >= 0;
  loop invariant \forall integer k; 0 <= k < a ==> (aa[k] >= 0 <==> (\exists integer j; 0 <= j < b && bb[j] == aa[k]));
  loop invariant \forall integer k; 0 <= k < a ==> (aa[k] < 0 <==> (\exists integer j; 0 <= j < c && cc[j] == aa[k]));
  loop invariant 0 <= c;
  loop invariant 0 <= b;
  loop invariant 0 <= a;
  loop assigns cc[0..N-1];
  loop assigns c;
  loop assigns bb[0..N-1];
  loop assigns b;
  loop assigns a;
  */
  while( a < N ) {
    if( aa[ a ] >= 0 ) {
      bb[ b ] = aa[ a ];
      b = b + 1;
    }
    else {
      cc[ c ] = aa[ a ];
      c = c + 1;
    }
    a = a + 1;
  }
  int x;
  /*@
  loop invariant x <= b;
  loop invariant \forall integer k; 0 <= k < x ==> bb[k] >= 0;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < b ; x++ ) {
    // @ assert(bb[ x ] >= 0  );
  }
  /*@
  loop invariant x <= c;
  loop invariant \forall integer k; 0 <= k < x ==> cc[k] < 0;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < c ; x++ ) {
    // @ assert(cc[ x ] < 0  );
  }
  return 0;
}
