#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define size 100000
int main()
{
  int a[size];
  int b[size];
  int i = 0;
  int j = 0;
  /*@
  loop invariant i == j;
  loop invariant 0 <= i <= size;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> \valid(b + k);
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == a[k];
  loop invariant size - i;
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < i ==> \valid(b + k);
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
  loop invariant j <= i/2;
  loop invariant i == 2*j+1;
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < j ==> a[k] == b[2*k+1];
  loop invariant 1 <= i;
  loop invariant 0 <= j;
  loop assigns j;
  loop assigns i;
  loop assigns a[0..j-1];
  */
  while( i < size )
  {
	a[j] = b[i];
        i = i+2;
        j = j+1;
  }
  i = 1;
  j = 0;
  /*@
  loop invariant j <= (size-1)/2;
  loop invariant i == 2*j + 1;
  loop invariant \forall integer k; 0 <= k < j ==> a[k] == b[2*k+1];
  loop invariant 1 <= i;
  loop invariant 0 <= j;
  loop invariant 0 <= j && i <= size;
  loop assigns j;
  loop assigns i;
  */
  while( i < size )
  {
	// @ assert(a[j] == b[2*j+1] );
        i = i+2;
        j = j+1;
  }
  return 0;
}
