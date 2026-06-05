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
		/*@
		loop invariant CELLCOUNT >= 3;
		loop invariant CELLCOUNT / 3 >= 1;
		loop invariant 0 <= 3 * (i - 1) <= CELLCOUNT;
		loop invariant 3 * i <= CELLCOUNT + 3;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 3] == 3;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 2] == 2;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 1] == 0;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 3] >= MINVAL;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 2] >= MINVAL;
		loop invariant \forall integer t; 1 <= t < i ==> volArray[3*t - 1] == 0 || volArray[3*t - 1] >= MINVAL;
		loop invariant i <= CELLCOUNT / 3 + 1;
		loop invariant MINVAL == 2;
		loop invariant CELLCOUNT % 3 == 0;
		loop invariant 1 <= i;
		loop assigns volArray[0 .. CELLCOUNT - 1];
		loop assigns j;
		loop assigns i;
		*/
		for(i = 1; i <= CELLCOUNT/3; i++)
		{
			/*@
			loop invariant j == 3 || j == 2 || j == 1 || j == 0;
			loop invariant j <= 3;
			loop invariant i <= CELLCOUNT / 3;
			loop invariant i * 3 - 1 < CELLCOUNT;
			loop invariant \forall integer k; j < k <= 3 ==> volArray[i * 3 - k] != 1;
			loop invariant \forall integer k; j < k <= 3 ==> (volArray[i * 3 - k] >= MINVAL || volArray[i * 3 - k] == 0);
			loop invariant \forall integer k; j < k <= 3 ==> (k >= MINVAL ==> volArray[i * 3 - k] == k);
			loop invariant \forall integer k; j < k <= 3 ==> (k < MINVAL ==> volArray[i * 3 - k] == 0);
			loop invariant MINVAL == 2;
			loop invariant 1 <= i;
			loop invariant 0 <= j;
			loop invariant 0 <= i * 3 - 3;
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
		/*@
		loop invariant i <= CELLCOUNT;
		loop invariant MINVAL == 2;
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
