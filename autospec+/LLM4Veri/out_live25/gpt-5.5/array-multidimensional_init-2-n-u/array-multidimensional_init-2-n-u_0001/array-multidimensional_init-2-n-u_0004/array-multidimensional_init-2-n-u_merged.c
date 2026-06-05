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
	int C=unknown();
	i=0;
	j=0;
	/*@
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> A[r][c] == C;
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
		loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> A[r][c] == C;
		loop invariant \forall integer k; 0 <= k < j ==> A[i][k] == C;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[i][0..n-1];
		*/
		while(j < n){
                        A[i][j]=C;
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	/*@
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant j == 0 || j == n;
	loop invariant i <= m;
	loop invariant \forall integer r, c; 0 <= r < m && 0 <= c < n ==> A[r][c] == C;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant n == 1500;
		loop invariant m == 1000;
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer r, c; 0 <= r < m && 0 <= c < n ==> A[r][c] == C;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		*/
		while(j < n){
                        //@ assert(A[i][j]==C);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
