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
  loop invariant size - i;
  loop invariant i <= size;
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
  while( i < size )
  {
	a[j] = b[i];
        i = i+2;
        j = j+1;
  }
  i = 1;
  j = 0;
  while( i < size )
  {
	// @ assert(a[j] == b[2*j+1] );
        i = i+2;
        j = j+1;
  }
  return 0;
}
