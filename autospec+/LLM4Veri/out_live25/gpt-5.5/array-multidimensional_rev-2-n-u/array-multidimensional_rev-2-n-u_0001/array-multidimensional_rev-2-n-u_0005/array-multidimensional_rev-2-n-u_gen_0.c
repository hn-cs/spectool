#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j;
	int m=1000,n=1500,p=1800;
	int A [1000][1500];
	int B [1000][1500];
	i=0;
	j=0;
	/*@
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> INT_MIN <= B[r][c] < INT_MAX;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns B[0..m-1][0..n-1];
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= B[i][k] < INT_MAX;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns B[i][0..n-1];
		*/
		while(j < n){
					B[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	/*@
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> A[r][c] == B[m-r-1][n-c-1];
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
		loop invariant \forall integer k; 0 <= k < j ==> A[i][k] == B[m-i-1][n-k-1];
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[i][0..n-1];
		*/
		while(j < n){
                            A[i][j]=B[m-i-1][n-j-1];
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < m){
		j=0;
		/*@
		loop invariant 0 <= j <= n;
		loop invariant 0 <= i < m;
		loop invariant \forall integer k; 0 <= k < n ==> A[i][k] == B[m-i-1][n-k-1];
		loop assigns j;
		*/
		while(j < n){
                            // @ assert(A[i][j]==B[m-i-1][n-j-1]);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
