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
	loop invariant m == 1000;
	loop invariant n == 1500;
	loop invariant 0 <= i <= m;
	loop invariant 0 <= j <= n;
	loop invariant j == 0 || j == n;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop assigns i, j, A[0..m-1][0..n-1];
	loop variant m - i;
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant n - j;
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
	while(i < n){
		j=0;
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
		while(j < n){
			// @ assert(A[i][j]>=min);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
