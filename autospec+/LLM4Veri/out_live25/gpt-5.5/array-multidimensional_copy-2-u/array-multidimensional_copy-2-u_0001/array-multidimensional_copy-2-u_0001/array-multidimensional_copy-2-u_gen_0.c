#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j;
	int n=1000;
	int A [1000][1000];
        int B [1000][1000];
	i=0;
	j=0;
	while(i < n){
		j=0;
		/*@
		loop invariant 0 <= j <= n;
		loop invariant n == 1000;
		loop invariant 0 <= i < n;
		loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= B[i][k] < INT_MAX;
		loop assigns j, B[i][0..n-1];
		loop variant n - j;
		*/
		while(j < n){
					B[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		while(j < n){
					A[i][j]=B[i][j];
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		while(j < n){
                            // @ assert(A[i][j]==B[i][j]);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
