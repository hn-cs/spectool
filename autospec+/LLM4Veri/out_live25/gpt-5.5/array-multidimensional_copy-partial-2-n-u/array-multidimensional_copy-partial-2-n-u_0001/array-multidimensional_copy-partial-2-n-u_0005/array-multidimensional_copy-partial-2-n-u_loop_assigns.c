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
	int q=500,s=700;
	int A [1000][1500];
        int B [500][700];
	// @ assert(q<m);
	// @ assert(s<n);
	i=0;
	j=0;
	/*@
	loop invariant j == 0 || j == n;
	loop invariant i <= m;
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
	loop invariant j == 0 || j == s;
	loop invariant i <= q;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < s ==> A[r][c] == B[r][c];
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..q-1][0..s-1];
	*/
	while(i < q){
		j=0;
		/*@
		loop invariant j <= s;
		loop invariant i < q;
		loop invariant \forall integer k; 0 <= k < j ==> A[i][k] == B[i][k];
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[i][0..s-1];
		*/
		while(j < s){
					A[i][j]=B[i][j];
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < q){
		j=0;
		/*@
		loop assigns j;
		*/
		while(j < s){
                                // @ assert(A[i][j]==B[i][j]);
                                j=j+1;
		}
		i=i+1;
    }
return 0;
}
