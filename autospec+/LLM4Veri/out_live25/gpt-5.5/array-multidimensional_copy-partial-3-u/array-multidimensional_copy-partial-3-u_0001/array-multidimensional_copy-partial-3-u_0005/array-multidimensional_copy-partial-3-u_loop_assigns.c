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
	int p=500;
	int A [1000][1000][1000];
        int B [1000][1000][1000];
	// @ assert(p<n);
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant p == 500;
	loop invariant p < n;
	loop invariant n == 1000;
	loop invariant k <= n;
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer h, l, m; 0 <= h < i && 0 <= l < n && 0 <= m < n ==> INT_MIN <= B[h][l][m] < INT_MAX;
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
		loop invariant k <= n;
		loop invariant j <= n;
		loop invariant i < n;
		loop invariant \forall integer l, m; 0 <= l < j && 0 <= m < n ==> INT_MIN <= B[i][l][m] < INT_MAX;
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
			loop invariant k <= n;
			loop invariant \forall integer l; 0 <= l < k ==> INT_MIN <= B[i][j][l] < INT_MAX;
			loop invariant 0 <= k;
			loop assigns k;
			loop assigns B[i][j][0..n-1];
			*/
			while(k < n){
					B[i][j][k] = unknown();
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < p){
		j=0;
		k=0;
		/*@
		loop assigns j;
		loop assigns A[i][0..p-1][0..p-1];
		*/
		while(j < p){
			k=0;
			/*@
			loop invariant p == 500;
			loop invariant p - k;
			loop invariant n == 1000;
			loop invariant k <= p;
			loop invariant j < p;
			loop invariant i < p;
			loop invariant \forall integer l; 0 <= l < k ==> A[i][j][l] == B[i][j][l];
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns A[i][j][0..p-1];
			*/
			while(k < p){
					A[i][j][k]=B[i][j][k];
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
		i=p;
		while(i < n){
		j=p;
		while(j < n){
			k=p;
			while(k < n){
					A[i][j][k]=B[i][j][k];
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
					// @ assert(A[i][j][k]==B[i][j][k]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
