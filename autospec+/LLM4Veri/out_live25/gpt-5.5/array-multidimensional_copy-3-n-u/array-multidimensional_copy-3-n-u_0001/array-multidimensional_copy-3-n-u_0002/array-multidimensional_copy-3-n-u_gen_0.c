#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j,k;
	int m=1000,n=1500,p=1800;
	int A [1000][1500][1800];
	int B [1000][1500][1800];
	i=0;
	j=0;
	k=0;
	while(i < m){
		j=0;
		k=0;
		/*@
		loop invariant 0 <= i < m;
		loop invariant 0 <= j <= n;
		loop invariant 0 <= k <= p;
		loop invariant \forall integer r, t; 0 <= r < j && 0 <= t < p ==> INT_MIN <= B[i][r][t] < INT_MAX;
		loop assigns j;
		loop assigns k;
		loop assigns B[i][0..n-1][0..p-1];
		loop variant n - j;
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant p - k;
			loop invariant k <= p;
			loop invariant \forall integer t; 0 <= t < k ==> INT_MIN <= B[i][j][t] < INT_MAX;
			loop invariant 0 <= k;
			loop assigns k;
			loop assigns B[i][j][0..p-1];
			*/
			while(k < p){
					B[i][j][k]=unknown();
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < p){
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
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < p){
					// @ assert(A[i][j][k]==B[i][j][k]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
