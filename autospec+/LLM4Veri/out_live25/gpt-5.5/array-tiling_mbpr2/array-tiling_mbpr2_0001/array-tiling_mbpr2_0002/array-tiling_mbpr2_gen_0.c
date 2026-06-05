#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int CELLCOUNT;
int main()
{
	CELLCOUNT = unknown();
	if(CELLCOUNT > 1)
	{
		int MINVAL=2;
		int i;
		int volArray[CELLCOUNT];
		int CCCELVOL2 = 3;
		int CCCELVOL1 = 1;
		if(CELLCOUNT % 2 != 0) { return 1; }
		// @ assert(CELLCOUNT % 2 == 0);
		/*@
		loop invariant i <= CELLCOUNT / 2 + 1;
		loop invariant \forall integer k; 1 <= k < i ==> (volArray[2*k - 2] >= MINVAL || volArray[2*k - 2] == 0);
		loop invariant MINVAL == 2;
		loop invariant CELLCOUNT % 2 == 0;
		loop invariant CCCELVOL2 == 3;
		loop invariant CCCELVOL1 == 1;
		loop invariant 1 <= i;
		loop invariant 1 < CELLCOUNT;
		loop assigns volArray[0..CELLCOUNT-1];
		loop assigns i;
		*/
		for(i = 1; i <= CELLCOUNT/2; i++)
		{
			if(CCCELVOL2 >= MINVAL)
			{
				volArray[i*2 - 2] = CCCELVOL2;
			}
			else
			{
				volArray[i*2 - 2] = 0;
			}
			volArray[i*2 - 1] = volArray[i*2 - 1];
		}
		/*@
		loop invariant 1 <= i <= CELLCOUNT / 2 + 1;
		loop invariant MINVAL == 2;
		loop invariant CELLCOUNT % 2 == 0;
		loop invariant 1 < CELLCOUNT;
		loop invariant CCCELVOL2 == 3;
		loop invariant CCCELVOL1 == 1;
		loop invariant \forall integer k; 1 <= k <= CELLCOUNT / 2 ==> (volArray[2*k - 2] >= MINVAL || volArray[2*k - 2] == 0);
		loop invariant \forall integer k; 1 <= k < i ==> (volArray[2*k - 1] >= MINVAL || volArray[2*k - 1] == 0);
		loop assigns volArray[0..CELLCOUNT-1], i;
		*/
		for(i = 1; i <= CELLCOUNT/2; i++)
		{
			if(CCCELVOL1 >= MINVAL)
			{
				volArray[i*2 - 1] = CCCELVOL1;
			}
			else
			{
				volArray[i*2 - 1] = 0;
			}
			volArray[i*2 - 2] = volArray[i*2 - 2];
		}
		for(i = 0; i < CELLCOUNT; i++)
		{
			// @ assert(volArray[i] >= MINVAL || volArray[i] == 0 );
		}
	}
	return 1;
}
