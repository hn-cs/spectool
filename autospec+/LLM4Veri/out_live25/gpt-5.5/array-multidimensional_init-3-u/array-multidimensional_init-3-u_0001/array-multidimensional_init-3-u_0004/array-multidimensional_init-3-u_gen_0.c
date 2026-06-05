#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j,k;
	int n=1000;
	int A [1000][1000][1000];
	int C=unknown();
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant k <= n;
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer ii, jj, kk; 0 <= ii < i && 0 <= jj < n && 0 <= kk < n ==> A[ii][jj][kk] == C;
	loop invariant 0 <= k;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..n-1][0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		k=0;
		/*@
		loop invariant k <= n;
		loop invariant j <= n;
		loop invariant i < n;
		loop invariant \forall integer jj, kk; 0 <= jj < j && 0 <= kk < n ==> A[i][jj][kk] == C;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns k;
		loop assigns j;
		loop assigns A[i][0..n-1][0..n-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant k <= n;
			loop invariant j < n;
			loop invariant i < n;
			loop invariant \forall integer l; 0 <= l < k ==> A[i][j][l] == C;
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns A[i][j][0..n-1];
			*/
			while(k < n){
					A[i][j][k]=C;
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < n){
		j=0;
		k=0;
		while(j < n){
			k=0;
			/*@
			loop invariant 0 <= k <= n;
			loop invariant 0 <= j < n;
			loop invariant 0 <= i < n;
			loop invariant \forall integer l; 0 <= l < n ==> A[i][j][l] == C;
			loop assigns k;
			loop assigns A[i][j][0..n-1];
			*/
			while(k < n){
					// @ assert(A[i][j][k]==C);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
