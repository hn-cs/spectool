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
        int B [1000][1000][1000];
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant n == 1000;
	loop invariant k <= n;
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer ii, jj, kk; 0 <= ii < i && 0 <= jj < n && 0 <= kk < n ==> INT_MIN <= B[ii][jj][kk] < INT_MAX;
	loop invariant 0 <= k;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns B[0..n-1][0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		k=0;
		/*@
		loop invariant n == 1000;
		loop invariant k <= n;
		loop invariant j <= n;
		loop invariant i < n;
		loop invariant \forall integer jj, kk; 0 <= jj < j && 0 <= kk < n ==> INT_MIN <= B[i][jj][kk] < INT_MAX;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns k;
		loop assigns j;
		loop assigns B[i][0..n-1][0..n-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant n == 1000;
			loop invariant k <= n;
			loop invariant j < n;
			loop invariant i < n;
			loop invariant \forall integer l; 0 <= l < k ==> INT_MIN <= B[i][j][l] < INT_MAX;
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns B[i][j][0..n-1];
			*/
			while(k < n){
                                        B[i][j][k]= unknown();
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
		/*@
		loop invariant n == 1000;
		loop invariant 0 <= i < n;
		loop invariant 0 <= j <= n;
		loop invariant 0 <= k <= n;
		loop invariant \forall integer jj, kk; 0 <= jj < j && 0 <= kk < n ==> A[i][jj][kk] == B[n-i-1][n-jj-1][n-kk-1];
		loop assigns j;
		loop assigns k;
		loop assigns A[i][0..n-1][0..n-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant n == 1000;
			loop invariant n - k;
			loop invariant k <= n;
			loop invariant j < n;
			loop invariant i < n;
			loop invariant \forall integer l; 0 <= l < k ==> A[i][j][l] == B[n-i-1][n-j-1][n-l-1];
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns A[i][j][0..n-1];
			*/
			while(k < n){
					A[i][j][k]=B[n-i-1][n-j-1][n-k-1];
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
			while(k < n){
					// @ assert(A[i][j][k]==B[n-i-1][n-j-1][n-k-1]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
