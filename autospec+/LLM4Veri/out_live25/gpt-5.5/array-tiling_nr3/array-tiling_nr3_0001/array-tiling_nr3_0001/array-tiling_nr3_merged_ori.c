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
		int j;
		int volArray[CELLCOUNT];
		if(CELLCOUNT % 3 != 0) { return 1; }
		// @ assert(CELLCOUNT % 3 == 0);
		for(i = 1; i <= CELLCOUNT/3; i++)
		{
			/*@
			loop invariant j;
			loop invariant j <= 3;
			loop invariant i <= CELLCOUNT / 3;
			loop invariant \forall integer k; j < k <= 3 ==> (k >= MINVAL ==> volArray[i * 3 - k] == k);
			loop invariant \forall integer k; j < k <= 3 ==> (k < MINVAL ==> volArray[i * 3 - k] == 0);
			loop invariant MINVAL == 2;
			loop invariant 1 <= i;
			loop invariant 0 <= j;
			loop assigns volArray[i * 3 - 3 .. i * 3 - 1];
			loop assigns j;
			*/
			for(j = 3; j >= 1; j--)
			{
				if(j >= MINVAL)
				{
					volArray[i*3 - j] = j;
				}
				else
				{
					volArray[i*3 - j] = 0;
				}
			}
		}
		for(i = 0; i < CELLCOUNT; i++)
		{
			// @ assert(volArray[i] >= MINVAL || volArray[i] == 0 );
		}
	}
	return 1;
}
