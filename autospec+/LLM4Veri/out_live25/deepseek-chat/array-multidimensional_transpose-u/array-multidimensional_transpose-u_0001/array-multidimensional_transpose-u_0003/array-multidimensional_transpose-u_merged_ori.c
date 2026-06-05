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
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == \at(A[p][q], Pre);
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns A[0..n-1][0..n-1];
	*/
	for ( i = 0 ; i < n ; i++ ){
          /*@
          loop invariant j <= n;
          loop invariant i <= n;
          loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == A[p][q]; // trivial, but needed for assigns;
          loop invariant 0 <= j;
          loop invariant 0 <= i;
          loop assigns j;
          loop assigns A[0..n-1][0..n-1];
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
           loop invariant j <= n;
           loop invariant i < n;
           loop invariant \forall integer p; 0 <= p < j ==> C[p][i] == A[i][p];
           loop invariant \forall integer p, q; 0 <= p < n && 0 <= q < i ==> C[p][q] == A[q][p];
           loop invariant 0 <= j;
           loop invariant 0 <= i;
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
