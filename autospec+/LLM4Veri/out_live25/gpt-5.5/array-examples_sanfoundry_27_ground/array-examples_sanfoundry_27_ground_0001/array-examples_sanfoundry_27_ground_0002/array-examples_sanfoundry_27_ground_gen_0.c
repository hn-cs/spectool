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
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= array[k] < INT_MAX;
		loop invariant SIZE - i;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns array[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++) 
		{
		  array[i] = unknown();
		}
    int largest = array[0];
    /*@
    loop invariant 1 <= i <= SIZE;
    loop invariant \forall integer k; 0 <= k < SIZE ==> INT_MIN <= array[k] < INT_MAX;
    loop invariant \forall integer k; 0 <= k < i ==> largest >= array[k];
    loop invariant \exists integer k; 0 <= k < i && largest == array[k];
    loop invariant INT_MIN <= largest < INT_MAX;
    loop assigns i;
    loop assigns largest;
    loop variant SIZE - i;
    */
    for (i = 1; i < SIZE; i++)
    {
        if (largest < array[i])
            largest = array[i];
    }
    int x;
    for ( x = 0 ; x < SIZE ; x++ ) {
      // @ assert(largest >= array[ x ]  );
    }
    return 0;
}
