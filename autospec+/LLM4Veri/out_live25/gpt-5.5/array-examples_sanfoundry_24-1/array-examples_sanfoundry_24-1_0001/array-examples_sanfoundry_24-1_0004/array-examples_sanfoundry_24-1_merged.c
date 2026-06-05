#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main()
{
    int array[SIZE];
    int i;
    int num = unknown();
		/*@
		loop invariant num >= 0 ==> i <= num;
		loop invariant num < 0 ==> i == 0;
		loop invariant \forall integer k; 0 <= k < i ==> array[k] >= INT_MIN;
		loop invariant \forall integer k; 0 <= k < i ==> array[k] != INT_MAX;
		loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= array[k] < INT_MAX;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns array[0..num-1];
		*/
		for(i = 0; i < num; i++) 
		{
		  array[i] = unknown();
		}
    /*@
    loop invariant num < 0 || i <= num;
    loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= array[k] < INT_MAX;
    loop invariant 0 <= i;
    loop assigns i;
    */
    for (i = 0; i < num; i++)
    {
        if (array[i] % 2 == 0)
        {
            // @ assert(  ( i % 2 ) == 0  );
        }
    }
    /*@
    loop invariant num < 0 || i <= num;
    loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= array[k] < INT_MAX;
    loop invariant 0 <= i;
    loop assigns i;
    */
    for (i = 0; i < num; i++)
    {
        if (array[i] % 2 != 0)
        {
            // @ assert(  ( i % 2 ) != 0  );
        }
    }
  return 0;
}
