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
	int max;
	i=0;
	j=0;
	/*@
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> \valid(&A[k][l]);
	loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> A[k][l] == unknown();
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..m-1][0..n-1];
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i <= m;
		loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> \valid(&A[k][l]);
		loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> \integer(A[k][l]) == unknown();
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[0..m-1][0..n-1];
		*/
		while(j < n){
					A[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
        max=A [0][0];
	/*@
	loop invariant i <= n;
	loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> A[k][l] <= max;
	loop invariant \exists integer k; 0 <= k < i ==> \exists integer l; 0 <= l < n && A[k][l] == max;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns max;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant i <= n;
		loop invariant \forall integer l; 0 <= l < j ==> A[i][l] <= max;
		loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < n ==> A[k][l] <= max;
		loop invariant \exists integer l; 0 <= l < j && A[i][l] == max;
		loop invariant \exists integer k, l; 0 <= k < i && 0 <= l < n && A[k][l] == max;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns max;
		loop assigns j;
		loop assigns A[0..n-1][0..n-1];
		*/
		while(j < n){
			if(A[i][j]>max){
                            max=A[i][j];
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
			// @ assert(A[i][j]<=max);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}
