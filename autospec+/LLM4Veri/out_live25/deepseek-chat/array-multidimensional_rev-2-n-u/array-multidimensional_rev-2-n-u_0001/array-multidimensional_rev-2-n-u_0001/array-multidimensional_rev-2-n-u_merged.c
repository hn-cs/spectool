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
	while(i < m){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i <= m;
		loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> \valid(&B[p][q]);
		loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> (B[p][q] == unknown());
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns B[0..m-1][0..n-1];
		*/
		while(j < n){
					B[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < m){
		j=0;
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
		while(j < n){
                            // @ assert(A[i][j]==B[m-i-1][n-j-1]);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
