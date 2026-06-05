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
		int CCCELVOL3 = 7;
		int CCCELVOL2 = 3;
		int CCCELVOL1 = 1;
		if(CELLCOUNT % 3 != 0) { return 1; }
		// @ assert(CELLCOUNT % 3 == 0);
		/*@
		loop invariant i <= CELLCOUNT / 3 + 1;
		loop invariant \forall integer k; 0 <= k < 3 * (i - 1) ==> volArray[k] >= MINVAL || volArray[k] == 0;
		loop invariant CELLCOUNT % 3 == 0;
		loop invariant 1 <= i;
		loop assigns volArray[0..CELLCOUNT-1];
		loop assigns i;
		*/
		for(i = 1; i <= CELLCOUNT/3; i++)
		{
			if(CCCELVOL3 >= MINVAL)
			{
				volArray[i*3 - 3] = CCCELVOL3;
			}
			else
			{
				volArray[i*3 - 3] = 0;
			}
			if(CCCELVOL2 >= MINVAL)
			{
				volArray[i*3 - 2] = CCCELVOL2;
			}
			else
			{
				volArray[i*3 - 2] = 0;
			}
			if(CCCELVOL1 >= MINVAL)
			{
				volArray[i*3 - 1] = CCCELVOL1;
			}
			else
			{
				volArray[i*3 - 1] = 0;
			}
		}
		/*@
		loop invariant i <= CELLCOUNT;
		loop invariant \forall integer k; 0 <= k < CELLCOUNT ==> volArray[k] >= MINVAL || volArray[k] == 0;
		loop invariant CELLCOUNT - i;
		loop invariant CELLCOUNT % 3 == 0;
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
