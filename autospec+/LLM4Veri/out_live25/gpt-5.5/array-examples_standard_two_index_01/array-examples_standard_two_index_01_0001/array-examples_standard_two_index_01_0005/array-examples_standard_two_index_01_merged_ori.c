#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define size 10000
int main()
{
  int a[size];
  int b[size];
  int i = 0;
  int j = 0;
  /*@
  loop invariant size == 10000;
  loop invariant size - i;
  loop invariant j == 0;
  loop invariant j <= i;
  loop invariant i <= size;
  loop invariant i + j == i;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] >= INT_MIN;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] <= INT_MAX - 1;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= b[k] < INT_MAX;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..size-1];
  */
  while( i < size )
  {
	b[i] = unknown();
    i = i+1;
  }
  i = 0;
  /*@
  loop invariant size == 10000;
  loop invariant j <= i;
  loop invariant i <= j;
  loop invariant i + j == 2 * i;
  loop invariant \forall integer k; i <= k < size ==> b[k] == b[k];
  loop invariant \forall integer k; 0 <= k < size ==> INT_MIN <= b[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] < INT_MAX;
  loop invariant 0 <= size - i;
  loop invariant j <= size;
  loop invariant i == j;
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  loop assigns a[0..size-1];
  */
  while( i < size )
  {
	a[j] = b[i];
        i = i+1;
        j = j+1;
  }
  i = 0;
  j = 0;
  /*@
  loop invariant size - i;
  loop invariant j <= size;
  loop invariant i == j;
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < size ==> a[k] == b[k];
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while( i < size )
  {
	// @ assert(a[j] == b[j] );
        i = i+1;
        j = j+1;
  }
  return 0;
}
