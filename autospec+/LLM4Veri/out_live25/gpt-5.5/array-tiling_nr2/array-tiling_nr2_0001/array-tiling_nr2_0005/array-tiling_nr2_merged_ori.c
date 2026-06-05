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
		int DEFAULTVALUE=1;
		int MINVAL=2;
		int i;
		int j;
		int volArray[CELLCOUNT];
		if(CELLCOUNT % 2 != 0) { return 1; }
		// @ assert(CELLCOUNT % 2 == 0);
		/*@
		loop invariant \valid(volArray + (0 .. CELLCOUNT-1));
		loop invariant \forall integer k; 0 <= k < 2*(i-1) ==> (k % 2 == 1 ==> volArray[k] == 0);
		loop invariant \forall integer k; 0 <= k < 2*(i-1) ==> (k % 2 == 0 ==> volArray[k] == 2);
		loop invariant \forall integer h; 1 <= h < i ==> volArray[2*h - 2] == 2;
		loop invariant \forall integer h; 1 <= h < i ==> volArray[2*h - 1] == 0;
		loop invariant DEFAULTVALUE == 1;
		loop invariant 2 <= CELLCOUNT;
		loop invariant 2 * (i - 1) <= CELLCOUNT;
		loop invariant 1 <= CELLCOUNT / 2;
		loop invariant i <= CELLCOUNT / 2 + 1;
		loop invariant MINVAL == 2;
		loop invariant CELLCOUNT % 2 == 0;
		loop invariant 1 <= i;
		loop assigns volArray[0..CELLCOUNT-1];
		loop assigns j;
		loop assigns i;
		*/
		for(i = 1; i <= CELLCOUNT/2; i++)
		{
			/*@
			loop invariant j <= 2;
			loop invariant j < 2 ==> volArray[i * 2 - 2] == 2;
			loop invariant j < 1 ==> volArray[i * 2 - 1] == 0;
			loop invariant i <= CELLCOUNT / 2;
			loop invariant i * 2 - 1 < CELLCOUNT;
			loop invariant \forall integer k; j < k <= 2 ==> (k >= MINVAL ==> volArray[i * 2 - k] == k);
			loop invariant \forall integer k; j < k <= 2 ==> (k < MINVAL ==> volArray[i * 2 - k] == 0);
			loop invariant MINVAL == 2;
			loop invariant DEFAULTVALUE == 1;
			loop invariant CELLCOUNT % 2 == 0;
			loop invariant 2 <= 2 * i;
			loop invariant 2 * i <= CELLCOUNT;
			loop invariant 1 <= j ==> 0 <= i * 2 - j < CELLCOUNT;
			loop invariant 1 <= i;
			loop invariant 0 <= j;
			loop invariant 0 <= i * 2 - 2;
			loop assigns volArray[i * 2 - 2 .. i * 2 - 1];
			loop assigns j;
			*/
			for(j = 2; j >= 1; j--)
			{
				if(j >= MINVAL)
				{
					volArray[i*2 - j] = j;
				}
				else
				{
					volArray[i*2 - j] = 0;
				}
			}
		}
		/*@
		loop invariant i <= CELLCOUNT;
		loop invariant MINVAL == 2;
		loop invariant CELLCOUNT % 2 == 0;
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
