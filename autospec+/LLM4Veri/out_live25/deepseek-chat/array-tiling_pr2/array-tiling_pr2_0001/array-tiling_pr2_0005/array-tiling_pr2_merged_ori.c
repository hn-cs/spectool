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
		int MINVAL;
		int i;
		int volArray[CELLCOUNT];
		int CCCELVOL2 = 3;
		int CCCELVOL1 = 1;
		if(CELLCOUNT % 2 != 0) { return 1; }
		// @ assert(CELLCOUNT % 2 == 0);
		/*@
		loop invariant i == 1 ==> \forall integer k; 0 <= k < 2*i ==> volArray[k] == (0 <= k % 2 < 1 ? (CCCELVOL2 >= MINVAL ? CCCELVOL2 : 0) : (CCCELVOL1 >= MINVAL ? CCCELVOL1 : 0));
		loop invariant \forall integer k; 0 <= k < i ==> volArray[2*k] == (CCCELVOL2 >= MINVAL ? CCCELVOL2 : 0);
		loop invariant \forall integer k; 0 <= k < i ==> volArray[2*k+1] == (CCCELVOL1 >= MINVAL ? CCCELVOL1 : 0);
		loop invariant CELLCOUNT % 2 == 0;
		volArray[2*k+1] == (CCCELVOL1 >= MINVAL ? CCCELVOL1 : 0));
		loop invariant i == 1 ==> volArray[1] == (CCCELVOL1 >= MINVAL ? CCCELVOL1 : 0);
		loop invariant i == 1 ==> volArray[0] == (CCCELVOL2 >= MINVAL ? CCCELVOL2 : 0);
		loop invariant i <= CELLCOUNT/2;
		loop invariant i <= CELLCOUNT/2 + 1;
		loop invariant \forall integer k; 0 <= k < i ==> (volArray[2*k] == (CCCELVOL2 >= MINVAL ? CCCELVOL2 : 0));
		loop invariant \forall integer k; 0 <= k < i ==> (volArray[2*k+1] == (CCCELVOL1 >= MINVAL ? CCCELVOL1 : 0));
		loop invariant \forall integer k; 0 <= k < i == >;
		loop invariant 1 <= i;
		loop invariant 0 <= i;
		loop invariant (CELLCOUNT/2) - i;
		loop assigns volArray[0..CELLCOUNT-1];
		loop assigns i;
		(volArray[2*k] == (CCCELVOL2 >= MINVAL ? CCCELVOL2 : 0) &&;
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
			if(CCCELVOL1 >= MINVAL)
			{
				volArray[i*2 - 1] = CCCELVOL1;
			}
			else
			{
				volArray[i*2 - 1] = 0;
			}
		}
		/*@
		loop invariant i == CELLCOUNT ==> \forall integer k; 0 <= k < CELLCOUNT ==> (volArray[k] == CCCELVOL2 || volArray[k] == CCCELVOL1 || volArray[k] == 0);
		loop invariant i <= CELLCOUNT;
		loop invariant \forall integer k; 0 <= k < i ==> (volArray[k] >= MINVAL || volArray[k] == 0);
		loop invariant \forall integer k; 0 <= k < i ==> (volArray[k] >= MINVAL ==> volArray[k] == CCCELVOL2 || volArray[k] == CCCELVOL1);
		loop invariant \forall integer k; 0 <= k < i ==> (volArray[k] == CCCELVOL2 || volArray[k] == CCCELVOL1 || volArray[k] == 0);
		loop invariant 0 <= i;
		loop assigns i;
		*/
		for(i = 0; i < CELLCOUNT; i++)
		{
			// @ assert(volArray[i] >= MINVAL || volArray[i] == 0 );
		}
	}
	return 1;
}
