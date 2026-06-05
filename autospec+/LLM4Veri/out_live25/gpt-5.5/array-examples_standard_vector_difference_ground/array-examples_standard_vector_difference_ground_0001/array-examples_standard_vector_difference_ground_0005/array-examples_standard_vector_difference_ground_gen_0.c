#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main( ) {
  int a[SIZE];
  int b[SIZE];
  int c[SIZE];
  int i = 0;
	/*@
	loop invariant i <= SIZE;
	loop invariant \valid(c + (0..SIZE-1));
	loop invariant \valid(b + (0..SIZE-1));
	loop invariant \valid(a + (0..SIZE-1));
	loop invariant \separated(b + (0..SIZE-1), c + (0..SIZE-1));
	loop invariant \separated(a + (0..SIZE-1), c + (0..SIZE-1));
	loop invariant \separated(a + (0..SIZE-1), b + (0..SIZE-1));
	loop invariant \forall integer k; 0 <= k < i ==> b[k] <= INT_MAX - 1;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] <= INT_MAX - 1;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= b[k] < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop invariant 0 <= SIZE - i;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for(i = 0; i < SIZE; i++)
	{
	  a[i] = unknown();
		b[i] = unknown();
	}
	i = 0;
  /*@
  loop invariant 0 <= SIZE - i;
  loop invariant \valid(a + (0..SIZE-1));
  loop invariant \valid(b + (0..SIZE-1));
  loop invariant \valid(c + (0..SIZE-1));
  loop invariant \separated(a + (0..SIZE-1), c + (0..SIZE-1));
  loop invariant \separated(b + (0..SIZE-1), c + (0..SIZE-1));
  loop invariant \separated(a + (0..SIZE-1), b + (0..SIZE-1));
  loop invariant \forall integer k; 0 <= k < SIZE ==> INT_MIN <= a[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < SIZE ==> INT_MIN <= b[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> c[k] + b[k] == a[k];
  loop invariant i <= SIZE;
  loop invariant \forall integer k; 0 <= k < i ==> c[k] == a[k] - b[k];
  loop invariant SIZE - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns c[0..SIZE-1];
  */
  while (i < SIZE) {
    c[i] = a[i] - b[i];
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x <= SIZE;
  loop invariant \forall integer k; 0 <= k < SIZE ==> c[k] == a[k] - b[k];
  loop invariant SIZE - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < SIZE ; x++ ) {
    // @ assert(c[x] == a[x] - b[x]  );
  }
  return 0;
}
