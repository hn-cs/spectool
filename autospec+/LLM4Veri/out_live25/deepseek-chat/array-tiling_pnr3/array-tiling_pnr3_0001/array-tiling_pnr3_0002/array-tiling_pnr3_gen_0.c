#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
/*@
requires \valid(a+(0..SIZE-1));
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
int ReadFromPort()
{
	int x = unknown();
	return x;
}
int SIZE;
const int MAX = 100000;
int main()
{
	SIZE = unknown();
	if(SIZE > 1 && SIZE < MAX)
	{
		int i;
		int value;
		int *a = malloc(sizeof(int)*SIZE);
		int DEFAULTVAL = 0; 
		int FIXEDVAL = 10; 
		if(SIZE % 3 != 0) { return 1; }
		// @ assert(SIZE % 3 == 0);
		/*@
		loop invariant 0 <= i <= SIZE/3;
		loop invariant \forall integer k; 0 <= k < i ==> 
		  (a[k*3] != DEFAULTVAL && a[k*3+1] != DEFAULTVAL && a[k*3+2] != DEFAULTVAL);
		loop assigns i, a[0..SIZE-1];
		loop variant SIZE/3 - i;
		*/
		for (i = 1 ; i <= SIZE/3 ; i++)
		{
			value = ReadFromPort();	
			if(value != DEFAULTVAL)
			{
				a[i*3 - 3] = value ;   
			}
			else 
			{
				a[i*3 - 3] = FIXEDVAL;  
			}
			value = ReadFromPort();	
			if(value != DEFAULTVAL)
			{
				a[i*3 - 2] = value ;   
			}
			else 
			{
				a[i*3 - 2] = FIXEDVAL;  
			}
			value = ReadFromPort();	
			if(value != DEFAULTVAL)
			{
				a[i*3 - 1] = value ;   
			}
			else 
			{
				a[i*3 - 1] = FIXEDVAL;  
			}
		}
		for ( i = 0; i < SIZE; i++)  
		{
			// @ assert(a[i]!=DEFAULTVAL);
		}
	}
	return 1;
}
