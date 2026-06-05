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
	/*@
	loop invariant m == 1000 && n == 1500 && p == 1800;
	loop invariant k <= p;
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer r, s, t; 0 <= r < i && 0 <= s < n && 0 <= t < p ==> INT_MIN <= B[r][s][t] < INT_MAX;
	loop invariant 0 <= k;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns B[0..m-1][0..n-1][0..p-1];
	*/
	while(i < m){
		j=0;
		k=0;
		/*@
		loop invariant k <= p;
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer r, t; 0 <= r < j && 0 <= t < p ==> INT_MIN <= B[i][r][t] < INT_MAX;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns k;
		loop assigns j;
		loop assigns B[i][0..n-1][0..p-1];
		*/
		while(j < n){
			k=0;
			/*@
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
			/*@
			loop invariant p - k;
			loop invariant k <= p;
			loop invariant j < n;
			loop invariant i < m;
			loop invariant \forall integer t; 0 <= t < k ==> A[i][j][t] == B[i][j][t];
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
