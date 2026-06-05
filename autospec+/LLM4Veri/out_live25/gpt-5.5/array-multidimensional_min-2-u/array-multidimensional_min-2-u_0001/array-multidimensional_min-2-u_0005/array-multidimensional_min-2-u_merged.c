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
	int min;
	i=0;
	j=0;
	/*@
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant j == 0 || j == n;
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..m-1][0..n-1];
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
        min=A [0][0];
	/*@
	loop invariant n == 1500;
	loop invariant min < INT_MAX;
	loop invariant m == 1000;
	loop invariant j == 0 || j == n;
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer r, c; 0 <= r < m && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop invariant \forall integer r, c; 0 <= r < i && r < m && 0 <= c < n ==> min <= A[r][c];
	loop invariant INT_MIN <= min;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns min;
	loop assigns j;
	loop assigns i;
	*/
	while(i < n){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i <= n;
		loop invariant \forall integer r, c; 0 <= r < m && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
		loop invariant \forall integer r, c; 0 <= r < i && r < m && 0 <= c < n ==> min <= A[r][c];
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop invariant 0 <= i < m ==> \forall integer c; 0 <= c < j ==> min <= A[i][c];
		loop assigns min;
		loop assigns j;
		*/
		while(j < n){
			if(A[i][j]<min){
                            min=A[i][j];
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
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer c; 0 <= c < n ==> A[i][c] >= min;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		*/
		while(j < n){
			// @ assert(A[i][j]>=min);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
