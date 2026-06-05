#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j;
	int m=1000,n=1500;
	int A [1000][1500];
	int max;
	i=0;
	j=0;
	/*@
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop invariant 0 <= i;
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= A[i][k] < INT_MAX;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[i][0..n-1];
		*/
		while(j < n){
					A[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
        max=A [0][0];
	/*@
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant i <= n;
	loop invariant \forall integer r, c; 0 <= r < m && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop invariant 0 <= i;
	loop assigns max;
	loop assigns j;
	loop assigns i;
	*/
	while(i < n){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant \forall integer c; 0 <= c < j ==> A[i][c] <= max;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns max;
		loop assigns j;
		*/
		while(j < n){
			if(A[i][j]>max){
                            max=A[i][j];
                        }
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		/*@
		loop assigns j;
		*/
		while(j < n){
			// @ assert(A[i][j]<=max);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
