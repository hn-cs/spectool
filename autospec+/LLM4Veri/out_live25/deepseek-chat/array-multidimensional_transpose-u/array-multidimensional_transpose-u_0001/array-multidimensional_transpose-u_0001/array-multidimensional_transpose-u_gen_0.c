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
	for ( i = 0 ; i < n ; i++ ){
          /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= j <= n;
          loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == A[p][q]; // trivial, but needed for assigns
          loop assigns A[0..n-1][0..n-1];
          loop assigns j;
          loop assigns i;
          */
          for ( j = 0 ; j < n ; j++ ){
                A[i][j]= unknown();
          }
    }
	i=0;
	j=0;
	while(i < n){
		  j=0;
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
