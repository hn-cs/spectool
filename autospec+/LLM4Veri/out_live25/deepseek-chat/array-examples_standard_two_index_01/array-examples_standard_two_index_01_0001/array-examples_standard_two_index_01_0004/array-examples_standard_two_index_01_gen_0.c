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
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == \at(unknown(), Pre);
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
  loop invariant j == i;
  loop invariant j <= size;
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
  loop invariant j == i;
  loop invariant j <= size;
  loop invariant i <= size;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
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
