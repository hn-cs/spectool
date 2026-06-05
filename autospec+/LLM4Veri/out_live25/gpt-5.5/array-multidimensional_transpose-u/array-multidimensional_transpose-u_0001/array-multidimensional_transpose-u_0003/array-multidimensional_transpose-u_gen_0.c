#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i;
	int k;
	int j;
	int n=1000;
        int m=1800;
	int A[1000][1000];
	int C[1000][1000];
	/*@
	loop invariant n == 1000;
	loop invariant i <= n;
	loop invariant \forall integer r, c; 0 <= r < i && 0 <= c < n ==> INT_MIN <= A[r][c] < INT_MAX;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..n-1][0..n-1];
	*/
	for ( i = 0 ; i < n ; i++ ){
          /*@
          loop invariant j <= n;
          loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= A[i][k] < INT_MAX;
          loop invariant 0 <= j;
          loop assigns j;
          loop assigns A[i][0..n-1];
          */
          for ( j = 0 ; j < n ; j++ ){
                A[i][j]= unknown();
          }
    }
	i=0;
	j=0;
	while(i < n){
		  j=0;
           /*@
           loop invariant n == 1000;
           loop invariant 0 <= i < n;
           loop invariant 0 <= j <= n;
           loop invariant \forall integer k; 0 <= k < j ==> C[k][i] == A[i][k];
           loop assigns j;
           loop assigns C[0..n-1][i];
           */
           while(j < n){
                C[j][i] = A[i][j];
		  		j=j+1;
          }
	i=i+1;
    }
	for ( i = 0 ; i < n ; i++ ){
          for ( j = 0 ; j < n ; j++ ){
                // @ assert(C[j][i] == A[i][j]);
          }
    }
return 0;
}
