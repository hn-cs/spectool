#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define size 100000
int main( )
{
  int a[size];
  int b[size];
  int i = 0;
  int j = 0;
  /*@
  loop invariant size - i;
  loop invariant i <= size;
  loop invariant i < size ==> 0 <= i < size;
  loop invariant \valid(b + (0..size-1));
  loop invariant \separated(a + (0..size-1), b + (0..size-1));
  loop invariant \forall integer k; 0 <= k < i ==> b[k] <= INT_MAX - 1;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= b[k];
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= b[k] < INT_MAX;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..size-1];
  */
  while( i < size )
  {
	b[i] = unknown();
    i = i+1;
  }
  i = 1;
  /*@
  loop invariant size - i >= -3;
  loop invariant i % 4 == 1;
  loop invariant j == (i - 1) / 4;
  loop invariant 0 <= j <= size;
  loop invariant 1 <= i <= size + 3;
  loop invariant \forall integer k; 0 <= k < j ==> a[k] <= INT_MAX - 1;
  loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k];
  loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
  loop invariant j <= (size + 3) / 4;
  loop invariant i == 4 * j + 1;
  loop invariant i <= size + 3;
  loop invariant \forall integer k; 0 <= k < j ==> a[k] == b[4 * k + 1];
  loop invariant 1 <= i;
  loop invariant 0 <= j;
  loop assigns j;
  loop assigns i;
  loop assigns a[0..size-1];
  */
  while( i < size )
  {
	a[j] = b[i];
        i = i+4;
        j = j+1;
  }
  i = 1;
  j = 0;
  /*@
  loop invariant size - i;
  loop invariant j <= (size + 3) / 4;
  loop invariant i == 4 * j + 1;
  loop invariant i <= size + 3;
  loop invariant \forall integer k; 0 <= k < (size + 3) / 4 ==> a[k] == b[4 * k + 1];
  loop invariant 1 <= i;
  loop invariant 0 <= j;
  loop assigns j;
  loop assigns i;
  */
  while( i < size )
  {
	// @ assert(a[j] == b[4*j+1] );
        i = i+4;
        j = j+1;
  }
  return 0;
}
