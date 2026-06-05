#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define MAX 100000 
int main()
{
    int array[MAX];
    int i;
    int largest1;
    int largest2;
    int temp;
		/*@
		loop invariant i <= MAX;
		loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= array[k] < INT_MAX;
		loop invariant MAX - i;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns array[0..MAX-1];
		*/
		for(i = 0; i < MAX; i++) 
		{
		  array[i] = unknown();
		}
    largest1 = array[0];
    largest2 = array[1];
    if (largest1 < largest2)
    {
        temp = largest1;
        largest1 = largest2;
        largest2 = temp;
    }
    /*@
    loop invariant largest2 <= largest1;
    loop invariant i <= MAX;
    loop invariant \forall integer k; 0 <= k < i ==> array[k] <= largest2 || array[k] == largest1;
    loop invariant \forall integer k; 0 <= k < i ==> array[k] <= largest1;
    loop invariant \forall integer k; 0 <= k < MAX ==> INT_MIN <= array[k] < INT_MAX;
    loop invariant \exists integer k; 0 <= k < i && largest2 == array[k];
    loop invariant \exists integer k; 0 <= k < i && largest1 == array[k];
    loop invariant 2 <= i;
    loop assigns largest2;
    loop assigns largest1;
    loop assigns i;
    */
    for (i = 2; i < MAX;  i++)
    {
        if (array[i] >= largest1)
        {
            largest2 = largest1;
            largest1 = array[i];
        }
        else if (array[i] > largest2)
        {
            largest2 = array[i];
        }
    }
    int x;
    for( x = 0 ; x < MAX ; x++ ) {
      // @ assert(array[ x ] <= largest1  );
    }
    for( x = 0 ; x < MAX ; x++ ) {
      // @ assert(array[x] <= largest2 || array[x] == largest1  );
    }
  return 0;
}
