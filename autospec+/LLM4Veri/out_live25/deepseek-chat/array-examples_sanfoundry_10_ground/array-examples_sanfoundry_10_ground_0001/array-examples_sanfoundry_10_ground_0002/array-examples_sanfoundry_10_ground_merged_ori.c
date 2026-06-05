#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
    int i;
    int n = 100000;
    int pos;
    int element = unknown();
    int found = 0;
    int vectorx[n];
		/*@
		loop invariant i <= n;
		loop invariant \forall integer k; 0 <= k < i ==> vectorx[k] <= INT_MAX && vectorx[k] >= INT_MIN;
		loop invariant 0 <= i;
		loop assigns vectorx[0..n-1];
		loop assigns i;
		*/
		for(i = 0; i < n; i++) 
		{
		  vectorx[i] = unknown();
		} 
    /*@
    loop invariant n - i;
    loop invariant i <= n;
    loop invariant found ==> \exists integer k; 0 <= k < i && vectorx[k] == element;
    loop invariant found ==> (vectorx[pos] == element);
    loop invariant found ==> (pos == element);
    loop invariant 0 <= i;
    loop invariant !found ==> \forall integer k; 0 <= k < i ==> vectorx[k] != element;
    loop assigns pos;
    loop assigns i;
    loop assigns found;
    */
    for (i = 0; i < n && !found; i++)
    {
        if (vectorx[i] == element)
        {
            found = 1;
            pos = i;
        }
    }
    if ( found )
    {
        for (i = pos; i <  n - 1; i++)
        {
            vectorx[i] = vectorx[i + 1];
        }
    }
    if ( found ) {
      int x;
      for ( x = 0 ; x < pos ; x++ ) {
        // @ assert(vectorx[x] != element  );
      }
    }
  return 0;
}
